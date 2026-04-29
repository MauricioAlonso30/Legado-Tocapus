#include "Nivel1.h"

Nivel1::Nivel1() : Nivel() {
    this->jugador = nullptr;
}

Nivel1::Nivel1(int numero, string titulo, bool completado, Jugador* jugador)
    : Nivel(numero, titulo, completado) {
    this->jugador = jugador;
}

void Nivel1::iniciar() {
}

bool Nivel1::validarRespuesta() {
}