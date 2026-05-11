#include "BloqueNarrativo.h"

BloqueNarrativo::BloqueNarrativo() : Entidad() {
    this->posicionCorrecta = 0;
}

BloqueNarrativo::BloqueNarrativo(int id, string nombre, int posicionCorrecta, vector<string> descripcion)
    : Entidad(id, nombre) {
    this->posicionCorrecta = posicionCorrecta;
    this->descripcion = descripcion;
}

int BloqueNarrativo::getPosicionCorrecta() {
    return this->posicionCorrecta;
}

void BloqueNarrativo::setPosicionCorrecta(int posicionCorrecta) {
    this->posicionCorrecta = posicionCorrecta;
}

vector<string> BloqueNarrativo::getDescripcion() {
    return this->descripcion;
}

void BloqueNarrativo::setDescripcion(vector<string> descripcion) {
    this->descripcion = descripcion;
}


vector<string> BloqueNarrativo::getFiguraASCII() {
    return this->figuraASCII;
}

void BloqueNarrativo::setFiguraASCII(vector<string> figuraASCII) {
    this->figuraASCII = figuraASCII;
}



void BloqueNarrativo::mostrarBloque(int x, int y, int anchoMaximo) {

    setLetraColor(15);

    for (string linea : this->descripcion) {

        mostrarDialogoWrap(linea, x, y, anchoMaximo);

        y++;
    }
}