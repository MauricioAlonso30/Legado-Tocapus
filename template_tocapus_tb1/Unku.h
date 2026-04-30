#pragma once
#include <vector>
#include "Textil.h"
#include "Tocapu.h"

class Unku : public Textil {
private:
    int filas;
    int columnas;
    vector<Tocapu*> tocapus;
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