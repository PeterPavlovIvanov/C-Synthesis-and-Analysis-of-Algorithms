#pragma once
#include "TypeDefs.h"

class ProductTypesBusinessLogic
{
public:
	ProductTypesBusinessLogic();
	~ProductTypesBusinessLogic();

public:
	BOOL SelectAll(ProductTypesArray & productTypesArray);

	BOOL Insert(PRODUCT_TYPES& productType);

	BOOL DeleteWhereID(int id);

	BOOL UpdateByID(PRODUCT_TYPES& productType);

	BOOL SelectWhereID(int id, PRODUCT_TYPES& pt, ModelsArray& modelsArray, CategoriesArray& categoriesArray, BrandsArray& brandsArray);
};