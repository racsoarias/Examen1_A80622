#include "stdafx.h"
#include "Operacion.h"
#include "Lista.h"
#include "Arbol.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[]) {
	srand((unsigned int)time(NULL));
	ifstream file("Operaciones.txt");
	string str;	
	Lista list, soluciones;
	Arbol tree;

	while (getline(file, str)){
		list.insertar(new Operacion(str));
		tree.createArbol(new Operacion(str));
		soluciones.insertar(tree.raiz);
	}

	system("pause");
	return 0;
}