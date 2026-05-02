#pragma once
#include "Entidad.h"

class Tocapu : public Entidad {
protected:
    string simboloASCII;
    string significado;
public:
    Tocapu();
    Tocapu(int id, string nombre, string simboloASCII, string significado);
    virtual ~Tocapu();

    string getSimboloASCII();
    void setSimboloASCII(string simboloASCII);

    string getSignificado();
    void setSignificado(string significado);

    void mostrarTocapu();
    virtual string obtenerCategoria();
};