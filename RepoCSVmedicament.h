#pragma once
#include "RepoFile.h"
#include "Medicament.h"

class RepoCSVmedicament : public RepoGeneral {
private:
	string filenameInOut;
public:
	RepoCSVmedicament(IContainer* e, string in, string out) : RepoGeneral(e)
	{
		this->filenameInOut = in;
		this->loadFromFile();
	}

	~RepoCSVmedicament() {

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
		RepoGeneral::update(oldElem, newElem);
		this->saveToFile();
	}

	int getSize() {
		return RepoGeneral::getSize();
	}

	void saveToFile() {
		ofstream f(this->filenameInOut);
		string delim = ",";
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
			string delim = ",";
			while (getline(f, linie))
			{
				int pos = linie.find(delim);
				int id = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string producator = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int stoc = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				int reteta = stoi(linie.substr(0));

				Medicament* m = new Medicament(id, producator, stoc, reteta);
				this->container->addElem(m);
			}
		}
	}
};