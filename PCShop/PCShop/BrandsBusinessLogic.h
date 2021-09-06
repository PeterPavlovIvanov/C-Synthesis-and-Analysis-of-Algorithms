#pragma once
#include "TypeDefs.h"

class BrandsBusinessLogic
{
public:
	BrandsBusinessLogic();
	~BrandsBusinessLogic();

public:
	BOOL SelectAll(BrandsArray& brandsArray);

	BOOL Insert(BRANDS& brand);

	BOOL DeleteWhereID(int id);

	BOOL UpdateByID(BRANDS& brand);

	BOOL SelectWhereID(int id, BRANDS& brand, ModelsArray& modelsArray);
};