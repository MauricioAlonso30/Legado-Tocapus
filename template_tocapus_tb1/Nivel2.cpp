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

void Nivel2::iniciar() {

    BloqueNarrativo mensajeEscenaNivel2(0, "Escena mensaje nivel 2", 0, { "¿Interpretar información es lo mismo que conocer la verdad?" });

    BloqueNarrativo textoEscena1Nivel2(1, "Escena 1 nivel 2", 0,
        {
        R"(Ha llegado el día de la muerte del maestro. Qhipu Ayar ya ha completado su formación inicial y es reconocido como alguien capaz de interpretar los 
        tocapus, por lo que su maestro, orgulloso, puede partir en paz. )"
        });
    BloqueNarrativo textoEscena2Nivel2(2, "Escena 2 nivel 2", 0,
        {
        R"(Días después de su fallecimiento llegan mensajeros del imperio con una misión urgente. En una huaca saqueada se ha encontrado un unku real, pero su 
        origen es desconocido. Ante esta situación, Qhipu Ayar es convocado para reconocerlo y determinar su procedencia, poniendo a prueba todo lo que ha aprendido.)"
        });

    BloqueNarrativo textoEscena3Nivel2(3, "Escena 3 nivel 2", 0,
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
    BloqueNarrativo textoEscena4Nivel2(4, "Escena 4 nivel 2", 0,
        {
        R"(Qhipu Ayar logra interpretar los símbolos correctamente y presenta el unku al Sapa Inca al que pertenece, demostrando así que el conocimiento que aprendió 
        tiene un verdadero valor.)" 
        
        });

    system("cls"); pintarMatriz(matriz_nivel2); _getch();
    system("cls"); pintarMatriz(matriz_mensaje_nivel2); mensajeEscenaNivel2.mostrarBloque(50, 24, 90); _getch();
    system("cls"); pintarMatriz(matriz_escena1_nivel2); textoEscena1Nivel2.mostrarBloque(128, 15, 39); _getch();
    system("cls"); pintarMatriz(matriz_escena2_nivel2);  textoEscena2Nivel2.mostrarBloque(128, 15, 39), _getch();
    system("cls"); pintarMatriz(matriz_escena3_nivel2);  textoEscena3Nivel2.mostrarBloque(40, 20, 90);  _getch();



    //este va al ultimo despues de la logica del juego
    system("cls"); pintarMatriz(matriz_escena4_nivel2);  textoEscena4Nivel2.mostrarBloque(128, 15, 39);  _getch();

    setCompletado(true);
}

void Nivel2::inspeccionarUnku() {
}

bool Nivel2::deducirSapaInca() {
    return false;
}