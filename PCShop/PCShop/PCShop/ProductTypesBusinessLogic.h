#pragma once
#include "TypeDefs.h"

class ProductTypesBusinessLogic
{
public:
	ProductTypesBusinessLogic();
	~ProductTypesBusinessLogic();

public:
	BOOL SelectAll(ProductTypesArray & productTypesArray);

	BOOL Insert(ProductTypeDTO & productTypeDTO);

	BOOL DeleteWhereID(int id);

	BOOL UpdateByID(ProductTypeDTO & productTypeDTO);

	BOOL SelectWhereID(int id, ProductTypeDTO & productTypeDTO);
};