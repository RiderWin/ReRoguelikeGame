#include "BaseObject.h"

int BaseObject::numberOfObjects = 0;

BaseObject::BaseObject()
{
	id = numberOfObjects;
	numberOfObjects++;
	flag = BASE_OBJ;
}

int BaseObject::getId()
{
	return id;
}

int BaseObject::getFlag()
{
	return flag;
}