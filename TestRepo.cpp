#include <iostream>
#include "ArrayContainer.h"
#include "Angajat.h"
#include "RepoFile.h"
#include "Medicament.h"
#include "RepoFileTXTangajat.h"
#include "RepoCSVangajat.h"
#include "RepoTXTmedicament.h"
#include "TestRepo.h"
#include <assert.h>

void TestAll::Testall()
{
	testGetSize();
	testGetAll();
	testAdd();
	testDel();
	testUpdate();
	testLoadFromFile();
}

void TestAll::testGetSize()
{
	IContainer* cu = new ArrayContainer(100);
	RepoGeneral r7(cu);
	assert(r7.getSize() == 0);
}

void TestAll::testGetAll()
{	
	IContainer* cu = new ArrayContainer(100);
	RepoGeneral r7(cu);
	Angajat* ang = new Angajat(12, "sdhsdgav", "wdf", 30000);
	Angajat* ang2 = new Angajat(1200, "sd", "wtf", 30000);
	r7.add(ang);
	r7.add(ang2);
	assert(r7.getElemPos(0)->operator==(r7.getALL()[0]));
	assert(r7.getElemPos(1)->operator==(r7.getALL()[1]));
}

void TestAll::testAdd()
{
	IContainer* cu = new ArrayContainer(100);
	RepoGeneral r7(cu);
	Angajat* ang = new Angajat(12, "sdhsdgav", "wdf", 30000);
	Angajat* ang2 = new Angajat(1200, "sd", "wtf", 30000);
	r7.add(ang);
	r7.add(ang2);
	assert(r7.getSize() == 2);
}

void TestAll::testDel()
{
	IContainer* cu = new ArrayContainer(100);
	RepoGeneral r7(cu);
	Angajat* ang = new Angajat(12, "sdhsdgav", "wdf", 30000);
	Angajat* ang2 = new Angajat(1200, "sd", "wtf", 30000);
	r7.add(ang);
	r7.add(ang2);
	r7.del(ang);
	assert(r7.getSize() == 1);
	assert(r7.getElemPos(0)->operator==(ang2));
	r7.del(ang2);
	assert(r7.getSize() == 0);
}

void TestAll::testUpdate()
{
	IContainer* cu = new ArrayContainer(100);
	RepoGeneral r7(cu);
	Angajat* ang = new Angajat(12, "sdhsdgav", "wdf", 30000);
	Angajat* ang2 = new Angajat(1200, "sd", "wtf", 30000);
	r7.add(ang);
	r7.add(ang2);
	assert(r7.getElemPos(0)->operator==(ang));
	Angajat* ang3 = new Angajat(12, "Suceava", "Suceava@yahoo.com", 19876);
	r7.update(ang, ang3);
	assert(r7.getElemPos(0)->operator==(ang3));
}

void TestAll::testLoadFromFile()
{
	IContainer* cu = new ArrayContainer(100);
	RepoTXTangajat r7(cu,"AngajatOut.txt");
	assert(r7.getSize() == 3);
	IContainer* cu2 = new ArrayContainer(100);
	RepoTXTmedicament r8(cu2, "MedicamentOut.txt");
	assert(r8.getSize() == 2);
	IContainer* cu3 = new ArrayContainer(100);
	RepoTXTmedicament r9(cu3, "MedicamentOut.csv");
	assert(r9.getSize() == 3);
	IContainer* cu4 = new ArrayContainer(100);
	RepoTXTmedicament r10(cu4, "AngajatOut.csv");
	assert(r10.getSize() == 5);
}
