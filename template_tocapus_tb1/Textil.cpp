#include "Textil.h"

Textil::Textil() : Entidad() {
    this->estado = "";
}

Textil::Textil(int id, string nombre, string estado)
    : Entidad(id, nombre) {
    this->estado = estado;
}

Textil::~Textil() {
}

string Textil::getEstado() {
    return this->estado;
}

void Textil::setEstado(string estado) {
    this->estado = estado;
}

void Textil::mostrarTextil() {
}