#pragma once
#include <vector>
#include "Entidad.h"
#include "Tocapu.h"

class BloqueNarrativo : public Entidad {
private:
    int posicionCorrecta;
    string descripcion;
    vector<Tocapu*> tocapus;
public:
    BloqueNarrativo();
    BloqueNarrativo(int id, string nombre, int posicionCorrecta, string descripcion);

    int getPosicionCorrecta();
    void setPosicionCorrecta(int posicionCorrecta);

    string getDescripcion();
    void setDescripcion(string descripcion);

    void mostrarBloque();
};