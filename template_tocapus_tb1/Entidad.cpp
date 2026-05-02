#include "Entidad.h"

Entidad::Entidad() {
    this->id = 0;
    this->nombre = "";
}

Entidad::Entidad(int id, string nombre) {
    this->id = id;
    this->nombre = nombre;
}

Entidad::~Entidad() {
}

int Entidad::getId() {
    return this->id;
}

string Entidad::getNombre() {
    return this->nombre;
}

void Entidad::setId(int id) {
    this->id = id;
}

void Entidad::setNombre(string nombre) {
    this->nombre = nombre;
}

void Entidad::mostrarInfo() {
}