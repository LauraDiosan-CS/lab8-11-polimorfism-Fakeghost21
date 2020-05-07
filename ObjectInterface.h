#pragma once
#include <string>
using namespace std;
class IE {
public:
	/*
		Face o clona a unui obiect de tip IE* si o returneaza
	*/
	virtual IE* clone() = 0;

	/*
		Face o copie a unui obiect de tip IE*
	*/
	virtual void copy(IE*) = 0;

	/*
		Compara id-urile a doua clase de tip IE*
	*/
	virtual bool equals(IE*) = 0;

	/*
		Operatorul compara toate atributele 
	*/
	virtual bool operator==(IE*) = 0;
	virtual string toString(string delim) = 0;
	virtual ~IE() {};
};