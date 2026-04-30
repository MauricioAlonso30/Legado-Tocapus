#include "Unku.h"

Unku::Unku() : Textil() {
    this->filas = 0;
    this->columnas = 0;
}

Unku::Unku(int id, string nombre, string estado, int filas, int columnas)
    : Textil(id, nombre, estado) {
    this->filas = filas;
    this->columnas = columnas;
}

int Unku::getFilas() {
    return this->filas;
}

void Unku::setFilas(int filas) {
    this->filas = filas;
}

int Unku::getColumnas() {
    return this->columnas;
}

void Unku::setColumnas(int columnas) {
    this->columnas = columnas;
}

void Unku::leerIdentidad() {
}

void Unku::mostrarCuadricula() {
}