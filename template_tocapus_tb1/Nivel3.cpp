#include "Nivel3.h"
#include "Recursos.h"
#include "Escenarios.h"
#include "BloqueNarrativo.h"
#include "Escenarios_nivel3.h"
#include "TocapuLinaje.h"
#include "TocapuTerritorio.h"
#include "TocapuJerarquia.h"


Nivel3::Nivel3() : Nivel() {
    this->jugador = nullptr;
    this->quero = nullptr;
}

Nivel3::Nivel3(int numero, string titulo, bool completado, Jugador* jugador)
    : Nivel(numero, titulo, completado) {
    this->jugador = jugador;
    this->quero = nullptr;
}

void Nivel3::iniciar() {

    BloqueNarrativo mensajeEscenaNivel3(0, "Escena mensaje nivel 3", 0,
        { "¿Qué ocurre cuando una historia se pierde o se reconstruye de forma incorrecta?" });

    BloqueNarrativo textoEscena1Nivel3(1, "Escena 1 nivel 3", 0,
        {
        R"(Años después, con la llegada de Francisco Pizarro al Perú, el Imperio
        Inca entra en un periodo de caos e inestabilidad que pone en riesgo la preservación de su memoria cultural.)"
        });

    BloqueNarrativo textoEscena2Nivel3(2, "Escena 2 nivel 3", 0,
        {
        R"(En medio de este conflicto, un quipucamayoc, amigo de Qhipu Ayar, le entrega un quero ceremonial dañado; cuyas superficies contienen escenas
        narrativas representadas mediante piezas de tocapus.)"
        });

    BloqueNarrativo textoEscena3Nivel3(3, "Escena 3 nivel 3", 0,
        {
        "Debes reconstruir correctamente la secuencia historica del quero.",
        "Usa [A] y [D] para moverte entre bloques.",
        "Presiona ENTER para seleccionar e intercambiar.",
        "Presiona [V] para validar la reconstruccion.",
        });

    BloqueNarrativo textoEscena4Nivel3(4, "Escena 4 nivel 3", 0,
        {
        R"(El quero ha sido reconstruido correctamente. Sus tocapus vuelven a formar la secuencia de la Batalla de Yahuarpampa, permitiendo
        recuperar y preservar la historia contenida en el objeto.)"
        });

    BloqueNarrativo textoEscenaFinalJuego(5, "Escena Final nivel 3", 0,
        {
        R"(Las culturas no desaparecen únicamente por factores externos, sino también cuando su conocimiento deja de ser comprendido
        e interpretado. A través de las Humanidades Digitales,
        es posible reconstruir ese conocimiento, pero su preservación depende del análisis crítico
        y la participación activa de quienes lo estudian.)"
        });


        system("cls"); pintarMatriz(matriz_nivel3); _getch();
        system("cls"); pintarMatriz(matriz_mensaje_nivel3); mensajeEscenaNivel3.mostrarBloque(50, 22, 90); _getch();
        system("cls"); pintarMatriz(matriz_escena1_nivel3); textoEscena1Nivel3.mostrarBloque(128, 15, 40); _getch();
        system("cls"); pintarMatriz(matriz_escena2_nivel3);  textoEscena2Nivel3.mostrarBloque(128, 15, 40), _getch();
        system("cls"); pintarMatriz(matriz_escena3_nivel3);  textoEscena3Nivel3.mostrarBloque(40, 20, 90);  _getch();




    Quero queroJuego(1, "Quero Yahuarpampa", "Deteriorado", 4);

    BloqueNarrativo* b1 = new BloqueNarrativo(
        1,
        "Bloque 1",
        0,
        { "Las fuerzas del Inca comienzan a reunirse." }
    );

    b1->setFiguraASCII({
        "  /\\  ",
        " /  \\ ",
        " \\--/ ",
        "  \\/  "
        });



    BloqueNarrativo* b2 = new BloqueNarrativo(
        2,
        "Bloque 2",
        1,
        { "El ejercito avanza hacia Yahuarpampa." }
    );

    b2->setFiguraASCII({
        "#   #",
        "  #  ",
        "#   #",
        });



    BloqueNarrativo* b3 = new BloqueNarrativo(
        3,
        "Bloque 3",
        2,
        { "La batalla contra los chancas se intensifica." }
    );

    b3->setFiguraASCII({
        "  *  ",
        "* * *",
        "  *  ",
        });



    BloqueNarrativo* b4 = new BloqueNarrativo(
        4,
        "Bloque 4",
        3,
        { "La victoria del Inca consolida su autoridad." }
    );

    b4->setFiguraASCII({
        " ******* ",
        "*   ##  *",
        "*   ##  *",
        " ******* "
        });



    // ORDEN DESORDENADO

    queroJuego.agregarBloque(b3);
    queroJuego.agregarBloque(b1);
    queroJuego.agregarBloque(b4);
    queroJuego.agregarBloque(b2);




    int intentos = 3;

    bool jugando = true;

    string ultimoTexto = "";

    system("cls");
    pintarMatriz(matriz_escena_juego_nivel3);


    while (jugando) {

        queroJuego.mostrarBloques();

        vector<BloqueNarrativo*>& bloques = queroJuego.getBloques();

        int actual = queroJuego.getBloqueActual();

        vector<string> descripcion = bloques[actual]->getDescripcion();

        int x = 40;
        int y = 41;
        int contador = 0;

        for (char c : ultimoTexto) {

            if (contador >= 90) {

                y++;
                x = 40;
                contador = 0;
            }

            cursorPosition(x, y);
            cout << ' ';

            x++;
            contador++;
        }


        mostrarDialogoWrap(descripcion[0], 40, 41, 90);

        ultimoTexto = descripcion[0];


        setLetraColor(15);

        cursorPosition(138, 44);
        cout << "INTENTOS: " << intentos << "/3";

        cursorPosition(118, 30);
        cout << "[A][D] MOVER";

        cursorPosition(118, 32);
        cout << "[ENTER] SELECCIONAR";

        cursorPosition(118, 34);
        cout << "[V] VALIDAR";

        int tecla = _getch();

        // IZQUIERDA

        if (tecla == 'a' || tecla == 'A') {

            int nuevo = queroJuego.getBloqueActual() - 1;

            if (nuevo < 0) {
                nuevo = (int)bloques.size() - 1;
            }

            queroJuego.setBloqueActual(nuevo);
        }

        // DERECHA

        else if (tecla == 'd' || tecla == 'D') {

            int nuevo = queroJuego.getBloqueActual() + 1;

            if (nuevo >= (int)bloques.size()) {
                nuevo = 0;
            }

            queroJuego.setBloqueActual(nuevo);
        }


        // SELECCIONAR / INTERCAMBIAR

        else if (tecla == 13) {

            // PRIMER ENTER

            if (queroJuego.getBloqueSeleccionado() == -1) {

                queroJuego.setBloqueSeleccionado(
                    queroJuego.getBloqueActual()
                );
            }

            // SEGUNDO ENTER

            else {

                int a = queroJuego.getBloqueSeleccionado();

                int b = queroJuego.getBloqueActual();

                queroJuego.intercambiarBloques(a, b);

                queroJuego.setBloqueSeleccionado(-1);
            }
        }

        // VALIDAR

        else if (tecla == 'v' || tecla == 'V') {

            bool correcto = true;

            for (size_t i = 0; i < bloques.size(); i++) {

                if (bloques[i]->getPosicionCorrecta() != (int)i) {

                    correcto = false;
                    break;
                }
            }

            // VICTORIA

            if (correcto) {


                setLetraColor(10);

                cursorPosition(121, 2);
                cout << "NARRACION RECONSTRUIDA";

                mostrarDialogoWrap(
                    "Tras la amenaza de los chancas, las fuerzas del Inca comenzaron "
                    "a reunirse para defender el territorio. El ejercito avanzo hacia "
                    "Yahuarpampa, donde el enfrentamiento se intensifico durante horas. "
                    "Finalmente, la victoria del Inca consolido su autoridad y permitio "
                    "preservar la memoria de la batalla a traves de los tocapus del quero.",
                    121,
                    3,
                    42
                );

                _getch();

                system("cls");

                pintarMatriz(matriz_escena4_nivel3);

                textoEscena4Nivel3.mostrarBloque(128, 15, 40);

                _getch();

                system("cls");

                pintarMatriz(matriz_Mensaje_escena5_nivel3);

                textoEscenaFinalJuego.mostrarBloque(49, 21, 90);

                _getch();

                setCompletado(true);

                return;
            }

            // Perder

            else {

                intentos--;

                setLetraColor(15);

                cursorPosition(138, 44);
                cout << "INTENTOS: " << intentos << "/3";

                if (intentos <= 0) {

                    setLetraColor(12);

                    cursorPosition(121, 2);
                    cout << "NARRACION INCOMPLETA";

                    mostrarDialogoWrap(
                        "La secuencia del quero no pudo ser reconstruida correctamente. "
                        "Los fragmentos de la batalla quedaron desordenados y parte de "
                        "la memoria contenida en los tocapus se perdio, impidiendo "
                        "comprender completamente la historia preservada por los incas.",
                        121,
                        3,
                        42
                    );

                    _getch();

                    system("cls");

                    pintarMatriz(matriz_lost);

                    _getch();

                    setCompletado(false);

                    return;
                }
            }
        }
    }
}





void Nivel3::ordenarBloques() {
}

string Nivel3::generarNarrativa() {
    return "";
}