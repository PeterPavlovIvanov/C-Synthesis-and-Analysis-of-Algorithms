#pragma once
#include "TypeDefs.h"
#include "ProductDTO.h"

class ProductsBusinessLogic
{
public:
	ProductsBusinessLogic();
	~ProductsBusinessLogic();

public:
	BOOL SelectAll(ProductsArray & productsArray);

	BOOL Insert(ProductDTO & productDTO);

	BOOL DeleteWhereID(int id);

	BOOL UpdateByID(ProductDTO & productDTO);

	BOOL SelectWhereID(int id, ProductDTO & productDTO);
};