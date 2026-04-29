#pragma once
#include "Entidad.h"

class SapaInca : public Entidad {
private:
    string panaca;
    string suyusGobernados;
public:
    SapaInca() {}
    SapaInca(int id, string nombre, string panaca, string suyusGobernados) {}

    string getPanaca() {}
    void setPanaca(string panaca) {}

    string getSuyusGobernados() {}
    void setSuyusGobernados(string suyusGobernados) {}

    void mostrarDatos() {}
};