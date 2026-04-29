#include "Codice.h"

Codice::Codice() : Entidad() {
    this->capacidad = 0;
    this->cantidadActual = 0;
}

Codice::Codice(int id, string nombre, int capacidad)
    : Entidad(id, nombre) {
    this->capacidad = capacidad;
    this->cantidadActual = 0;
}

int Codice::getCapacidad() {
    return this->capacidad;
}

void Codice::setCapacidad(int capacidad) {
    this->capacidad = capacidad;
}

void Codice::agregarTocapu(Tocapu* tocapu) {
}

Tocapu* Codice::buscarTocapu(int id) {
}

void Codice::mostrarCodice() {
}

bool Codice::estaLleno() {
}