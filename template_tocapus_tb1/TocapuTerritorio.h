#pragma once
#include "Tocapu.h"

class TocapuTerritorio : public Tocapu {
private:
    string suyu;
public:
    TocapuTerritorio() {}
    TocapuTerritorio(int id, string nombre, string simboloASCII, string significado, string suyu) {}

    string getSuyu() {}
    void setSuyu(string suyu) {}

    string obtenerCategoria() override;
};