#include "stdafx.h"
#include "DBConnection.h"
#include "ProductsBusinessLogic.h"

#include "BrandsTable.h"
#include "ProductTypes.h"
#include "ProductsTable.h"
#include "CategoriesTable.h"
#include "ModelsTable.h"
#include "ProductsTable.h"

ProductsBusinessLogic::ProductsBusinessLogic()
{
}

ProductsBusinessLogic::~ProductsBusinessLogic()
{
}

BOOL ProductsBusinessLogic::SelectAll(ProductsArray & productsArray)
{
	CSession session;

	// Отваряме сесия
	if (session.Open(DBConnection::GetInstance().GetDataSource()))
		return FALSE;

	// Започваме транзакция
	if (FAILED(session.StartTransaction()))
		return FALSE;

	// all PRODUCT_TYPES
	ProductsTable productsTable(&session);
	if (FAILED(productsTable.SelectAll(productsArray)))
		return FALSE;

	//// all CATEGORIES
	//CategoriesTable categoriesTable(&session);
	//CategoriesArray categoriesArray;
	//if (FAILED(categoriesTable.SelectAll(categoriesArray)))
	//	return FALSE;

	//// all MODELS
	//ModelsTable modelsTable(&session);
	//ModelsArray modelsArray;
	//if (FAILED(modelsTable.SelectAll(modelsArray)))
	//	return FALSE;

	//// all BRANDS
	//BrandsTable brandsTable(&session);
	//BrandsArray brandsArray;
	//if (FAILED(brandsTable.SelectAll(brandsArray)))
	//	return FALSE;

	// assign entities to productDTOs
	//for (int i = 0; i < productsArray.GetCount(); i++)
	//{
	//	PRODUCT_TYPES* currentPT;
	//	currentPT = productsArray.GetAt(i);
	//	ProductDTO ptDTO(currentPT);

	//	// assign brand
	//	for (int b = 0; b < brandsArray.GetCount(); b++)
	//		if (brandsArray.GetAt(b)->ID == currentPT->brandID)
	//		{
	//			ptDTO.brand =*brandsArray.GetAt(b);
	//			break;
	//		}

	//	// assign model
	//	for (int m = 0; m < modelsArray.GetCount(); m++)
	//		if (modelsArray.GetAt(m)->ID == currentPT->modelID)
	//		{
	//			ptDTO.model = *modelsArray.GetAt(m);
	//			break;
	//		}

	//	// assign category
	//	for (int c = 0; c < categoriesArray.GetCount(); c++)
	//		if (categoriesArray.GetAt(c)->ID == currentPT->categoryID)
	//		{
	//			ptDTO.category = *categoriesArray.GetAt(c);
	//			break;
	//		}

	//	productsArray.Add(&(ptDTO.product));
	//}

	// Commit-ваме транзакцията
	if (FAILED(session.Commit()))
		return FALSE;

	// Затваряме сесията
	session.Close();
	return TRUE;
}

BOOL ProductsBusinessLogic::Insert(ProductDTO & productDTO)
{
	ProductsTable productsTable;

	if (FAILED(productsTable.Insert(productDTO.product)))
		return FALSE;

	return TRUE;
}

BOOL ProductsBusinessLogic::DeleteWhereID(int id)
{
	ProductsTable productsTable;

	if (FAILED(productsTable.DeleteWhereID(id)))
		return FALSE;

	return TRUE;
}

BOOL ProductsBusinessLogic::UpdateByID(ProductDTO & productDTO)
{
	ProductsTable productsTable;

	if (FAILED(productsTable.UpdateWhereID(productDTO.product.serialID, productDTO.product)))
		return FALSE;

	return TRUE;
}

BOOL ProductsBusinessLogic::SelectWhereID(int id, ProductDTO & productDTO)
{
	CSession session;

	// Отваряме сесия
	if (session.Open(DBConnection::GetInstance().GetDataSource()))
		return FALSE;

	// Започваме транзакция
	if (FAILED(session.StartTransaction()))
		return FALSE;

	// PRODUCT_TYPE
	ProductsTable productsTable(&session);
	if (FAILED(productsTable.SelectWhereID(id, productDTO.product)))
		return FALSE;

	//// CATEGORY   
	//CategoriesTable categoriesTable(&session);
	//if (FAILED(categoriesTable.SelectWhereID(productDTO.product.categoryID, productDTO.category)))
	//	return FALSE;

	//// MODEL
	//ModelsTable modelsTable(&session);
	//if (FAILED(modelsTable.SelectWhereID(productDTO.product.modelID, productDTO.model)))
	//	return FALSE;

	//// BRAND 
	//BrandsTable brandsTable(&session);
	//if (FAILED(brandsTable.SelectWhereID(productDTO.product.brandID, productDTO.brand)))
	//	return FALSE;

	// Commit-ваме транзакцията
	if (FAILED(session.Commit()))
		return FALSE;

	// Затваряме сесията
	session.Close();
	return TRUE;
}
