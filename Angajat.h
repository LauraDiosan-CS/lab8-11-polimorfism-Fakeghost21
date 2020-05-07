#pragma once
#include "ObjectInterface.h"
#include <string>
using namespace std;

class Angajat : public IE {
private:
	int id, gradAcces;
	string nume;
	string email;
public:
	Angajat() {
		this->id = -1;
		this->gradAcces = 0;
		this->nume = "";
		this->email = "";
	}

	Angajat(int idN, string numeN, string emailN, int gradAccesN) {
		this->id = idN;
		this->nume = numeN;
		this->email = emailN;
		this->gradAcces = gradAccesN;
	}

	Angajat(const Angajat& a) {
		this->id = a.id;
		this->nume = a.nume;
		this->email = a.email;
		this->gradAcces = a.gradAcces;
	}

	int getId() {
		return this->id;
	}

	int getGrad() {
		return this->gradAcces;
	}

	string getNume() {
		return this->nume;
	}

	string getEmail() {
		return this->email;
	}

	void setId(int newId) {
		this->id = newId;
	}

	void setNume(string newNume) {
		this->nume = newNume;
	}

	void setGrad(int newGrad) {
		this->gradAcces = newGrad;
	}

	void setEmail(string newEmail) {
		this->email = newEmail;
	}

	Angajat& operator=(const Angajat& a) {
		this->id = a.id;
		this->nume = a.nume;
		this->email = a.email;
		this->gradAcces = a.gradAcces;
		return *this;
	}

	void copy(IE* OI)
	{
		Angajat* a = (Angajat*)OI;
		this->id = a->id;
		this->nume = a->nume;;
		this->email = a->email;
		this->gradAcces = a->gradAcces;
	}

	bool equals(IE* OI) {
		return (this->id == ((Angajat*)OI)->id);
	}

	IE* clone() {
		Angajat* newAngajat = new Angajat;
		newAngajat->id = this->id;
		newAngajat->nume = this->nume;
		newAngajat->email = this->email;
		newAngajat->gradAcces = this->gradAcces;
		return newAngajat;
	}

	string toString(string delim) {
		string grad = to_string(this->gradAcces);
		string id = to_string(this->id);
		string s = id + delim + this->nume + delim + this->email + delim + grad;
		return s;
	}

	bool operator==(IE* OI) {
		return(this->id == ((Angajat*)OI)->id and this->email == ((Angajat*)OI)->email
			and this->gradAcces == ((Angajat*)OI)->gradAcces and this->nume == ((Angajat*)OI)->nume);
	}
};