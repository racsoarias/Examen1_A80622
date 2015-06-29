#include "stdafx.h"
#include "Resta.h"

Resta::Resta(char c){
	this->c = c;
}
Resta::~Resta(){
}
Operando * Resta::operar(Elemento * a, Elemento * b){
	return new Operando(dynamic_cast<Operando*>(a)->d - dynamic_cast<Operando*>(b)->d);
}