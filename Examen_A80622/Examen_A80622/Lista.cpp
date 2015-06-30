#include "stdafx.h"
#include "Lista.h"

Lista::Lista(){
	cabeza = NULL;
}
Lista::~Lista(){
	Elemento *nodoAcutal = cabeza;
	while (nodoAcutal != NULL){
		nodoAcutal = nodoAcutal->prox;
		nodoAcutal = NULL;
	}
	cabeza = NULL;
}

void Lista::insertar(Elemento *nodoNuevo){
	if (cabeza == NULL){
		cabeza = *&nodoNuevo;
	}
	else {
		Elemento *nodoAcutal = cabeza;
		while (nodoAcutal->prox != NULL){
			nodoAcutal = nodoAcutal->prox;
		}
		nodoAcutal->prox = *&nodoNuevo;
	}
}
