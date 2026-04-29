#pragma once
#include "Entidad.h"

class Textil : public Entidad {
protected:
    string estado;
public:
    Textil() {}
    Textil(int id, string nombre, string estado) {}
    virtual ~Textil() {}

    string getEstado() {}
    void setEstado(string estado) {}

    void mostrarTextil() {}
};