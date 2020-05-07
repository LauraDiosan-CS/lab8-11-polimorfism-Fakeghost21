#include <iostream>
#include "ArrayContainer.h"
#include "Angajat.h"
#include "RepoFile.h"
#include "Medicament.h"
#include "RepoFileTXTangajat.h"
#include "RepoCSVangajat.h"
#include "RepoTXTmedicament.h"
#include "TestAngajat.h"
#include "TestRepo.h"
#include <assert.h>

int main()
{
	//IContainer* c = new ArrayContainer(100);
	//IContainer* cm = new ArrayContainer(100);
	//IContainer* cu = new ArrayContainer(100);
	//RepoGeneral r7(cu);
	//RepoGeneral r2(c);
	//RepoGeneral r(c,"AngajatOut.txt", "AngajatiLoad.txt");
	//RepoTXTangajat r(c, "AngajatOut.txt");
	//RepoTXTmedicament rm(cm, "MedicamentOut.txt");
	//Angajat* ang = new Angajat(12, "sdhsdgav", "wdf", 30000);
	//Angajat* ang2 = new Angajat(1200, "sd", "wtf", 30000);
	//Medicament* m = new Medicament(12, "surex", 1000000, 1);
	//Medicament* m2 = new Medicament(1903, "paracetamol", 104000, 0);
	//r.add(ang);
	//r.add(ang2);
	//ang = ang2;
	//cout << ang->toString(" ");
	//r.del(r.getElemPos(0));
	//rm.add(m);
	//rm.add(m2);
	//cout << r7.getSize() << endl;
	//assert(r7.getSize() == 0);
	TestAll trm;
	trm.Testall();
	TestAngajat t;
	t.testAll();
	//r.update(ang2, ang);
	//cout << r.getALL()[2]->toString(" ");
	/*c->addElem(ang);
	string s = c->getElemPos(0)->toString(",");
	cout << s << endl;
	c->updateElem(c->getElemPos(0), ang2);
	string s2 = c->getElemPos(0)->toString(" ");
	cout << s2<< endl;
	string s3 = c->getALL()[0]->toString(",");
	cout << s3 << endl;
	cout << c->getSize() << endl;
	c->removeElem(ang2);
	cout << c->getSize() << endl;*/
	/*r.add(ang);
	string s4 = c->getElemPos(0)->toString();
	cout << s4 << endl;
	r.update(ang, ang2);
	string s5 = c->getElemPos(0)->toString();
	cout << s5 << endl;
	r.del(ang);
	cout << r.getSize() << endl;
	r2.add(m);
	string s6 = c->getElemPos(1)->toString();
	cout << s6 << endl;*/

	return 0;
}

