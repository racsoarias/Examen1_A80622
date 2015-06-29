#pragma once

using namespace std;

class Elemento{

protected:
	Elemento();
	Elemento * hijoIzq, *hijoDer;

public:
	Elemento * prox;
	virtual ~Elemento();
	Elemento *& getHijoIzq();
	Elemento *& getHijoDer();
	void setHijoIzq(Elemento *);
	void setHijoDer(Elemento *);

};