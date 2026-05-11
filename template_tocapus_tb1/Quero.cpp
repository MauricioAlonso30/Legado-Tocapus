#include "Quero.h"

Quero::Quero() : Textil() {
    this->cantidadBloques = 0;
    this->bloqueActual = 0;
    this->bloqueSeleccionado = -1;
}

Quero::Quero(int id, string nombre, string estado, int cantidadBloques)
    : Textil(id, nombre, estado) {

    this->cantidadBloques = cantidadBloques;
    this->bloqueActual = 0;
    this->bloqueSeleccionado = -1;
}

int Quero::getCantidadBloques() {
    return this->cantidadBloques;
}

void Quero::setCantidadBloques(int cantidadBloques) {
    this->cantidadBloques = cantidadBloques;
}

void Quero::agregarBloque(BloqueNarrativo* bloque) {
    this->bloques.push_back(bloque);
}

void Quero::intercambiarBloques(int a, int b) {

    BloqueNarrativo* temporal = this->bloques[a];

    this->bloques[a] = this->bloques[b];

    this->bloques[b] = temporal;
}

int Quero::getBloqueActual() {
    return this->bloqueActual;
}

void Quero::setBloqueActual(int bloqueActual) {
    this->bloqueActual = bloqueActual;
}

int Quero::getBloqueSeleccionado() {
    return this->bloqueSeleccionado;
}

void Quero::setBloqueSeleccionado(int bloqueSeleccionado) {
    this->bloqueSeleccionado = bloqueSeleccionado;
}

vector<BloqueNarrativo*>& Quero::getBloques() {
    return this->bloques;
}

void Quero::reconstruirNarracion() {
}

void Quero::mostrarBloques() {

    int xInicial = 26;
    int yInicial = 24;

    int anchoBloque = 10;
    int altoBloque = 7;

    int separacion = 24;

    for (size_t i = 0; i < bloques.size(); i++) {

        int x = xInicial + (i * separacion);
        int y = yInicial;

     

        if ((int)i == bloqueSeleccionado) {
            setLetraColor(12); 
        }
        else if ((int)i == bloqueActual) {
            setLetraColor(14);
        }
        else {
            setLetraColor(15); 
        }

        // BORDE SUPERIOR

        cursorPosition(x, y);
        cout << char(201);

        for (int j = 0; j < anchoBloque; j++) {
            cout << char(205);
        }

        cout << char(187);

        // LATERALES e INTERIOR

        for (int fila = 1; fila <= altoBloque; fila++) {

            cursorPosition(x, y + fila);
            cout << char(186);

            // LIMPIAR INTERIOR DEL BLOQUE

            for (int columna = 1; columna <= anchoBloque; columna++) {

                cursorPosition(x + columna, y + fila);
                cout << ' ';
            }

            cursorPosition(x + anchoBloque + 1, y + fila);
            cout << char(186);
        }

        // BORDE INFERIOR

        cursorPosition(x, y + altoBloque + 1);
        cout << char(200);

        for (int j = 0; j < anchoBloque; j++) {
            cout << char(205);
        }

        cout << char(188);

        // TEXTO CENTRAL

        setLetraColor(15);

        vector<string> figura = bloques[i]->getFiguraASCII();

        for (size_t linea = 0; linea < figura.size(); linea++) {

            cursorPosition(x + 2, y + 2 + linea);

            cout << figura[linea];
        }
    }
}

bool Quero::validarOrden() {
    return false;
}