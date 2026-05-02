#pragma once
#include "Nivel.h"
#include "Jugador.h"
#include "Quero.h"

class Nivel3 : public Nivel {
private:
    Jugador* jugador;
    Quero* quero;
public:
    Nivel3();
    Nivel3(int numero, string titulo, bool completado, Jugador* jugador);

    void iniciar() override;
    void ordenarBloques();
    string generarNarrativa();
};