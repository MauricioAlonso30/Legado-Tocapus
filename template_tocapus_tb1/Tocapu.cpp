#include "Tocapu.h"

Tocapu::Tocapu() : Entidad() {
    this->simboloASCII = "";
    this->significado = "";
}

Tocapu::Tocapu(int id, string nombre, string simboloASCII, string significado)
    : Entidad(id, nombre) {
    this->simboloASCII = simboloASCII;
    this->significado = significado;
}

Tocapu::~Tocapu() {
}

string Tocapu::getSimboloASCII() {
    return this->simboloASCII;
}

void Tocapu::setSimboloASCII(string simboloASCII) {
    this->simboloASCII = simboloASCII;
}

string Tocapu::getSignificado() {
    return this->significado;
}

void Tocapu::setSignificado(string significado) {
    this->significado = significado;
}

void Tocapu::mostrarTocapu() {
}

string Tocapu::obtenerCategoria() {
    return "Tocapu generico";
}