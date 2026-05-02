#include "Recursos.h"


void cursorPosition(int x, int y)
{
	Console::SetCursorPosition(x, y);
}

void pantalla()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX cfi = {};
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 8;
	cfi.dwFontSize.Y = 12;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(hOut, FALSE, &cfi);

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

void pintarMatriz(int matriz[ALTO][ANCHO]) {
	for (int f = 0; f < 50; f++)
	{
		for (int c = 0; c < 170; c++)
		{
			cursorPosition(c, f);
			if (matriz[f][c] == 0)  Console::ForegroundColor = ConsoleColor::Black;
			else if (matriz[f][c] == 1)  Console::ForegroundColor = ConsoleColor::DarkBlue;
			else if (matriz[f][c] == 2)  Console::ForegroundColor = ConsoleColor::Green;
			else if (matriz[f][c] == 3)  Console::ForegroundColor = ConsoleColor::Cyan;
			else if (matriz[f][c] == 4)  Console::ForegroundColor = ConsoleColor::DarkRed;
			else if (matriz[f][c] == 5)  Console::ForegroundColor = ConsoleColor::DarkMagenta;
			else if (matriz[f][c] == 6)  Console::ForegroundColor = ConsoleColor::DarkYellow;
			else if (matriz[f][c] == 7)  Console::ForegroundColor = ConsoleColor::Gray;
			else if (matriz[f][c] == 8)  Console::ForegroundColor = ConsoleColor::DarkGray;
			else if (matriz[f][c] == 9)  Console::ForegroundColor = ConsoleColor::Blue;
			else if (matriz[f][c] == 10)  Console::ForegroundColor = ConsoleColor::DarkGreen;
			else if (matriz[f][c] == 11)  Console::ForegroundColor = ConsoleColor::DarkCyan;
			else if (matriz[f][c] == 12)  Console::ForegroundColor = ConsoleColor::Red;
			else if (matriz[f][c] == 13)  Console::ForegroundColor = ConsoleColor::Magenta;
			else if (matriz[f][c] == 14)  Console::ForegroundColor = ConsoleColor::Yellow;
			else if (matriz[f][c] == 15)  Console::ForegroundColor = ConsoleColor::White;

			cout << (char)219;
		}
	}
}

// Mostrar dialogo con una oracion o linea -> strings
void mostrarDialogoSolo(string mensaje, int xInicio, int yInicio) {
	/*
	mostrarDialogo(escenario1_reglas, 36, 16);
	*/

	// Mostrar el texto letra por letra
	cursorPosition(xInicio, yInicio); // texto centrado
	setLetraColor(15); // color blanco
	for (char c : mensaje) {
		cout << c;
		_sleep(30); // velocidad de aparacion del mensaje
	}
}

// Mostrar texto con varias lineas
void mostrarDialogo(vector<string> lineas, int xInicio, int yInicio) {
	setLetraColor(15);
	int y = yInicio;

	for (string linea : lineas) {
		cursorPosition(xInicio, y++);
		for (char c : linea) {
			cout << c;
			_sleep(30);
		}
		Beep(250, 100);
	}
}
