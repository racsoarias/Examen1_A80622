#include "stdafx.h"
#include "Arbol.h"

Arbol::Arbol(){
	raiz = NULL;
}
Arbol::~Arbol(){
	if (raiz != NULL) {
		destruirRec(raiz);
	}
}

void Arbol::createArbol(Elemento *nodo){
	if (nodo != NULL){
		this->raiz = nodo;
		createArbolRe(raiz);
		construirRe(raiz);
		resolverRe(raiz);
	}
}
void Arbol::createArbolRe(Elemento *nodo){

	Operacion *newNodo = dynamic_cast<Operacion*>(nodo);

	string str = newNodo->getStr();
	int i = 0, count = 0;
	bool hold = false, action = true;
	char signos[] = { "()+-/*" };

	for (int k = 0; k < 4; k++){
		while (action && i < str.length()){
			if (str.at(0) == signos[0] && str.at(str.length() - 1) == signos[1] && count == 0){
				str = str.substr(1, str.length() - 2);
			}
			if (str.at(i) == signos[0]){
				hold = true;
				count++;
			}
			if (str.at(i) == signos[1]){
				count--;
				if (count == 0){
					hold = false;
				}
			}
			if (hold != true && (str.at(i) == signos[k + 2] || str.at(i) == signos[k + 3])){
				newNodo->setStr(str.substr(i, 1));
				newNodo->setHijoIzq(new Operacion(str.substr(0, i)));
				newNodo->setHijoDer(new Operacion(str.substr(i + 1)));
				nodo = newNodo;
				action = false;
			}
			i++;
		}
		i = 0;
		k++;
	}
	if (nodo->getHijoIzq() != NULL){
		createArbolRe(nodo->getHijoIzq());
	}
	if (nodo->getHijoDer() != NULL){
		createArbolRe(nodo->getHijoDer());
	}
}

void Arbol::construirRe(Elemento *&nodo){
	Operacion *temp = dynamic_cast<Operacion*>(nodo);

	if (nodo->getHijoIzq() == NULL && nodo->getHijoDer() == NULL){
		nodo = new Operando(stod(temp->getStr()));
	}
	else{
		char c = temp->getStr().at(0);
		switch (c){

		case '+':
			nodo = new Suma(c);
			break;
		case'-':
			nodo = new Resta(c);
			break;
		case '*':
			nodo = new Multiplicacion(c);
			break;
		case '/':
			nodo = new Division(c);
			break;
		default:
			break;
		}
		nodo->setHijoIzq(temp->getHijoIzq());
		nodo->setHijoDer(temp->getHijoDer());
	}
	if (nodo->getHijoIzq() != NULL){
		construirRe(nodo->getHijoIzq());
	}
	if (nodo->getHijoDer() != NULL){
		construirRe(nodo->getHijoDer());
	}
}

void Arbol::resolverRe(Elemento *& nodo){
	Operador * operador = dynamic_cast<Operador*>(nodo);
	if (operador != NULL){
		if (nodo->getHijoIzq() != NULL){
			resolverRe(nodo->getHijoIzq());
		}
		if (nodo->getHijoDer() != NULL){
			resolverRe(nodo->getHijoDer());
		}
		nodo = operador->operar(nodo->getHijoIzq(), nodo->getHijoDer());
	}
}

int Arbol::intlength(int i){
	int len = 0;
	if (i > 0){
		for (len = 0; i > 0; len++) {
			i = i / 10;
		}
	}
	return len;
}

void Arbol::destruirRec(Elemento * nodo) {
	if (nodo->getHijoIzq() != NULL) {
		destruirRec(nodo->getHijoIzq());
	}
	if (nodo->getHijoDer() != NULL) {
		destruirRec(nodo->getHijoDer());
	}
	// Primero se destruye a los hijos y luego al padre.
	delete nodo;
}
