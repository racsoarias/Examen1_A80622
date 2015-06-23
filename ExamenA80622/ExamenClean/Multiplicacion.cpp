#include "stdafx.h"
#include "Multiplicacion.h"

Multiplicacion::Multiplicacion(char c){
	this->c = c;
}
Multiplicacion::~Multiplicacion(){
}
Operando Multiplicacion::operar(Elemento * a, Elemento * b){
	return *new Operando(dynamic_cast<Operando*>(a)->d * dynamic_cast<Operando*>(b)->d);
}