#include "BaseObject.h"
#include "StandartInclude.h"

int BaseObject::numberOfObjects = 0;

BaseObject::BaseObject()
{
	id = numberOfObjects;
	numberOfObjects++;
}

int BaseObject::getId()
{
	return id;
}