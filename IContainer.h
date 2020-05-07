#ifndef ICONTAINER_H
#define ICONTAINER_H

#include "ObjectInterface.h"
#include "Iterator.h"

class IContainer {
public:
	virtual void addElem(IE*) = 0;
	virtual void removeElem(IE*) = 0;
	virtual void updateElem(IE* oldElem,IE* newElem) = 0;
	virtual void empty() = 0;
	virtual int getSize() = 0;
	virtual bool contains(IE*) = 0;
	virtual IE** getALL() = 0;

	virtual IE* getElemPos(int pos) = 0;

	friend class IIterator;
	virtual IIterator* getIterator() = 0;

	virtual ~IContainer() {};
};
#endif