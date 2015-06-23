#pragma once
#include "Elemento.h"

class Lista{

public:
	Elemento *cabeza;

	Lista();
	~Lista();	
	
	void insertar(Elemento *);
	void imprimir();

};
