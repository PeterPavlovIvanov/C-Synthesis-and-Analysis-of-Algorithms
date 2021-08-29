#include "stdafx.h"
#include "CategoriesBusinessLogic.h"
#include "CategoriesTable.h"

CategoriesBusinessLogic::CategoriesBusinessLogic()
{
}

CategoriesBusinessLogic::~CategoriesBusinessLogic()
{
}

BOOL CategoriesBusinessLogic::SelectAll(CategoriesArray & categoriesArray)
{
	CategoriesTable categoriesTable;

	BOOL hResult = categoriesTable.SelectAll(categoriesArray);

	return hResult;
}

BOOL CategoriesBusinessLogic::Insert(CATEGORIES & category)
{
	CategoriesTable categoriesTable;

	BOOL hResult = categoriesTable.Insert(category);

	return hResult;
}

BOOL CategoriesBusinessLogic::DeleteWhereID(int id)
{
	CategoriesTable categoriesTable;

	BOOL hResult = categoriesTable.DeleteWhereID(id);

	return hResult;
}

BOOL CategoriesBusinessLogic::UpdateByID(CATEGORIES & category)
{
	CategoriesTable categoriesTable;

	BOOL hResult = categoriesTable.UpdateWhereID(category.ID, category);

	return hResult;
}

BOOL CategoriesBusinessLogic::SelectWhereID(int id, CATEGORIES & category)
{
	CategoriesTable categoriesTable;

	BOOL hResult = categoriesTable.SelectWhereID(id, category);

	return hResult;
}
