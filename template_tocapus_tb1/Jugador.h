#pragma once
#include "Entidad.h"
#include "Codice.h"

class Jugador : public Entidad {
private:
    int intentos;
    Codice* codice;
public:
    Jugador() {}
    Jugador(int id, string nombre, int intentos) {}

    int getIntentos() {}
    void setIntentos(int intentos) {}

    Codice* getCodice() {}
    void setCodice(Codice* codice) {}

    void reducirIntentos() {}
    void reiniciarIntentos() {}
};