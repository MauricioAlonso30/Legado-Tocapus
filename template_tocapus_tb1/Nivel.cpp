#include "Nivel.h"

Nivel::Nivel() {
    this->numero = 0;
    this->titulo = "";
    this->completado = false;
}

Nivel::Nivel(int numero, string titulo, bool completado) {
    this->numero = numero;
    this->titulo = titulo;
    this->completado = completado;
}

Nivel::~Nivel() {
}

int Nivel::getNumero() {
    return this->numero;
}

string Nivel::getTitulo() {
    return this->titulo;
}

bool Nivel::getCompletado() {
    return this->completado;
}

void Nivel::setNumero(int numero) {
    this->numero = numero;
}

void Nivel::setTitulo(string titulo) {
    this->titulo = titulo;
}

void Nivel::setCompletado(bool completado) {
    this->completado = completado;
}

void Nivel::mostrarIntro() {
}

void Nivel::iniciar() {
}