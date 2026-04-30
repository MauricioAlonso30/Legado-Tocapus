#pragma once
#include <vector>
#include "Textil.h"
#include "BloqueNarrativo.h"

class Quero : public Textil {
private:
    int cantidadBloques;
    vector<BloqueNarrativo*> bloques;
public:
    Quero() {}
    Quero(int id, string nombre, string estado, int cantidadBloques) {}

    int getCantidadBloques() {}
    void setCantidadBloques(int cantidadBloques) {}

    void reconstruirNarracion() {}
    void mostrarBloques() {}
    bool validarOrden() {}
};