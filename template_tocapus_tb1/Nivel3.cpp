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


    BloqueNarrativo mensajeEscenaNivel3(0, "Escena mensaje nivel 3", 0, { "¿Qué ocurre cuando una historia se pierde o se reconstruye de forma incorrecta?" });

    BloqueNarrativo textoEscena1Nivel3(1, "Escena 1 nivel 3", 0,
        {
        R"(Años después, con la llegada de Francisco Pizarro al Perú, el Imperio 
        Inca entra en un periodo de caos e inestabilidad que pone en riesgo la preservación de su memoria cultural. )"
        });
    BloqueNarrativo textoEscena2Nivel3(2, "Escena 2 nivel 3", 0,
        {
        R"(En medio de este conflicto, un quipucamayoc, amigo de Qhipu Ayar, le entrega un quero ceremonial dañado; cuyas superficies contienen escenas 
        narrativas representadas mediante piezas de tocapus.)"
        });

    BloqueNarrativo textoEscena3Nivel3(3, "Escena 3 nivel 3", 0,
        {
        "Debes observar cada tocapu y seleccionar su significado correcto.",
        "Usa las teclas W y S para desplazarte entre las opciones.",
        "Presiona ENTER para confirmar tu respuesta.",
        "Tienes intentos limitados.",
        "Cada acierto se registrará en tu códice."
        "Modificar."
        "Modificar."
        "Modificar."
        });
    BloqueNarrativo textoEscena4Nivel3(4, "Escena 4 nivel 3", 0,
        {
        R"(El quero ha sido reconstruido correctamente. Sus tocapus vuelven a formar la secuencia de la Batalla de Yahuarpampa, permitiendo 
        recuperar y preservar la historia contenida en el objeto.)"
        });

    system("cls"); pintarMatriz(matriz_nivel3); _getch();
    system("cls"); pintarMatriz(matriz_mensaje_nivel3); mensajeEscenaNivel3.mostrarBloque(50, 22, 90); _getch();
    system("cls"); pintarMatriz(matriz_escena1_nivel3); textoEscena1Nivel3.mostrarBloque(128, 15, 40); _getch();
    system("cls"); pintarMatriz(matriz_escena2_nivel3);  textoEscena2Nivel3.mostrarBloque(128, 15, 40), _getch();
    system("cls"); pintarMatriz(matriz_escena3_nivel3);  textoEscena3Nivel3.mostrarBloque(40, 20, 90);  _getch();



    //este va al ultimo despues de la logica del juego
    system("cls"); pintarMatriz(matriz_escena4_nivel3);  textoEscena4Nivel3.mostrarBloque(128, 15, 40);  _getch();

    setCompletado(true);
}




void Nivel3::ordenarBloques() {
}

string Nivel3::generarNarrativa() {
    return "";
}