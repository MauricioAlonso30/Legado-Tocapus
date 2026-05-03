#include "Nivel1.h"
#include "Recursos.h"
#include "Escenarios_nivel1.h"
#include "TocapuLinaje.h"
#include "TocapuTerritorio.h"
#include "TocapuJerarquia.h"
#include <conio.h>
#include <vector>

Nivel1::Nivel1() : Nivel() {
    this->jugador = nullptr;
}

Nivel1::Nivel1(int numero, string titulo, bool completado, Jugador* jugador)
    : Nivel(numero, titulo, completado) {
    this->jugador = jugador;
}

// ================================================================
// Helpers internos del Nivel 1 (no se exponen al header)
// ================================================================

// Devuelve 0=Linaje, 1=Territorio, 2=Jerarquia segun el tocapu
static int categoriaIndice(Tocapu* t) {
    string c = t->obtenerCategoria();
    if (c.find("Linaje") == 0) return 0;
    if (c.find("Territorio") == 0) return 1;
    return 2;
}

// ASCII art generico por categoria
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

// Dibuja el tocapu actual en la caja de la izquierda
static void dibujarTocapuActual(Tocapu* t) {
    int cat = categoriaIndice(t);
    vector<string> art = asciiPorCategoria(cat);

    int xBase = 23;   // 1 pixel mas a la izquierda
    int yBase = 22;

    setLetraColor(15);
    for (size_t i = 0; i < art.size(); i++) {
        cursorPosition(xBase, yBase + (int)i);
        cout << art[i];
    }
}

// Dibuja las 3 opciones de respuesta con cursor de seleccion
static void dibujarOpciones(int seleccion) {
    string opciones[3] = { "LINAJE", "TERRITORIO", "JERARQUIA" };
    string descripciones[3] = {
        "Representa a una familia o descendencia.",
        "Representa un lugar o region.            ",
        "Representa un rango o posicion.          "
    };
    int yBase[3] = { 19, 27, 35 };  // textos mas abajo, centrados en cada caja
    int xCursor = 56;               // 4 pixeles mas a la izquierda
    int xLabel = 70;

    for (int i = 0; i < 3; i++) {
        // Limpiar zona del cursor (4 filas x 7 chars)
        for (int dy = -2; dy <= 1; dy++) {
            cursorPosition(xCursor, yBase[i] + dy);
            cout << "       ";
        }

        if (i == seleccion) {
            // Cursor octagonal de 4 lineas con punta a la derecha
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

// Dibuja el codice (derecha) con los tocapus acertados
static void dibujarCodiceJuego(vector<Tocapu*>& acertados) {
    int xBase = 128;       // mas a la izquierda, dentro del grid
    int yBase = 15;        // 1 pixel abajo del anterior
    int colsPorFila = 3;
    int anchoCelda = 13;   // mas separacion horizontal (col 2 y 3 mas a la derecha)
    int altoCelda = 9;     // mas separacion vertical (fila 2 y 3 mas abajo)
    // (sin clears: la matriz ya viene fresca y los icons se dibujan encima)

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

// Caja inferior con nombre + significado del tocapu actual (panel negro de abajo)
static void dibujarDescripcion(Tocapu* t) {
    int xBase = 15;
    int yBase = 43;     // 1 pixel mas arriba

    cursorPosition(xBase, yBase);
    setLetraColor(14);
    cout << t->getNombre();

    cursorPosition(xBase, yBase + 1);
    setLetraColor(15);
    cout << t->getSignificado();
}

// Indicador de intentos
static void dibujarIntentos(int n) {
    int xBase = 130;
    int yBase = 39;     // 6 pixeles mas abajo

    cursorPosition(xBase, yBase);
    setLetraColor(n > 1 ? 14 : 12);
    cout << "INTENTOS: " << n << "/3";
}

// Pantalla provisional WIN
static void mostrarWin() {
    system("cls");
    setLetraColor(10);
    cursorPosition(80, 24);
    cout << "WIN";
    cursorPosition(60, 26);
    setLetraColor(15);
    cout << "Presiona una tecla para continuar...";
    _getch();
}

// Pantalla provisional LOST
static void mostrarLost() {
    system("cls");
    setLetraColor(12);
    cursorPosition(80, 24);
    cout << "LOST";
    cursorPosition(60, 26);
    setLetraColor(15);
    cout << "Presiona una tecla para continuar...";
    _getch();
}

// ================================================================
// Flujo principal
// ================================================================

void Nivel1::iniciar() {
    Codice* codice = jugador->getCodice();

    // (a) Cargar 15 tocapus en el codice del jugador
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

    // (b) Slideshow
    system("cls"); pintarMatriz(matriz_nivel1);          _getch();
    system("cls"); pintarMatriz(matriz_mensaje_nivel1);  _getch();
    system("cls"); pintarMatriz(matriz_escena1_nivel1);  _getch();
    system("cls"); pintarMatriz(matriz_escena2_nivel1);  _getch();
    system("cls"); pintarMatriz(matriz_escena3_nivel1);  _getch();

    // (c) Minijuego
    // Pool de tocapus disponibles (ids 1..15)
    vector<Tocapu*> pool;
    for (int id = 1; id <= 15; id++) {
        Tocapu* t = codice->buscarTocapu(id);
        if (t != nullptr) pool.push_back(t);
    }

    // Mezcla Fisher-Yates con la funcion aleatorio() existente
    for (int i = (int)pool.size() - 1; i > 0; i--) {
        int j = aleatorio(0, i);
        Tocapu* tmp = pool[i];
        pool[i] = pool[j];
        pool[j] = tmp;
    }

    // Tomar primeros 5
    if (pool.size() > 5) pool.resize(5);

    int intentos = 3;
    vector<Tocapu*> acertados;

    for (size_t k = 0; k < pool.size(); k++) {
        Tocapu* tocapu = pool[k];

        // Render base de la pregunta (una sola vez)
        system("cls");
        pintarMatriz(matriz_escena_juego_nivel1);
        dibujarTocapuActual(tocapu);
        dibujarCodiceJuego(acertados);
        dibujarDescripcion(tocapu);
        dibujarIntentos(intentos);

        int seleccion = 0;
        bool confirmado = false;

        // Loop de input
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

    // Termino los 5 con intentos > 0 -> WIN
    mostrarWin();
    setCompletado(true);
}

bool Nivel1::validarRespuesta() {
    return false;
}
