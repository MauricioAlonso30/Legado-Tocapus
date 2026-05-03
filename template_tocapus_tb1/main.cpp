#include "Recursos.h"
#include "Nivel1.h"
#include "Escenarios.h"
#include "Jugador.h"
#include <conio.h>
#include <ctime>
#include <cstdlib>

int main() {
    
    int posCursorX = 58;
    int posCursorY = 24;
    int yAnterior = posCursorY;
    bool salir = false; 

    srand((unsigned)time(NULL));
    system("mode con: cols=170 lines=50");
    pantalla();

    pintarMatriz(matriz_menu_principal);
    dibujarBotonMenu(posCursorX, posCursorY);

while (!salir)
    {

        if (posCursorY != yAnterior) {
            borrarBotonMenu(posCursorX, yAnterior);
            yAnterior = posCursorY;
        }

        if (_kbhit()) {
            char tecla = _getch();
            tecla = toupper(tecla);

            switch (tecla)
            {
            case JUGADOR_UP: 
                if (posCursorY == 24) posCursorY = 40;
                else if (posCursorY == 40) posCursorY = 32;
                else if (posCursorY == 32) posCursorY = 24;
                break;

            case JUGADOR_DOWN: 
                if (posCursorY == 24) posCursorY = 32;
                else if (posCursorY == 32) posCursorY = 40;
                else if (posCursorY == 40) posCursorY = 24;
                break;

            case 13: //Boton de Enter 

                switch (posCursorY)
                {
                case 24: // La opcion de Jugar
                {
                    system("cls");

                    Jugador* qhipu = new Jugador(1, "Qhipu Ayar", 3);
                    qhipu->getCodice()->setId(1);
                    qhipu->getCodice()->setNombre("Codice de Qhipu");
                    qhipu->getCodice()->setCapacidad(15);

                    Nivel1 nivel1(1, "El Aprendiz", false, qhipu);
                    nivel1.iniciar();

                    delete qhipu;

                    // Volver al menú
                    system("cls");
                    pintarMatriz(matriz_menu_principal);

                    break;
                }

                case 32: // ILa opcion de creditos
                    system("cls");
                    pintarMatriz(matriz_creditos);
                    _getch();

                    // Volver al menú
                    system("cls");
                    pintarMatriz(matriz_menu_principal);
                    break;

                case 40: // La opcion de salir
                    borrarBotonMenu(posCursorX, posCursorY); 
                    system("cls");
                    pintarMatriz(matriz_salir);
                    _sleep(5000);
                    salir = true;
                    continue; 
                }

                break;
            }
        }

        // Dibujar cursor SOLO si no vas a salir
        if (!salir) {
            dibujarBotonMenu(posCursorX, posCursorY);
        }

        _sleep(50);
    }

    return 0;
}




/*

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


\*/
