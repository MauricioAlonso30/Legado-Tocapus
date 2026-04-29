#pragma once
#include "Textil.h"
#include "Tocapu.h"

class Unku : public Textil {
private:
    int filas;
    int columnas;
    Tocapu* tocapus[50];
    int cantidadTocapus;
public:
    Unku() {}
    Unku(int id, string nombre, string estado, int filas, int columnas) {}

    int getFilas() {}
    void setFilas(int filas) {}

    int getColumnas() {}
    void setColumnas(int columnas) {}

    void leerIdentidad() {}
    void mostrarCuadricula() {}
};