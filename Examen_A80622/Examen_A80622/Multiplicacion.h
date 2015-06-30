#pragma once
#include "Operador.h"
class Multiplicacion: public Operador {

public:

	char c; 
	Multiplicacion(char);
	~Multiplicacion();
	virtual Operando *operar(Elemento*, Elemento*);
};

