#pragma once
#include <iostream>

using namespace std;

class Nivel {
protected:
    int numero;
    string titulo;
    bool completado;
public:
    Nivel();
    Nivel(int numero, string titulo, bool completado);
    ~Nivel();

    int getNumero();
    string getTitulo();
    bool getCompletado();

    void setNumero(int numero);
    void setTitulo(string titulo);
    void setCompletado(bool completado);

    void mostrarIntro();
    virtual void iniciar();
};