#pragma once
#include "Recursos.h"
#include "Entidad.h"
#include "Tocapu.h"

class BloqueNarrativo : public Entidad {
private:
    int posicionCorrecta;
    vector<string> descripcion;
    vector<string> figuraASCII;
    vector<Tocapu*> tocapus;
public:
    BloqueNarrativo();
    BloqueNarrativo(int id, string nombre, int posicionCorrecta, vector<string> descripcion);

    int getPosicionCorrecta();
    void setPosicionCorrecta(int posicionCorrecta);

    vector<string> getDescripcion();
    void setDescripcion(vector<string> descripcion);
    vector<string> getFiguraASCII();
    void setFiguraASCII(vector<string> figuraASCII);

    void mostrarBloque(int x, int y, int anchoMaximo);
};