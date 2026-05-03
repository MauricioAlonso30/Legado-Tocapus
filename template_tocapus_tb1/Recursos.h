#pragma once
#include <iostream>
#include <conio.h>
#include<vector>
#include <Windows.h>
#include <ctime>
#include <cstdlib>

using namespace std;
using namespace System;

#define ANCHO 170
#define ALTO 50

void cursorPosition(int x, int y);
void pantalla();
int aleatorio(int limiteMinimo, int limiteMaximo);
void setLetraColor(int color);
void setFondoColor(int color);
void pintarMatriz(int matriz[ALTO][ANCHO]);
void mostrarDialogo(vector<string> lineas, int xInicio, int yInicio);
void mostrarDialogoSolo(string mensaje, int xInicio, int yInicio);
void mostrarDialogoWrap(string mensaje, int xInicio, int yInicio, int anchoMaximo);
void mostrarDialogoAuto(vector<string> lineas, int xInicio, int yInicio, int anchoMaximo);

#define JUGADOR_UP 'W'
#define JUGADOR_DOWN 'S'
#define JUGADOR_LEFT 'A'
#define JUGADOR_RIGHT 'D'