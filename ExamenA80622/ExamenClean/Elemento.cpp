
#include "stdafx.h"
#include "Elemento.h"

Elemento::Elemento(){
	hijoIzq = NULL;
	hijoDer = NULL;
	prox = NULL;
}


Elemento::~Elemento(){
}

Elemento *& Elemento::getHijoIzq() {
	return hijoIzq;
}

Elemento *& Elemento::getHijoDer() {
	return hijoDer;
}

void Elemento::setHijoIzq(Elemento * e) {
	this->hijoIzq = e;
}

void Elemento::setHijoDer(Elemento * e) {
	this->hijoDer = e;
}