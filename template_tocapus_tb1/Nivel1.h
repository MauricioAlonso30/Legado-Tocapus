#pragma once
#include "Nivel.h"
#include "Jugador.h"

class Nivel1 : public Nivel {
private:
    Jugador* jugador;
public:
    Nivel1() {}
    Nivel1(int numero, string titulo, bool completado, Jugador* jugador) {}

    void iniciar() override;
    bool validarRespuesta() {}
};