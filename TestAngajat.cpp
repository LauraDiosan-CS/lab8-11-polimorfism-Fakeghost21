#include "Angajat.h"
#include <assert.h>
#include "TestAngajat.h"
#include <iostream>
using namespace std;
void TestAngajat::testAll()
{
	testImplicitConstructor();
	testConstructorWithParameters();
	cout << "Au rulat toate testele!" << endl;
}

void TestAngajat::testImplicitConstructor()
{
	Angajat a;
	assert(a.getNume().empty());
	assert(a.getEmail().empty());
	assert(a.getGrad() == 0);
	assert(a.getId() == -1);
}

void TestAngajat::testConstructorWithParameters()
{
	Angajat a(100,"Dorel","dorel@yahoo.com",2);
	assert(a.getNume() == "Dorel");
	assert(a.getEmail() == "dorel@yahoo.com");
	assert(a.getGrad() == 2);
	assert(a.getId() == 100);
}

void TestAngajat::testCopyConstructor()
{
	Angajat a1(100, "Dorel", "dorel@yahoo.com", 2);
	Angajat a2(a1);
	assert(a2.getNume() == a1.getNume());
	assert(a2.getEmail() == a1.getEmail());
}

void TestAngajat::testClone()
{
	Angajat a1(100, "Dorel", "dorel@yahoo.com", 2);
	Angajat* pClone = (Angajat*)a1.clone();
	assert(a1.equals(pClone));
	assert(&a1 != pClone);
}

void TestAngajat::testSetteri()
{
	Angajat a1(100, "Dorel", "dorel@yahoo.com", 2);
	a1.setNume("Ionel");
	assert(a1.getNume() == "Ionel");
	a1.setGrad(0);
	a1.setEmail("");
	a1.setId(236);
	assert(a1.getEmail().empty());
	assert(a1.getGrad() == 0);
	assert(a1.getId() == 236);
}

void TestAngajat::testAssignmentOperator()
{
	Angajat a1(100, "Dorel", "dorel@yahoo.com", 2);
	Angajat a2;
	a2 = a1;
	assert(a2.getNume() == a1.getNume());
	assert(a2.getEmail() == a2.getEmail());
}

void TestAngajat::testToString()
{
	Angajat a1(100, "Dorel", "dorel@yahoo.com", 2);
	assert(a1.toString(" ") == "100 Dorel dorel@yahoo.com 2");
	assert(a1.toString(",") == "100,Dorel,dorel@yahoo.com,2");
}
