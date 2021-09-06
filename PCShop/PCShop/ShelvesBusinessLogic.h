#pragma once
#include "TypeDefs.h"
class ShelvesBusinessLogic
{
public:
	ShelvesBusinessLogic();
	~ShelvesBusinessLogic();

public:
	BOOL SelectAll(ShelvesArray& shelvesArray);

	BOOL Insert(SHELVES& shelf);

	BOOL DeleteWhereID(int id);

	BOOL UpdateByID(SHELVES& shelf);

	BOOL SelectWhereID(int id, SHELVES& shelf);
};