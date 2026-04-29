#pragma once
#include "Entidad.h"
#include "Tocapu.h"

class Codice : public Entidad {
private:
    int capacidad;
    Tocapu* tocapus[100];
    int cantidadActual;
public:
    Codice() {}
    Codice(int id, string nombre, int capacidad) {}

    int getCapacidad() {}
    void setCapacidad(int capacidad) {}

    void agregarTocapu(Tocapu* tocapu) {}
    Tocapu* buscarTocapu(int id) {}
    void mostrarCodice() {}
    bool estaLleno() {}
};