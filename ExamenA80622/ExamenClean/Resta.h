#pragma once
#include "Operador.h"
class Resta : public Operador {

public:
	char c; 
	Resta(char);
	~Resta();
	virtual Operando operar(Elemento*, Elemento*);
};

