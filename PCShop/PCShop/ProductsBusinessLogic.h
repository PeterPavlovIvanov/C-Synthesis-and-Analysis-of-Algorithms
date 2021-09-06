#pragma once
#include "TypeDefs.h"

class ProductsBusinessLogic
{
public:
	ProductsBusinessLogic();
	~ProductsBusinessLogic();

public:
	BOOL SelectAll(ProductsArray & productsArray);

	BOOL Insert(PRODUCTS & product, PRODUCT_TYPES & productType);

	BOOL DeleteWhereID(int id);

	BOOL UpdateByID(PRODUCTS & product);

	BOOL SelectWhereID(int id, PRODUCTS & product, PRODUCT_TYPES& productType, ModelsArray& modelsArray, CategoriesArray & categoriesArray, BrandsArray & brandsArray, ShelvesArray& shelvesArray, RacksArray& racksArray);
};