#include "TocapuLinaje.h"

TocapuLinaje::TocapuLinaje() : Tocapu() {
    this->panaca = "";
}

TocapuLinaje::TocapuLinaje(int id, string nombre, string simboloASCII, string significado, string panaca)
    : Tocapu(id, nombre, simboloASCII, significado) {
    this->panaca = panaca;
}

string TocapuLinaje::getPanaca() {
    return this->panaca;
}

void TocapuLinaje::setPanaca(string panaca) {
    this->panaca = panaca;
}

string TocapuLinaje::obtenerCategoria() {
    return "Linaje: " + this->panaca;
}