#include "Nivel1.h"
#include "Recursos.h"
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

    system("cls"); pintarMatriz(matriz_mensaje_global); mensajeGlobal.mostrarBloque(40, 23, 90); _getch();
    system("cls"); pintarMatriz(matriz_nivel1); _getch();
    system("cls"); pintarMatriz(matriz_mensaje_nivel1); mensajeEscenaNivel1.mostrarBloque(40, 23, 90); _getch();
    system("cls"); pintarMatriz(matriz_escena1_nivel1); textoEscena1.mostrarBloque(147, 15, 22); _getch();
    system("cls"); pintarMatriz(matriz_escena2_nivel1);  textoEscena2.mostrarBloque(120, 15, 47), _getch();
    system("cls"); pintarMatriz(matriz_escena3_nivel1);  textoEscena3.mostrarBloque(40, 20, 90);  _getch();

    setCompletado(true);
}

bool Nivel1::validarRespuesta() {
    return false;
}
