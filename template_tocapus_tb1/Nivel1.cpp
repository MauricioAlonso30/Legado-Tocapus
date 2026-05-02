#include "Nivel1.h"
#include "Recursos.h"
#include "Escenarios_nivel1.h"
#include "TocapuLinaje.h"
#include "TocapuTerritorio.h"
#include "TocapuJerarquia.h"
#include <conio.h>

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

    system("cls"); pintarMatriz(matriz_nivel1);          _getch();
    system("cls"); pintarMatriz(matriz_mensaje_nivel1);  _getch();
    system("cls"); pintarMatriz(matriz_escena1_nivel1);  _getch();
    system("cls"); pintarMatriz(matriz_escena2_nivel1);  _getch();
    system("cls"); pintarMatriz(matriz_escena3_nivel1);  _getch();

    setCompletado(true);
}

bool Nivel1::validarRespuesta() {
    return false;
}
