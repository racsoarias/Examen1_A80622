#include "stdafx.h"
#include "Division.h"

Division::Division(char c){
	this->c = c;
}
Division::~Division(){
}
Operando * Division::operar(Elemento * a, Elemento * b){
	return new Operando(dynamic_cast<Operando*>(a)->d / dynamic_cast<Operando*>(b)->d);
}
