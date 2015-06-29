#include "stdafx.h"
#include "Suma.h"

Suma::Suma(char c){
	this->c = c;
}
Suma::~Suma(){
}
Operando * Suma::operar(Elemento * a, Elemento * b){
	return new Operando(dynamic_cast<Operando*>(a)->d + dynamic_cast<Operando*>(b)->d);
}