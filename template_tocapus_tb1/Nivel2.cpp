#include "Nivel2.h"

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
}

void Nivel2::inspeccionarUnku() {
}

bool Nivel2::deducirSapaInca() {
    return false;
}