#pragma once
#include <vector>
#include "Entidad.h"
#include "Codice.h"

class Jugador : public Entidad {
private:
    int intentos;
    Codice* codice;
    vector<int> aprendidos;
public:
    Jugador();
    Jugador(int id, string nombre, int intentos);

    int getIntentos();
    void setIntentos(int intentos);

    Codice* getCodice();
    void setCodice(Codice* codice);

    void reducirIntentos();
    void reiniciarIntentos();

    void agregarAprendido(int id);
    vector<int>& getAprendidos();
};