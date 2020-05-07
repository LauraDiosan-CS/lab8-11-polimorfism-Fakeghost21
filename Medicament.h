#pragma once
#include "ObjectInterface.h"
#include <string>
using namespace std;

class Medicament : public IE {
private:
	int id, stoc, reteta;
	string producator;
public:
	Medicament() {
		this->id = -1;
		this->stoc = 0;
		this->reteta = -1;
		this->producator = "";
	}

	Medicament(int id, string producator, int stoc, int reteta)
	{
		this->id = id;
		this->stoc = stoc;
		this->reteta = reteta;
		this->producator = producator;
	}

	Medicament(const Medicament& m) {
		this->id = m.id;
		this->stoc = m.stoc;
		this->reteta = m.reteta;
		this->producator = m.producator;
	}

	int getId() {
		return this->id;
	}

	int getStoc() {
		return this->stoc;
	}

	string getProducator() {
		return this->producator;
	}

	int getReteta() {
		return this->reteta;
	}

	void setId(int newId) {
		this->id = newId;
	}

	void setProducator(string newProducator) {
		this->producator = newProducator;
	}

	void setStoc(int newStoc) {
		this->stoc = newStoc;
	}

	void setReteta(int newReteta) {
		this->reteta = newReteta;
	}

	Medicament& operator=(const Medicament& m) {
		this->id = m.id;
		this->stoc = m.stoc;
		this->reteta = m.reteta;
		this->producator = m.producator;
		return *this;
	}

	void copy(IE* OI)
	{
		Medicament* m = (Medicament*)OI;
		this->id = m->id;
		this->stoc = m->stoc;
		this->reteta = m->reteta;
		this->producator = m->producator;
	}

	bool equals(IE* OI) {
		return (this->id == ((Medicament*)OI)->id);
	}

	IE* clone() {
		Medicament* newMedicament = new Medicament;
		newMedicament->id = this->id;
		newMedicament->producator = this->producator;
		newMedicament->stoc = this->stoc;
		newMedicament->reteta = this->reteta;
		return newMedicament;
	}

	string toString(string delim) {
		string stoc = to_string(this->stoc);
		string id = to_string(this->id);
		string reteta = to_string(this->reteta);
		string s = id + delim + this->producator + delim + stoc + delim + reteta;
		return s;
	}

	bool operator==(IE* OI) {
		return(this->id == ((Medicament*)OI)->id and this->producator == ((Medicament*)OI)->producator
			and this->reteta == ((Medicament*)OI)->reteta and this->stoc == ((Medicament*)OI)->stoc);
	}
};