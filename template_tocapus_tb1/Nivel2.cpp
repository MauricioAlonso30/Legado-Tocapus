#include "Nivel2.h"
#include "Recursos.h"
#include "Escenarios.h"
#include "Escenarios_nivel2.h"
#include "TocapuLinaje.h"
#include "TocapuTerritorio.h"
#include "TocapuJerarquia.h"
#include "BloqueNarrativo.h"



Nivel2::Nivel2() : Nivel() {
    this->jugador = nullptr;
    this->unku = nullptr;
}

Nivel2::Nivel2(int numero, string titulo, bool completado, Jugador* jugador)
    : Nivel(numero, titulo, completado) {
    this->jugador = jugador;
    this->unku = nullptr;
}



struct SapaIncaCfg {
    string nombre;
    int tocapuIds[3];
};

static const int NUM_SAPAS = 6;
static const SapaIncaCfg SAPAS[NUM_SAPAS] = {
    { "PACHACUTEC",     {  1,  6, 11 } },
    { "TUPAC YUPANQUI", {  2,  7, 12 } },
    { "HUAYNA CAPAC",   {  3,  8, 13 } },
    { "HUASCAR",        {  4,  9, 14 } },
    { "ATAHUALPA",      {  5, 10, 15 } },
    { "MANCO INCA",     {  1,  7, 13 } }
};

static const int ACIERTOS_REQUERIDOS = 3;
static const int INTENTOS_MAXIMOS = 10;
static const int INTENTOS_SAPA = 3;


static int categoriaIndiceN2(Tocapu* t) {
    string c = t->obtenerCategoria();
    if (c.find("Linaje") == 0) return 0;
    if (c.find("Territorio") == 0) return 1;
    return 2;
}

static int colorPorCategoria(int cat) {
    if (cat == 0) return 11;
    if (cat == 1) return 10;
    return 12;
}


static const int codiceX[3] = { 125, 138, 151 };
static const int codiceY[2] = { 6, 12 };
static const int codiceW = 12;
static const int codiceH = 5;


static const int unkuX[3] = { 62, 74, 86 };
static const int unkuY[3] = { 10, 17, 24 };
static const int unkuW = 11;
static const int unkuH = 6;


static const int activoX = 122;
static const int activoY = 26;
static const int activoW = 14;
static const int activoH = 5;


static const int descX = 138;
static const int descY = 26;
static const int descW = 28;
static const int descH = 5;


static const int slotsY = 33;
static int slotPosX(int idx) {
    return 124 + idx * 5;
}


static const int sapaY = 36;
static const int sapaH = 8;
static const int sapaW = 26;
static int sapaPosX(int idx) {
    return 4 + idx * 27;
}


static bool contieneId(vector<int>& v, int id) {
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] == id) return true;
    }
    return false;
}

static bool formaOtraCombinacion(vector<int>& ids, int sapaCorrecto) {
    for (int i = 0; i < NUM_SAPAS; i++) {
        if (i == sapaCorrecto) continue;
        const SapaIncaCfg& s = SAPAS[i];
        bool t0 = contieneId(ids, s.tocapuIds[0]);
        bool t1 = contieneId(ids, s.tocapuIds[1]);
        bool t2 = contieneId(ids, s.tocapuIds[2]);
        if (t0 && t1 && t2) return true;
    }
    return false;
}

static vector<int> generarIdsUnku(int sapaCorrectoIdx) {
    vector<int> ids;
    const SapaIncaCfg& sapa = SAPAS[sapaCorrectoIdx];
    ids.push_back(sapa.tocapuIds[0]);
    ids.push_back(sapa.tocapuIds[1]);
    ids.push_back(sapa.tocapuIds[2]);

    vector<int> candidatos;
    for (int id = 1; id <= 15; id++) {
        if (!contieneId(ids, id)) candidatos.push_back(id);
    }
    for (int i = (int)candidatos.size() - 1; i > 0; i--) {
        int j = aleatorio(0, i);
        int tmp = candidatos[i]; candidatos[i] = candidatos[j]; candidatos[j] = tmp;
    }

    int agregados = 0;
    for (size_t k = 0; k < candidatos.size(); k++) {
        if (agregados >= 4) break;
        int id = candidatos[k];
        ids.push_back(id);
        if (formaOtraCombinacion(ids, sapaCorrectoIdx)) {
            ids.pop_back();
        }
        else {
            agregados++;
        }
    }

    while ((int)ids.size() < 7) {
        ids.push_back(sapa.tocapuIds[aleatorio(0, 2)]);
    }

    for (int rep = 0; rep < 2; rep++) {
        int idx = aleatorio(0, (int)ids.size() - 1);
        ids.push_back(ids[idx]);
    }

    while ((int)ids.size() > 9) ids.pop_back();

    for (int i = (int)ids.size() - 1; i > 0; i--) {
        int j = aleatorio(0, i);
        int tmp = ids[i]; ids[i] = ids[j]; ids[j] = tmp;
    }
    return ids;
}


static void limpiarRectColor(int xBase, int yBase, int w, int h, int color) {
    setLetraColor(color);
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cursorPosition(xBase + x, yBase + y);
            cout << (char)219;
        }
    }
}

static vector<string> asciiArtGrande(int cat) {
    if (cat == 0) {
        return {
            " _______ ",
            "|  /\\   |",
            "| /  \\  |",
            "| \\--/  |",
            "|  \\/   |",
            "|_______|"
        };
    }
    if (cat == 1) {
        return {
            " _______ ",
            "| #   # |",
            "|   #   |",
            "| #   # |",
            "|       |",
            "|_______|"
        };
    }
    return {
        " _______ ",
        "|   *   |",
        "| * * * |",
        "|   *   |",
        "|       |",
        "|_______|"
    };
}

static vector<string> asciiArtCompacto(int cat) {
    if (cat == 0) {
        return {
            " /\\ ",
            "/  \\",
            "\\  /"
        };
    }
    if (cat == 1) {
        return {
            "# #",
            " # ",
            "# #"
        };
    }
    return {
        " * ",
        "***",
        " * "
    };
}

static void dibujarTocapuEnCelda(Tocapu* t, int xBase, int yBase, int w, int h, int colorFondo) {
    limpiarRectColor(xBase, yBase, w, h, colorFondo);
    if (t == nullptr) return;

    int cat = categoriaIndiceN2(t);
    int colorTexto = colorPorCategoria(cat);

    setFondoColor(colorFondo);
    setLetraColor(colorTexto);

    if (h >= 6 && w >= 9) {
        string sym = t->getSimboloASCII();
        string nombre = t->getNombre();

        cursorPosition(xBase + (w - (int)sym.size()) / 2, yBase + 1);
        cout << sym;

        size_t spaceIdx = nombre.find(' ');
        if (spaceIdx != string::npos) {
            string part1 = nombre.substr(0, spaceIdx);
            string part2 = nombre.substr(spaceIdx + 1);
            if ((int)part1.size() > w) part1 = part1.substr(0, w);
            if ((int)part2.size() > w) part2 = part2.substr(0, w);
            cursorPosition(xBase + (w - (int)part1.size()) / 2, yBase + 3);
            cout << part1;
            cursorPosition(xBase + (w - (int)part2.size()) / 2, yBase + 4);
            cout << part2;
        }
        else {
            if ((int)nombre.size() > w) nombre = nombre.substr(0, w);
            cursorPosition(xBase + (w - (int)nombre.size()) / 2, yBase + 3);
            cout << nombre;
        }
    }
    else {
        vector<string> art = asciiArtCompacto(cat);
        int artW = (int)art[0].size();
        int artH = (int)art.size();
        int artX = xBase + (w - artW) / 2;
        int artY = yBase;

        for (int i = 0; i < artH; i++) {
            cursorPosition(artX, artY + i);
            cout << art[i];
        }

        string nombre = t->getNombre();
        if ((int)nombre.size() > w) nombre = nombre.substr(0, w);
        int nomX = xBase + (w - (int)nombre.size()) / 2;
        int nomY = yBase + h - 1;
        cursorPosition(nomX, nomY);
        cout << nombre;
    }

    setFondoColor(0);
}


static void dibujarBordeCodice(int slot, int color) {
    int r = slot / 3;
    int c = slot % 3;
    int xBase = codiceX[c];
    int yBase = codiceY[r];

    setLetraColor(color);
    for (int x = -1; x <= codiceW; x++) {
        cursorPosition(xBase + x, yBase - 1);
        cout << (char)219;
        cursorPosition(xBase + x, yBase + codiceH);
        cout << (char)219;
    }
    for (int y = 0; y < codiceH; y++) {
        cursorPosition(xBase - 1, yBase + y);
        cout << (char)219;
        cursorPosition(xBase + codiceW, yBase + y);
        cout << (char)219;
    }
}


static void dibujarUnkuTodo(vector<Tocapu*>& tocapus) {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            int idx = r * 3 + c;
            dibujarTocapuEnCelda(tocapus[idx], unkuX[c], unkuY[r], unkuW, unkuH, 15);
        }
    }
}

static void dibujarCodicePagina(vector<Tocapu*>& aprendidos, int pagina) {
    for (int slot = 0; slot < 6; slot++) {
        int idx = pagina * 6 + slot;
        int r = slot / 3;
        int c = slot % 3;
        Tocapu* t = (idx < (int)aprendidos.size()) ? aprendidos[idx] : nullptr;
        dibujarTocapuEnCelda(t, codiceX[c], codiceY[r], codiceW, codiceH, 14);
    }
    for (int slot = 0; slot < 6; slot++) {
        dibujarBordeCodice(slot, 6);
    }
}

static Tocapu* tocapuSeleccionadoActual(vector<Tocapu*>& aprendidos, int paginaActual, int selSlot) {
    int idx = paginaActual * 6 + selSlot;
    if (idx >= 0 && idx < (int)aprendidos.size()) return aprendidos[idx];
    return nullptr;
}


static void dibujarTocapuActivo(Tocapu* t) {
    dibujarTocapuEnCelda(t, activoX, activoY, activoW, activoH, 14);
}


static void dibujarDescripcionSeleccion(Tocapu* t) {
    limpiarRectColor(descX, descY, descW, descH, 14);
    if (t == nullptr) return;

    setFondoColor(14);
    setLetraColor(0);

    string nombre = t->getNombre();
    string sig = t->getSignificado();
    string cat = t->obtenerCategoria();

    if ((int)nombre.size() > descW) nombre = nombre.substr(0, descW);
    if ((int)sig.size() > descW)    sig = sig.substr(0, descW);
    if ((int)cat.size() > descW)    cat = cat.substr(0, descW);

    cursorPosition(descX, descY + 1);
    cout << nombre;
    cursorPosition(descX, descY + 2);
    cout << sig;
    cursorPosition(descX, descY + 3);
    cout << cat;

    setFondoColor(0);
}


static void dibujarSlotResultado(int idx, bool acierto) {
    int x = slotPosX(idx);
    int y = slotsY;

    setFondoColor(14);
    if (acierto) {
        setLetraColor(10);
        cursorPosition(x, y);
        cout << "V";
    }
    else {
        setLetraColor(12);
        cursorPosition(x, y);
        cout << "X";
    }
    setFondoColor(0);
}


static void dibujarSapaInca(int idx, const SapaIncaCfg& s, Codice* codice, bool seleccionado) {
    int xBase = sapaPosX(idx);
    int yBase = sapaY;

    limpiarRectColor(xBase, yBase, sapaW, sapaH, 0);

    setFondoColor(0);
    setLetraColor(seleccionado ? 14 : 7);
    string nombre = s.nombre;
    if ((int)nombre.size() > sapaW) nombre = nombre.substr(0, sapaW);
    int nx = xBase + (sapaW - (int)nombre.size()) / 2;
    cursorPosition(nx, yBase + 1);
    cout << nombre;

    setLetraColor(7);
    cursorPosition(xBase + 8, yBase + 3);
    cout << "Tocapus:";

    for (int i = 0; i < 3; i++) {
        Tocapu* t = codice->buscarTocapu(s.tocapuIds[i]);
        if (t == nullptr) continue;
        int cat = categoriaIndiceN2(t);
        int color = colorPorCategoria(cat);
        setLetraColor(color);
        int tx = xBase + 2 + i * 8;
        int ty = yBase + 5;
        cursorPosition(tx, ty);
        cout << t->getSimboloASCII();
        string n = t->getNombre();
        if ((int)n.size() > 7) n = n.substr(0, 7);
        cursorPosition(tx - 1, ty + 1);
        cout << n;
    }

    if (seleccionado) {
        setLetraColor(12);
        for (int x = -1; x <= sapaW; x++) {
            cursorPosition(xBase + x, yBase - 1);
            cout << (char)219;
            cursorPosition(xBase + x, yBase + sapaH);
            cout << (char)219;
        }
        for (int y = 0; y < sapaH; y++) {
            cursorPosition(xBase - 1, yBase + y);
            cout << (char)219;
            cursorPosition(xBase + sapaW, yBase + y);
            cout << (char)219;
        }
    }
    else {
        setLetraColor(0);
        for (int x = -1; x <= sapaW; x++) {
            cursorPosition(xBase + x, yBase - 1);
            cout << (char)219;
            cursorPosition(xBase + x, yBase + sapaH);
            cout << (char)219;
        }
        for (int y = 0; y < sapaH; y++) {
            cursorPosition(xBase - 1, yBase + y);
            cout << (char)219;
            cursorPosition(xBase + sapaW, yBase + y);
            cout << (char)219;
        }
    }
}


static void dibujarPanelIntentosSapa(int restantes) {
    setFondoColor(0);
    setLetraColor(14);
    cursorPosition(70, 45);
    cout << "INTENTOS RESTANTES: " << restantes << "/" << INTENTOS_SAPA;
}


void Nivel2::iniciar() {

    BloqueNarrativo mensajeEscenaNivel2(0, "Escena mensaje nivel 2", 0, { "\xA8Interpretar informaci\xA2n es lo mismo que conocer la verdad?" });

    BloqueNarrativo textoEscena1Nivel2(1, "Escena 1 nivel 2", 0,
        {
        R"(Ha llegado el d�a de la muerte del maestro. Qhipu Ayar ya ha completado su formaci�n inicial y es reconocido como alguien capaz de interpretar los
        tocapus, por lo que su maestro, orgulloso, puede partir en paz. )"
        });
    BloqueNarrativo textoEscena2Nivel2(2, "Escena 2 nivel 2", 0,
        {
        R"(D�as despu�s de su fallecimiento llegan mensajeros del imperio con una misi�n urgente. En una huaca saqueada se ha encontrado un unku real, pero su
        origen es desconocido. Ante esta situaci�n, Qhipu Ayar es convocado para reconocerlo y determinar su procedencia, poniendo a prueba todo lo que ha aprendido.)"
        });

    BloqueNarrativo textoEscena3Nivel2(3, "Escena 3 nivel 2", 0,
        {
        "Observa el tocapu destacado bajo tu codice y revisa los tocapus de tu codice.",
        "Usa las flechas o las teclas A y D para desplazarte por los cuadros del codice.",
        "En la columna derecha, presiona la flecha derecha o D para ver los siguientes tocapus.",
        "Presiona ENTER cuando el cuadro seleccionado coincida con el tocapu destacado.",
        "Necesitas 3 aciertos para descifrar el unku."
        });
    BloqueNarrativo textoEscena4Nivel2(4, "Escena 4 nivel 2", 0,
        {
        R"(Qhipu Ayar logra interpretar los s�mbolos correctamente y presenta el unku al Sapa Inca al que pertenece, demostrando as� que el conocimiento que aprendi�
        tiene un verdadero valor.)"
        });

    system("cls"); pintarMatriz(matriz_nivel2); _getch();
    system("cls"); pintarMatriz(matriz_mensaje_nivel2); mensajeEscenaNivel2.mostrarBloque(50, 24, 90); _getch();
    system("cls"); pintarMatriz(matriz_escena1_nivel2); textoEscena1Nivel2.mostrarBloque(128, 15, 39); _getch();
    system("cls"); pintarMatriz(matriz_escena2_nivel2);  textoEscena2Nivel2.mostrarBloque(128, 15, 39), _getch();
    system("cls"); pintarMatriz(matriz_escena3_nivel2);  textoEscena3Nivel2.mostrarBloque(40, 19, 90);  _getch();



    Codice* codice = jugador->getCodice();

    int sapaCorrectoIdx = aleatorio(0, NUM_SAPAS - 1);
    vector<int> idsUnku = generarIdsUnku(sapaCorrectoIdx);

    vector<Tocapu*> tocapusUnku;
    for (size_t i = 0; i < idsUnku.size(); i++) {
        tocapusUnku.push_back(codice->buscarTocapu(idsUnku[i]));
    }
    while (tocapusUnku.size() < 9) tocapusUnku.push_back(nullptr);

    vector<Tocapu*> aprendidos;
    for (int id = 1; id <= 15; id++) {
        Tocapu* t = codice->buscarTocapu(id);
        if (t != nullptr) aprendidos.push_back(t);
    }

    system("cls");
    pintarMatriz(matriz_escena_juego_nivel2);
    dibujarUnkuTodo(tocapusUnku);

    int paginaActual = 0;
    int selSlot = 0;
    dibujarCodicePagina(aprendidos, paginaActual);
    dibujarBordeCodice(selSlot, 12);

    Tocapu* activo = tocapusUnku[aleatorio(0, 8)];
    dibujarTocapuActivo(activo);
    dibujarDescripcionSeleccion(tocapuSeleccionadoActual(aprendidos, paginaActual, selSlot));

    int verdes = 0;
    int intentos = 0;

    while (verdes < ACIERTOS_REQUERIDOS && intentos < INTENTOS_MAXIMOS) {
        int tecla = _getch();

        int sub = -1;
        if (tecla == 0 || tecla == 224) {
            sub = _getch();
        }
        else if (tecla == 'a' || tecla == 'A') sub = 75;
        else if (tecla == 'd' || tecla == 'D') sub = 77;
        else if (tecla == 'w' || tecla == 'W') sub = 72;
        else if (tecla == 's' || tecla == 'S') sub = 80;

        if (sub == 75 || sub == 77 || sub == 72 || sub == 80) {
            int prevSlot = selSlot;
            int prevPagina = paginaActual;

            if (sub == 75) {
                int col = selSlot % 3;
                if (col == 0) {
                    if (paginaActual > 0) {
                        paginaActual--;
                        selSlot += 2;
                    }
                }
                else {
                    selSlot--;
                }
            }
            else if (sub == 77) {
                int col = selSlot % 3;
                if (col == 2) {
                    int totalPaginas = ((int)aprendidos.size() + 5) / 6;
                    if (totalPaginas < 1) totalPaginas = 1;
                    if (paginaActual + 1 < totalPaginas) {
                        paginaActual++;
                        selSlot -= 2;
                    }
                }
                else {
                    selSlot++;
                }
            }
            else if (sub == 72 || sub == 80) {
                selSlot = (selSlot + 3) % 6;
            }

            if (prevPagina != paginaActual) {
                dibujarCodicePagina(aprendidos, paginaActual);
                dibujarBordeCodice(selSlot, 12);
                dibujarDescripcionSeleccion(tocapuSeleccionadoActual(aprendidos, paginaActual, selSlot));
            }
            else if (prevSlot != selSlot) {
                dibujarBordeCodice(prevSlot, 6);
                dibujarBordeCodice(selSlot, 12);
                dibujarDescripcionSeleccion(tocapuSeleccionadoActual(aprendidos, paginaActual, selSlot));
            }
        }
        else if (tecla == 'n' || tecla == 'N') {
            if (activo == nullptr) continue;
            bool yaAprendido = false;
            for (size_t i = 0; i < aprendidos.size(); i++) {
                if (aprendidos[i] != nullptr && aprendidos[i]->getId() == activo->getId()) {
                    yaAprendido = true;
                    break;
                }
            }
            bool acierto;
            if (!yaAprendido) {
                aprendidos.push_back(activo);
                jugador->agregarAprendido(activo->getId());
                int newIdx = (int)aprendidos.size() - 1;
                paginaActual = newIdx / 6;
                selSlot = newIdx % 6;
                dibujarCodicePagina(aprendidos, paginaActual);
                dibujarBordeCodice(selSlot, 12);
                dibujarDescripcionSeleccion(activo);
                acierto = true;
            }
            else {
                acierto = false;
            }
            dibujarSlotResultado(intentos, acierto);
            intentos++;
            if (acierto) verdes++;
            if (verdes < ACIERTOS_REQUERIDOS && intentos < INTENTOS_MAXIMOS) {
                activo = tocapusUnku[aleatorio(0, 8)];
                dibujarTocapuActivo(activo);
            }
        }
        else if (tecla == 13) {
            if (activo == nullptr) continue;
            Tocapu* sel = tocapuSeleccionadoActual(aprendidos, paginaActual, selSlot);
            bool acierto = (sel != nullptr && sel->getId() == activo->getId());
            dibujarSlotResultado(intentos, acierto);
            intentos++;
            if (acierto) verdes++;
            if (verdes < ACIERTOS_REQUERIDOS && intentos < INTENTOS_MAXIMOS) {
                activo = tocapusUnku[aleatorio(0, 8)];
                dibujarTocapuActivo(activo);
            }
        }
    }

    if (verdes < ACIERTOS_REQUERIDOS) {
        system("cls"); pintarMatriz(matriz_lost); _getch();
        setCompletado(false);
        return;
    }

    system("cls"); pintarMatriz(matriz_escena4_nivel2);  textoEscena4Nivel2.mostrarBloque(128, 15, 39);  _getch();
    setCompletado(true);
}

void Nivel2::inspeccionarUnku() {
}

bool Nivel2::deducirSapaInca() {
    return false;
}
