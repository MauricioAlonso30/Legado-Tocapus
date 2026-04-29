#include "BloqueNarrativo.h"

BloqueNarrativo::BloqueNarrativo() : Entidad() {
    this->posicionCorrecta = 0;
    this->descripcion = "";
    this->cantidadTocapus = 0;
}

BloqueNarrativo::BloqueNarrativo(int id, string nombre, int posicionCorrecta, string descripcion)
    : Entidad(id, nombre) {
    this->posicionCorrecta = posicionCorrecta;
    this->descripcion = descripcion;
    this->cantidadTocapus = 0;
}

int BloqueNarrativo::getPosicionCorrecta() {
    return this->posicionCorrecta;
}

void BloqueNarrativo::setPosicionCorrecta(int posicionCorrecta) {
    this->posicionCorrecta = posicionCorrecta;
}

string BloqueNarrativo::getDescripcion() {
    return this->descripcion;
}

void BloqueNarrativo::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

void BloqueNarrativo::mostrarBloque() {
}