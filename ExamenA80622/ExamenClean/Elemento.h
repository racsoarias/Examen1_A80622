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
	/*virtual void imprimir(ostream &) const = 0;
	
	virtual int compareTo(Elemento *) = 0;
	virtual void imprimir(ostream &) const = 0;	
	bool operator<(Elemento &);
	bool operator<=(Elemento &);
	bool operator>(Elemento &);
	bool operator>=(Elemento &);
	*/


};