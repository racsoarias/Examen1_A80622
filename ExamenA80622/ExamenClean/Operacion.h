#pragma once
#include "Elemento.h"

using namespace std;

class Operacion : public Elemento{

protected:
	string str;
	
public:

	Operacion(string);
	virtual ~Operacion();	
	
	string getStr();	
	void setStr(string); 

};