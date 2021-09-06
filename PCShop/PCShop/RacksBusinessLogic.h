#pragma once
#include "TypeDefs.h"

class RacksBusinessLogic
{
public:
	RacksBusinessLogic();
	~RacksBusinessLogic();

public:
	BOOL SelectAll(RacksArray& racksArray);
	
	BOOL Insert(RACKS& rack);

	BOOL DeleteWhereID(int id);
	
	BOOL UpdateByID(RACKS& rack);

	BOOL SelectWhereID(int id, RACKS& rack);

	BOOL SelectAllByRackID(ShelvesArray& shelvesArray, int rackID);
};