#pragma once
#include <vector>
#include "Entidad.h"
#include "Tocapu.h"

class Codice : public Entidad {
private:
    int capacidad;
    vector<Tocapu*> tocapus;
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