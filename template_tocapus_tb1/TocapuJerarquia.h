#pragma once
#include "Tocapu.h"

class TocapuJerarquia : public Tocapu {
private:
    string rango;
public:
    TocapuJerarquia();
    TocapuJerarquia(int id, string nombre, string simboloASCII, string significado, string rango);

    string getRango();
    void setRango(string rango);

    string obtenerCategoria() override;
};