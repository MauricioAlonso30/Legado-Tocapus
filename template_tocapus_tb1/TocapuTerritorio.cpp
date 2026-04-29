#include "TocapuTerritorio.h"

TocapuTerritorio::TocapuTerritorio() : Tocapu() {
    this->suyu = "";
}

TocapuTerritorio::TocapuTerritorio(int id, string nombre, string simboloASCII, string significado, string suyu)
    : Tocapu(id, nombre, simboloASCII, significado) {
    this->suyu = suyu;
}

string TocapuTerritorio::getSuyu() {
    return this->suyu;
}

void TocapuTerritorio::setSuyu(string suyu) {
    this->suyu = suyu;
}

string TocapuTerritorio::obtenerCategoria() {
    return "Territorio: " + this->suyu;
}