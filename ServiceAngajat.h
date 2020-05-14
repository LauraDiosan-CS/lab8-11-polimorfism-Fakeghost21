#pragma once
#include "Repository.h"
#include "Angajat.h"
#include "MyExceptionClass.h"
class ServiceAngajat {
private:
	Repository<Angajat>* r;
public:
	ServiceAngajat() {
		this->r = NULL;
	}

	ServiceAngajat(Repository<Angajat>& repo)
	{
		this->r = &repo;
	}

	~ServiceAngajat(){}

	Angajat* look4id(int id)
	{
		for (int i = 0; i < r->getSize(); i++)
		{
			if ((*r->getPosEntity(i)).getId() == id)
				return r->getPosEntity(i);
		}
		throw MyExcept("Id invalid!");
	}

	Angajat* look4email(string email)
	{
		for (int i = 0; i < r->getSize(); i++)
		{
			if ((*r->getPosEntity(i)).getEmail() == email)
				return r->getPosEntity(i);
		}
		throw MyExcept("Email invalid!");
	}

	bool logIn(string username, int password)
	{
		try {
			Angajat a = *this->look4id(password);
			a = *this->look4email(username);
			return true;
		}
		catch (MyExcept & exc)
		{
			throw exc;
		}
	}

	void addElem(int idN, string numeN, string emailN, int gradAccesN) {
		if (gradAccesN < 0)
			throw MyExcept("Grad de acces invalid!");
		Angajat a = Angajat(idN, numeN, emailN, gradAccesN);
		this->r->add(&a);
	}

	void delElem(int id)
	{
		try {
			Angajat a(*this->look4id(id));
			this->r->remove(id);
		}
		catch (MyExcept & exc)
		{
			throw exc;
		}
	}

	vector<Angajat*> getALL() {
		return this->r->getAll();
	}

	void updateElements(int idN, string numeN, string emailN, int gradAccesN) {
		try {
			//this->look4id(idN);
			Angajat a = *this->look4id(idN);
			Angajat aNew(idN, numeN, emailN, gradAccesN);
			this->r->update(&a, &aNew);
		}
		catch (MyExcept & exc) {
			throw exc;
		}
	}

	void clearEntity() {
		this->r->clear();
	}

};