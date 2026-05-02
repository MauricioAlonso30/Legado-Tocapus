#include "Nivel3.h"

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
}

void Nivel3::ordenarBloques() {
}

string Nivel3::generarNarrativa() {
    return "";
}