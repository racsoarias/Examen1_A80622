#pragma once
#include "Elemento.h"
using namespace std;
class Operando: public Elemento{

public:
	double d;
	int i;
	Operando(double);
	~Operando();
	
};

