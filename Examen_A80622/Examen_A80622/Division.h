#pragma once
#include "Operador.h"
class Division : public Operador {

public:

	char c; 
	Division(char);
	~Division();
	virtual Operando *operar(Elemento*, Elemento*);
};