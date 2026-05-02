#pragma once
#include "Tocapu.h"

class TocapuLinaje : public Tocapu {
private:
    string panaca;
public:
    TocapuLinaje();
    TocapuLinaje(int id, string nombre, string simboloASCII, string significado, string panaca);

    string getPanaca();
    void setPanaca(string panaca);

    string obtenerCategoria() override;
};