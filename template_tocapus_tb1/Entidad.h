#pragma once
#include <iostream>

using namespace std;

class Entidad {
	protected:
		int id;
		string nombre;
	public:
		Entidad();
		Entidad(int id, string nombre);
		~Entidad();

		int getId();
		string getNombre();

		void setId(int id);
		void setNombre(string nombre);

		void mostrarInfo();
};