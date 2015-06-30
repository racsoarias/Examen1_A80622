#include "stdafx.h"
#include "Operacion.h"

Operacion::Operacion(string str): Elemento(), str(str){
// equivalente a this->str = str;
}


Operacion::~Operacion(){
}


string Operacion::getStr(){
	return str;
}
void Operacion::setStr(string str){
	this->str = str;
}
