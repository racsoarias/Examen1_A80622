#include "stdafx.h"
#include "Operador.h"


Operador::Operador(){
}

Operador::~Operador(){
}

Operando Operador::operar(Elemento * a, Elemento * b){
	return *new Operando(dynamic_cast<Operando*>(a)->d + dynamic_cast<Operando*>(b)->d);
}
