#include "Recursos.h"
#include "JuegoNivelesTocapus.h"
#include "Escenarios.h"




void dibujarBotonMenu(int x, int y);


void borrarBotonMenu(int x, int y);


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

                    JuegoNivelesTocapus juego;
                    juego.iniciarJuego();

    
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


void dibujarBotonMenu(int x, int y) {
    setLetraColor(10);

    cursorPosition(x, y);         cout << (char)219;
    cursorPosition(x, y + 1);     cout << (char)219;
    cursorPosition(x + 1, y + 1); cout << (char)219;
    cursorPosition(x + 2, y + 1); cout << (char)219;
    cursorPosition(x, y + 2);     cout << (char)219;
    cursorPosition(x + 1, y + 2); cout << (char)219;
    cursorPosition(x + 2, y + 2); cout << (char)219;
    cursorPosition(x + 3, y + 2); cout << (char)219;
    cursorPosition(x + 4, y + 2); cout << (char)219;
    cursorPosition(x, y + 3);     cout << (char)219;
    cursorPosition(x + 1, y + 3); cout << (char)219;
    cursorPosition(x + 2, y + 3); cout << (char)219;
    cursorPosition(x, y + 4);     cout << (char)219;
}


void borrarBotonMenu(int x, int y) {

    for (int dy = 0; dy < 5; dy++) {
        for (int dx = 0; dx < 5; dx++) {

            int px = x + dx;
            int py = y + dy;

            cursorPosition(px, py);

            int valor = matriz_menu_principal[py][px];


            if (valor == 0) {
                cout << " ";
            }
            else {
                setLetraColor(valor);
                cout << (char)219;
            }
        }
    }
}