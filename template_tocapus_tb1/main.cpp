#include "Recursos.h"
#include "Nivel1.h"
#include "Jugador.h"
#include <conio.h>
#include <ctime>
#include <cstdlib>

int main() {
    srand((unsigned)time(NULL));
    system("mode con: cols=170 lines=50");
    pantalla();

    setLetraColor(15);
    cursorPosition(60, 21);
    cout << "presiona una tecla para comenzar";
    _getch();
    system("cls");

    Jugador* qhipu = new Jugador(1, "Qhipu Ayar", 3);
    qhipu->getCodice()->setId(1);
    qhipu->getCodice()->setNombre("Codice de Qhipu");
    qhipu->getCodice()->setCapacidad(15);

    Nivel1 nivel1(1, "El Aprendiz", false, qhipu);
    nivel1.iniciar();

    delete qhipu;
    return 0;
}
