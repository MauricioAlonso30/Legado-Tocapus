#pragma once
#include <iostream>
#include <conio.h>
#include<vector>
#include <Windows.h>

using namespace std;
using namespace System;

#define ANCHO 170
#define ALTO 50

void cursorPosition(int x, int y);
void pantalla();
int aleatorio(int limiteMinimo, int limiteMaximo);
void setLetraColor(int color);
void setFondoColor(int color);