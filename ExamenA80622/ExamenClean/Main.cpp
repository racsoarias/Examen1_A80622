#include "stdafx.h"
#include "Elemento.h"
#include "Operador.h"
#include "Operacion.h"
#include "Operando.h"
#include "Lista.h"
#include "Arbol.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[]) {
	srand(time(NULL));
	ifstream file("Operaciones.txt");
	string str;	
	Lista list, soluciones;
	Arbol tree;

	while (getline(file, str)){
		list.insertar(new Operacion(str));
		tree.createArbol(new Operacion(str));
		soluciones.insertar(tree.raiz);

	}

	list.~Lista();
	soluciones.~Lista();

	system("pause");
	return 0;
}