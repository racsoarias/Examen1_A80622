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
		createArbolRe(raiz);//Este método toma la raíz una vez y la separa
		segregar(raiz);//Este método revisa todos los nodos y llama a createArbolRe
		construir(raiz);
		resolverRe(raiz);
	}
}
void Arbol::createArbolRe(Elemento *nodo){

	Operacion *newNodo = static_cast<Operacion*>(nodo);

	string str = newNodo->getStr();
	int i = 0, count = 0, k=0;
	bool hold = false, action = true;
	char signos[] = { "()+-/*" };

	for (k; k < 4; k++){
		while (action && i < str.length()){
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
			if (str.at(0) == signos[0] && str.at(str.length() - 1) == signos[1] && count == 0){
				str = str.substr(1, str.length() - 2);
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
}

void Arbol::segregar(Elemento *nodo){//Este método revisa todos los nodos y llama a createArbolRe

	if (nodo->getHijoIzq() != NULL){
		createArbolRe(nodo->getHijoIzq());
		segregar(nodo->getHijoIzq());
	}
	if (nodo->getHijoDer() != NULL){
		createArbolRe(nodo->getHijoDer());
		segregar(nodo->getHijoDer());
	}
}

void Arbol::construir(Elemento *&nodo){
	Operacion *newNodo = dynamic_cast<Operacion*>(nodo);

	if (nodo->getHijoIzq() == NULL && nodo->getHijoDer() == NULL){
		nodo = new Operando(stod(newNodo->getStr()));
	}
	else{
		char c = newNodo->getStr().at(0);
		switch (c){

		case '+':
			nodo = &*new Suma(c);
			break;
		case'-':
			nodo = &*new Resta(c);
			break;
		case '*':
			nodo = &*new Multiplicacion(c);
			break;
		case '/':
			nodo = &*new Division(c);
			break;
		default:
			break;
		}
		nodo->setHijoIzq(newNodo->getHijoIzq());
		nodo->setHijoDer(newNodo->getHijoDer());
	}
	if (nodo->getHijoIzq() != NULL){
		construir(nodo->getHijoIzq());
	}
	if (nodo->getHijoDer() != NULL){
		construir(nodo->getHijoDer());
	}
}

void Arbol::resolverRe(Elemento *&nodo){

	if (dynamic_cast<Operando*>(nodo->getHijoIzq()) != NULL &&
		dynamic_cast<Operando*>(nodo->getHijoDer()) != NULL){

		nodo = &dynamic_cast<Operador*>(nodo)->operar(nodo->getHijoIzq(), nodo->getHijoDer());
		cout << endl;
	}
	else{
		if (dynamic_cast<Operando*>(nodo->getHijoIzq()) == NULL){
			resolverRe(nodo->getHijoIzq());
		}
		if (dynamic_cast<Operando*>(nodo->getHijoDer()) == NULL){
			resolverRe(nodo->getHijoDer());
		}
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
