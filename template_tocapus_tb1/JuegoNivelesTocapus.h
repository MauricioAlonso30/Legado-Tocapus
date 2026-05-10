#pragma once
#include "Recursos.h"
#include "Nivel1.h"
#include "Nivel2.h"
#include "Nivel3.h"
#include "Escenarios.h"
#include "Jugador.h"

class JuegoNivelesTocapus {

private:

    Jugador* jugador;

public:

    JuegoNivelesTocapus();

    ~JuegoNivelesTocapus();

    void iniciarJuego();
};

