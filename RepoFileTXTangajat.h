#pragma once
#include "RepoFile.h"
#include "Angajat.h"

class RepoTXTangajat : public RepoGeneral {
private:
	string filenameInOut;
public:
	RepoTXTangajat(IContainer* e,string inOut) : RepoGeneral(e)
	{
		this->filenameInOut = inOut;
		this->loadFromFile();
	}

	~RepoTXTangajat() {

	}

	void add(IE* e) {
		RepoGeneral::add(e);
		this->saveToFile();
	}

	void del(IE* e) {
		RepoGeneral::del(e);
		this->saveToFile();
	}

	void update(IE* oldElem, IE* newElem)
	{
		RepoGeneral::update(oldElem,newElem);
		this->saveToFile();
	}

	int getSize() {
		return RepoGeneral::getSize();
	}

	void saveToFile() {
		ofstream f(this->filenameInOut);
		string delim = " ";
		if (f.is_open())
		{
			for (int i = 0; i < this->getSize(); i++)
			{
				string s = this->getALL()[i]->toString(delim);
				f << s << endl;
			}
		}
	}

	void loadFromFile()
	{
		ifstream f(this->filenameInOut);
		if (f.is_open())
		{
			//this->emptyRepo();
			string linie;
			string delim = " ";
			while (getline(f, linie))
			{
				int pos = linie.find(delim);
				int id = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string nume = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string email = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				int grad = stoi(linie.substr(0));

				Angajat* a = new Angajat(id,nume,email,grad);
				this->container->addElem(a);
			}
		}
	}
};