#include "Codice.h"

Codice::Codice() : Entidad() {
    this->capacidad = 0;
}

Codice::Codice(int id, string nombre, int capacidad)
    : Entidad(id, nombre) {
    this->capacidad = capacidad;
}

int Codice::getCapacidad() {
    return this->capacidad;
}

void Codice::setCapacidad(int capacidad) {
    this->capacidad = capacidad;
}

void Codice::agregarTocapu(Tocapu* tocapu) {
    if (!estaLleno()) {
        tocapus.push_back(tocapu);
    }
}

Tocapu* Codice::buscarTocapu(int id) {
    for (Tocapu* t : tocapus) {
        if (t != nullptr && t->getId() == id) {
            return t;
        }
    }
    return nullptr;
}

void Codice::mostrarCodice() {
}

bool Codice::estaLleno() {
    return (int)tocapus.size() >= capacidad;
}