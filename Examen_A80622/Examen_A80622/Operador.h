#pragma once
#include "Elemento.h"
#include "Operacion.h"
#include "Operando.h"
using namespace std;
class Operador : public Elemento{

public:
	char c;
	Operador();
	~Operador();	
	virtual Operando * operar(Elemento *, Elemento *); 
};

