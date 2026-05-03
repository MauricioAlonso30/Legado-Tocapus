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




string limpiarTexto(string texto) {

	string textoLimpio = "";
	bool inicioLinea = true;

	for (char letra : texto) {

		if (letra == '\n') {
			textoLimpio += ' ';
			inicioLinea = true;
		}
		else if (inicioLinea && letra == ' ') {
			// Ignorar espacios al comenzar línea
		}
		else {
			textoLimpio += letra;
			inicioLinea = false;
		}
	}

	return textoLimpio;
}

// Mostrar dialogo con una oracion o linea -> strings



void mostrarDialogoSolo(string mensaje, int xInicio, int yInicio) {

	cursorPosition(xInicio, yInicio);
	setLetraColor(15);

	// Mostrar el texto letra por letra
	cursorPosition(xInicio, yInicio); // texto centrado
	setLetraColor(15); // color blanco
	for (char c : mensaje) {
		cout << c;
		_sleep(30);

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

		Beep(250, 100); // ?? NO BORRADO (lo respeté)
	}
}



void mostrarDialogoWrap(string mensaje, int xInicio, int yInicio, int anchoMaximo) {

	mensaje = limpiarTexto(mensaje);

	int x = xInicio;
	int y = yInicio;
	int contador = 0;

	setLetraColor(15);

	for (char c : mensaje) {

		// protección pantalla
		if (y >= ALTO - 1) return;

		// salto automático por ancho
		if (contador >= anchoMaximo) {
			y++;
			x = xInicio;
			contador = 0;

			if (y >= ALTO - 1) return;
		}

		cursorPosition(x, y);
		cout << c;
		_sleep(25);

		x++;
		contador++;
	}
}





void mostrarDialogoAuto(vector<string> lineas, int xInicio, int yInicio, int anchoMaximo) {

	setLetraColor(15);

	int y = yInicio;

	for (string linea : lineas) {

		int x = xInicio;
		int contador = 0;

		for (char c : linea) {

			if (contador >= anchoMaximo) {
				y++;
				x = xInicio;
				contador = 0;
			}

			cursorPosition(x, y);
			cout << c;
			_sleep(25);

			x++;
			contador++;
		}

		y++; // siguiente línea
	}
}

