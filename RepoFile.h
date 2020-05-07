#pragma once
#include "ArrayContainer.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class RepoGeneral {
protected:
	IContainer* container;
public:
	RepoGeneral(IContainer* e)
	{
		this->container = e;
	}

	~RepoGeneral()
	{
	}
	
	virtual IE** getALL()
	{
		return this->container->getALL();
	}

	virtual IE* getElemPos(int pos) {
		return this->container->getElemPos(pos);
	}

	virtual void add(IE* e)
	{
		this->container->addElem(e);
	}

	virtual void del(IE* e)
	{
		this->container->removeElem(e);
	}

	virtual int getSize()
	{
		return this->container->getSize();
	}

	virtual void update(IE* oldElem, IE* newElem)
	{
		this->container->updateElem(oldElem,newElem);
	}
	
};