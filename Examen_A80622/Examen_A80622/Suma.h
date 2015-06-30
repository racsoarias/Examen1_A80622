#pragma once
#include "Operador.h"
class Suma : public Operador {

public:

	char c;
	Suma(char);
	~Suma();
	virtual Operando *operar(Elemento*, Elemento*);
};

