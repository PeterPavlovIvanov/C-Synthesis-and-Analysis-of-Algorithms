#pragma once
#include "TypeDefs.h"

class CategoriesBusinessLogic
{
public:
	CategoriesBusinessLogic();
	~CategoriesBusinessLogic();

public:
	BOOL SelectAll(CategoriesArray& categoriesArray);

	BOOL Insert(CATEGORIES& category);

	BOOL DeleteWhereID(int id);

	BOOL UpdateByID(CATEGORIES& category);

	BOOL SelectWhereID(int id, CATEGORIES& category);
};