#include "SapaInca.h"

SapaInca::SapaInca() : Entidad() {
    this->panaca = "";
    this->suyusGobernados = "";
}

SapaInca::SapaInca(int id, string nombre, string panaca, string suyusGobernados)
    : Entidad(id, nombre) {
    this->panaca = panaca;
    this->suyusGobernados = suyusGobernados;
}

string SapaInca::getPanaca() {
    return this->panaca;
}

void SapaInca::setPanaca(string panaca) {
    this->panaca = panaca;
}

string SapaInca::getSuyusGobernados() {
    return this->suyusGobernados;
}

void SapaInca::setSuyusGobernados(string suyusGobernados) {
    this->suyusGobernados = suyusGobernados;
}

void SapaInca::mostrarDatos() {
}