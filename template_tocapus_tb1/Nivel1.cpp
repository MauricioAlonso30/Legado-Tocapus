#include "Nivel1.h"
#include "Recursos.h"
#include "Escenarios.h"
#include "Escenarios_nivel1.h"
#include "TocapuLinaje.h"
#include "TocapuTerritorio.h"
#include "TocapuJerarquia.h"
#include "BloqueNarrativo.h"




Nivel1::Nivel1() : Nivel() {
    this->jugador = nullptr;
}

Nivel1::Nivel1(int numero, string titulo, bool completado, Jugador* jugador)
    : Nivel(numero, titulo, completado) {
    this->jugador = jugador;
}

static int categoriaIndice(Tocapu* t) {
    string c = t->obtenerCategoria();
    if (c.find("Linaje") == 0) return 0;
    if (c.find("Territorio") == 0) return 1;
    return 2;
}

static vector<string> asciiPorCategoria(int cat) {
    if (cat == 0) {
        return {
            " _______ ",
            "|  /\\   |",
            "| /  \\  |",
            "| \\--/  |",
            "|  \\/   |",
            "|_______|"
        };
    } else if (cat == 1) {
        return {
            " _______ ",
            "| #   # |",
            "|   #   |",
            "| #   # |",
            "|       |",
            "|_______|"
        };
    } else {
        return {
            " _______ ",
            "|   *   |",
            "| * * * |",
            "|   *   |",
            "|       |",
            "|_______|"
        };
    }
}

static void dibujarTocapuActual(Tocapu* t) {
    int cat = categoriaIndice(t);
    vector<string> art = asciiPorCategoria(cat);

    int xBase = 23;
    int yBase = 22;

    setLetraColor(15);
    for (size_t i = 0; i < art.size(); i++) {
        cursorPosition(xBase, yBase + (int)i);
        cout << art[i];
    }
}

static void dibujarOpciones(int seleccion) {
    string opciones[3] = { "LINAJE", "TERRITORIO", "JERARQUIA" };
    string descripciones[3] = {
        "Representa a una familia o descendencia.",
        "Representa un lugar o region.            ",
        "Representa un rango o posicion.          "
    };
    int yBase[3] = { 19, 27, 35 };
    int xCursor = 56;
    int xLabel = 70;

    for (int i = 0; i < 3; i++) {
        for (int dy = -2; dy <= 1; dy++) {
            cursorPosition(xCursor, yBase[i] + dy);
            cout << "       ";
        }

        if (i == seleccion) {
            setLetraColor(14);
            cursorPosition(xCursor, yBase[i] - 2);
            cout << "  __  ";
            cursorPosition(xCursor, yBase[i] - 1);
            cout << " /  \\ ";
            cursorPosition(xCursor, yBase[i]);
            cout << "|    |";
            cursorPosition(xCursor + 6, yBase[i]);
            cout << ">";
            cursorPosition(xCursor, yBase[i] + 1);
            cout << " \\__/ ";
        }

        cursorPosition(xLabel, yBase[i] - 1);
        setLetraColor(i == seleccion ? 14 : 15);
        cout << opciones[i];

        cursorPosition(xLabel, yBase[i] + 1);
        setLetraColor(7);
        cout << descripciones[i];
    }
}

static void dibujarCodiceJuego(vector<Tocapu*>& acertados) {
    int xBase = 128;
    int yBase = 15;
    int colsPorFila = 3;
    int anchoCelda = 13;
    int altoCelda = 9;

    for (size_t i = 0; i < acertados.size(); i++) {
        int fila = (int)i / colsPorFila;
        int col = (int)i % colsPorFila;
        int x = xBase + col * anchoCelda;
        int y = yBase + fila * altoCelda;

        int cat = categoriaIndice(acertados[i]);
        setLetraColor(cat == 0 ? 11 : (cat == 1 ? 10 : 14));

        if (cat == 0) {
            cursorPosition(x, y);     cout << " /\\ ";
            cursorPosition(x, y + 1); cout << "<L >";
            cursorPosition(x, y + 2); cout << " \\/ ";
        }
        else if (cat == 1) {
            cursorPosition(x, y);     cout << "#   #";
            cursorPosition(x, y + 1); cout << " #T# ";
            cursorPosition(x, y + 2); cout << "#   #";
        }
        else {
            cursorPosition(x, y);     cout << "  *  ";
            cursorPosition(x, y + 1); cout << " *J* ";
            cursorPosition(x, y + 2); cout << "  *  ";
        }
    }
}

static void dibujarDescripcion(Tocapu* t) {
    int xBase = 15;
    int yBase = 43;

    cursorPosition(xBase, yBase);
    setLetraColor(14);
    cout << t->getNombre();

    cursorPosition(xBase, yBase + 1);
    setLetraColor(15);
    cout << t->getSignificado();
}

static void dibujarIntentos(int n) {
    int xBase = 130;
    int yBase = 39;

    cursorPosition(xBase, yBase);
    setLetraColor(n > 1 ? 14 : 12);
    cout << "INTENTOS: " << n << "/3";
}

static void mostrarWin() {
    system("cls"); pintarMatriz(matriz_win); _getch();
}

static void mostrarLost() {
    system("cls"); pintarMatriz(matriz_lost); _getch();
}

void Nivel1::iniciar() {
    Codice* codice = jugador->getCodice();

    codice->agregarTocapu(new TocapuLinaje(1, "Linaje Hanan", "[H]", "Casa real alta",            "Hanan Cuzco"));
    codice->agregarTocapu(new TocapuLinaje(2, "Linaje Hurin", "[h]", "Casa real baja",            "Hurin Cuzco"));
    codice->agregarTocapu(new TocapuLinaje(3, "Panaca Inaca", "[I]", "Descendencia Pachacutec",   "Inaca Panaca"));
    codice->agregarTocapu(new TocapuLinaje(4, "Panaca Capac", "[C]", "Descendencia Capac Yupanqui","Capac Ayllu"));
    codice->agregarTocapu(new TocapuLinaje(5, "Panaca Sucsu", "[S]", "Descendencia Viracocha",    "Sucsu Panaca"));

    codice->agregarTocapu(new TocapuTerritorio(6,  "Chinchaysuyu", "[N]", "Region norte",        "Chinchaysuyu"));
    codice->agregarTocapu(new TocapuTerritorio(7,  "Antisuyu",     "[E]", "Region este",         "Antisuyu"));
    codice->agregarTocapu(new TocapuTerritorio(8,  "Contisuyu",    "[O]", "Region oeste",        "Contisuyu"));
    codice->agregarTocapu(new TocapuTerritorio(9,  "Collasuyu",    "[U]", "Region sur",          "Collasuyu"));
    codice->agregarTocapu(new TocapuTerritorio(10, "Cusco",        "[X]", "Centro del imperio",  "Cusco"));

    codice->agregarTocapu(new TocapuJerarquia(11, "Sapa Inca",    "[*]", "Maximo gobernante",   "Sapa Inca"));
    codice->agregarTocapu(new TocapuJerarquia(12, "Coya",         "[+]", "Esposa principal",    "Coya"));
    codice->agregarTocapu(new TocapuJerarquia(13, "Apu",          "[A]", "Gobernador de suyu",  "Apu"));
    codice->agregarTocapu(new TocapuJerarquia(14, "Curaca",       "[c]", "Jefe local",          "Curaca"));
    codice->agregarTocapu(new TocapuJerarquia(15, "Cumbicamayoc", "[t]", "Maestro tejedor",     "Cumbicamayoc"));

    BloqueNarrativo mensajeGlobal(0, "Escena Global", 0, { "¿Es posible reconstruir y preservar una cultura ancestral cuando su lenguaje aún no ha sido completamente comprendido?" });

    BloqueNarrativo mensajeEscenaNivel1(1, "Escena 1", 0, { "¿El conocimiento se pierde cuando no se comprende o cuando no se transmite?" });

    BloqueNarrativo textoEscena1(2,"Escena 1",0,
        { 
        R"(En la ciudad del Cusco, durante el apogeo del Imperio Inca, los conocimientos sobre los tocapus son resguardados por los cumbicamayoc, artesanos de élite 
        encargados de tejer no sólo textiles, sino también información cultural. Estos no son simples símbolos, sino un lenguaje visual que representa linajes, 
        territorios y jerarquías.")"
        });
    BloqueNarrativo textoEscena2(3, "Escena 2", 0,
        {
        R"(Qhipu Ayar, es aceptado como aprendiz en el taller de uno de estos artesanos cumbicamayoc. Sin embargo, el tiempo es limitado, el maestro, consciente de su 
        pronta muerte, debe transmitir todo su conocimiento antes de que este fallezca por una rara enfermedad. 
          )"
        });
        
    BloqueNarrativo textoEscena3(4, "Escena 3", 0,
        {
        "Debes observar cada tocapu y seleccionar su significado correcto.",
        "Usa las teclas W y S para desplazarte entre las opciones.",
        "Presiona ENTER para confirmar tu respuesta.",
        "Tienes intentos limitados.",
        "Cada acierto se registrará en tu códice."
        });
    BloqueNarrativo textoEscena4(5, "Escena 4", 0,
        {
        R"( El conocimiento de Qhipu Ayar comienza a tomar forma.
        Los tocapus aprendidos se registran en el códice, marcando el inicio de su aprendizaje 
        )" });


    system("cls"); pintarMatriz(matriz_mensaje_global); mensajeGlobal.mostrarBloque(40, 23, 90); _getch();
    system("cls"); pintarMatriz(matriz_nivel1); _getch();
    system("cls"); pintarMatriz(matriz_mensaje_nivel1); mensajeEscenaNivel1.mostrarBloque(40, 23, 90); _getch();
    system("cls"); pintarMatriz(matriz_escena1_nivel1); textoEscena1.mostrarBloque(147, 15, 22); _getch();
    system("cls"); pintarMatriz(matriz_escena2_nivel1);  textoEscena2.mostrarBloque(120, 15, 47), _getch();
    system("cls"); pintarMatriz(matriz_escena3_nivel1);  textoEscena3.mostrarBloque(40, 20, 90);  _getch();


    vector<Tocapu*> pool;
    for (int id = 1; id <= 15; id++) {
        Tocapu* t = codice->buscarTocapu(id);
        if (t != nullptr) pool.push_back(t);
    }

    for (int i = (int)pool.size() - 1; i > 0; i--) {
        int j = aleatorio(0, i);
        Tocapu* tmp = pool[i];
        pool[i] = pool[j];
        pool[j] = tmp;
    }

    if (pool.size() > 5) pool.resize(5);

    int intentos = 3;
    vector<Tocapu*> acertados;

    for (size_t k = 0; k < pool.size(); k++) {
        Tocapu* tocapu = pool[k];

        system("cls");
        pintarMatriz(matriz_escena_juego_nivel1);
        dibujarTocapuActual(tocapu);
        dibujarCodiceJuego(acertados);
        dibujarDescripcion(tocapu);
        dibujarIntentos(intentos);

        int seleccion = 0;
        bool confirmado = false;

        while (!confirmado) {
            dibujarOpciones(seleccion);

            int tecla = _getch();
            if (tecla == 'w' || tecla == 'W') {
                seleccion = (seleccion - 1 + 3) % 3;
            }
            else if (tecla == 's' || tecla == 'S') {
                seleccion = (seleccion + 1) % 3;
            }
            else if (tecla == 13) {
                confirmado = true;
            }
        }

        bool correcto = (seleccion == categoriaIndice(tocapu));

        if (correcto) {
            acertados.push_back(tocapu);
        }
        else {
            intentos--;
            if (intentos <= 0) {
                mostrarLost();
                setCompletado(false);
                return;
            }
        }
    }
    system("cls"); pintarMatriz(matriz_escena4_nivel1);  textoEscena4.mostrarBloque(147, 15, 22);  _getch();
    mostrarWin();
    setCompletado(true);
}

bool Nivel1::validarRespuesta() {
    return false;
}


