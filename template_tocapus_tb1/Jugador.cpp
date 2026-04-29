#include "Jugador.h"

Jugador::Jugador() : Entidad() {
    this->intentos = 0;
    this->codice = nullptr;
}

Jugador::Jugador(int id, string nombre, int intentos)
    : Entidad(id, nombre) {
    this->intentos = intentos;
    this->codice = new Codice();
}

int Jugador::getIntentos() {
    return this->intentos;
}

void Jugador::setIntentos(int intentos) {
    this->intentos = intentos;
}

Codice* Jugador::getCodice() {
    return this->codice;
}

void Jugador::setCodice(Codice* codice) {
    this->codice = codice;
}

void Jugador::reducirIntentos() {
}

void Jugador::reiniciarIntentos() {
}