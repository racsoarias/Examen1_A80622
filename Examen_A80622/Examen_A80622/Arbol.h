#pragma once
#include "Elemento.h"
#include "Operacion.h"
#include "Operando.h"
#include "Operador.h"
#include "Suma.h"
#include "Resta.h"
#include "Multiplicacion.h"
#include "Division.h"

using namespace std;
class Arbol{

public:
	Elemento * raiz;

	Arbol();
	virtual ~Arbol();
	void createArbol(Elemento *);
private:
	void resolverRe(Elemento *&);
	void createArbolRe(Elemento *);
	void destruirRec(Elemento *);
	int intlength(int);
	void construirRe(Elemento *&);
};
