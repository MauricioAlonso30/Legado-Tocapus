#include "Recursos.h"


void cursorPosition(int x, int y)
{
	Console::SetCursorPosition(x, y);
}

void pantalla()
{
	Console::CursorVisible = 0;
	Console::SetBufferSize(ANCHO, ALTO);
	Console::SetWindowSize(ANCHO, ALTO);
}

int aleatorio(int limiteMinimo, int limiteMaximo) {
	return limiteMinimo + (rand() % (limiteMaximo - limiteMinimo + 1));
}

void setLetraColor(int color) {
	Console::ForegroundColor = ConsoleColor(color);
}

void setFondoColor(int color) {
	Console::BackgroundColor = ConsoleColor(color);
}