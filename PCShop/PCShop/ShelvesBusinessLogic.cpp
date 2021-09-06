#include "stdafx.h"
#include "ShelvesBusinessLogic.h"
#include "ShelvesTable.h"

ShelvesBusinessLogic::ShelvesBusinessLogic()
{
}

ShelvesBusinessLogic::~ShelvesBusinessLogic()
{
}

BOOL ShelvesBusinessLogic::SelectAll(ShelvesArray & shelvesArray)
{
	ShelvesTable shelvesTable;

	BOOL hResult = shelvesTable.SelectAll(shelvesArray);

	return hResult;
}

BOOL ShelvesBusinessLogic::Insert(SHELVES & shelf)
{
	ShelvesTable shelvesTable;

	BOOL hResult = shelvesTable.Insert(shelf);

	return hResult;
}

BOOL ShelvesBusinessLogic::DeleteWhereID(int id)
{
	ShelvesTable shelvesTable;

	BOOL hResult = shelvesTable.DeleteWhereID(id);

	return hResult;
}

BOOL ShelvesBusinessLogic::UpdateByID(SHELVES & shelf)
{
	ShelvesTable shelvesTable;

	BOOL hResult = shelvesTable.UpdateWhereID(shelf.ID, shelf);

	return hResult;
}

BOOL ShelvesBusinessLogic::SelectWhereID(int id, SHELVES & shelf)
{
	ShelvesTable shelvesTable;

	BOOL hResult = shelvesTable.SelectWhereID(id, shelf);

	return hResult;
}
