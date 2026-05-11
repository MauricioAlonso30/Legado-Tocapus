#include "JuegoNivelesTocapus.h"

JuegoNivelesTocapus::JuegoNivelesTocapus() {

    jugador = new Jugador(1, "Qhipu Ayar", 3);

    jugador->getCodice()->setId(1);
    jugador->getCodice()->setNombre("Codice de Qhipu");
    jugador->getCodice()->setCapacidad(15);
}

JuegoNivelesTocapus::~JuegoNivelesTocapus() {

    delete jugador;
}

void JuegoNivelesTocapus::iniciarJuego() {

   
        Nivel1 nivel1(1, "El Aprendiz", false, jugador);

    nivel1.iniciar();

    if (!nivel1.getCompletado()) {
        return;
    }
    


        Nivel2 nivel2(2, "Unkus", false, jugador);

    nivel2.iniciar();

    if (!nivel2.getCompletado()) {
        return;
    }    
   
   
    Nivel3 nivel3(3, "Quero", false, jugador);

    nivel3.iniciar();

    if (!nivel3.getCompletado()) {
        return;
    }

    system("cls");

    pintarMatriz(matriz_win);

    _getch();


}