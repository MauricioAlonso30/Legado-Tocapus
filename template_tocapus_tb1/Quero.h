#pragma once
#include <vector>
#include "Recursos.h"
#include "Textil.h"
#include "BloqueNarrativo.h"

class Quero : public Textil {
private:
    int cantidadBloques;
    vector<BloqueNarrativo*> bloques;
    int bloqueActual;
    int bloqueSeleccionado;

public:
    Quero();
    Quero(int id, string nombre, string estado, int cantidadBloques);

    int getCantidadBloques();
    void setCantidadBloques(int cantidadBloques);

    void reconstruirNarracion();
    void mostrarBloques();
    bool validarOrden();


    void agregarBloque(BloqueNarrativo* bloque);
    void intercambiarBloques(int a, int b);

    int getBloqueActual();
    void setBloqueActual(int bloqueActual);

    int getBloqueSeleccionado();
    void setBloqueSeleccionado(int bloqueSeleccionado);

    vector<BloqueNarrativo*>& getBloques();

};