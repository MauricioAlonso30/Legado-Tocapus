#pragma once
#include "Nivel.h"
#include "Jugador.h"
#include "Unku.h"
#include "SapaInca.h"

class Nivel2 : public Nivel {
private:
    Jugador* jugador;
    Unku* unku;
    SapaInca* candidatos[10];
    int cantidadCandidatos;
public:
    Nivel2() {}
    Nivel2(int numero, string titulo, bool completado, Jugador* jugador) {}

    void iniciar() override;
    void inspeccionarUnku() {}
    bool deducirSapaInca() {}
};