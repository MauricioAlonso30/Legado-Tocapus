#include "Quero.h"

Quero::Quero() : Textil() {
    this->cantidadBloques = 0;
}

Quero::Quero(int id, string nombre, string estado, int cantidadBloques)
    : Textil(id, nombre, estado) {
    this->cantidadBloques = cantidadBloques;
}

int Quero::getCantidadBloques() {
    return this->cantidadBloques;
}

void Quero::setCantidadBloques(int cantidadBloques) {
    this->cantidadBloques = cantidadBloques;
}

void Quero::reconstruirNarracion() {
}

void Quero::mostrarBloques() {
}

bool Quero::validarOrden() {
    return false;
}