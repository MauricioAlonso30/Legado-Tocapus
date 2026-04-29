#include "TocapuJerarquia.h"

TocapuJerarquia::TocapuJerarquia() : Tocapu() {
    this->rango = "";
}

TocapuJerarquia::TocapuJerarquia(int id, string nombre, string simboloASCII, string significado, string rango)
    : Tocapu(id, nombre, simboloASCII, significado) {
    this->rango = rango;
}

string TocapuJerarquia::getRango() {
    return this->rango;
}

void TocapuJerarquia::setRango(string rango) {
    this->rango = rango;
}

string TocapuJerarquia::obtenerCategoria() {
    return "Jerarquia: " + this->rango;
}