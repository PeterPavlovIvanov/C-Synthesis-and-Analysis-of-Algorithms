#include "stdafx.h"
#include "DBConnection.h"
#include "ProductTypesBusinessLogic.h"
#include "BrandsTable.h"
#include "ProductTypes.h"
#include "ProductTypesTable.h"
#include "CategoriesTable.h"
#include "ModelsTable.h"

ProductTypesBusinessLogic::ProductTypesBusinessLogic()
{
}

ProductTypesBusinessLogic::~ProductTypesBusinessLogic()
{
}

BOOL ProductTypesBusinessLogic::SelectAll(ProductTypesArray & productTypesArray)
{
	CSession session;

	// Отваряме сесия
	if (session.Open(DBConnection::GetInstance().GetDataSource()))
		return FALSE;

	// Започваме транзакция
	if (FAILED(session.StartTransaction()))
		return FALSE;

	// all PRODUCT_TYPES
	ProductTypesTable productTypesTable(&session);
	if (FAILED(productTypesTable.SelectAll(productTypesArray)))
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

	// assign entities to productTypeDTOs
	//for (int i = 0; i < productTypesArray.GetCount(); i++)
	//{
	//	PRODUCT_TYPES* currentPT;
	//	currentPT = productTypesArray.GetAt(i);
	//	ProductTypeDTO ptDTO(currentPT);

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

	//	productTypesArray.Add(&(ptDTO.productType));
	//}

	// Commit-ваме транзакцията
	if (FAILED(session.Commit()))
		return FALSE;

	// Затваряме сесията
	session.Close();
	return TRUE;
}

BOOL ProductTypesBusinessLogic::Insert(ProductTypeDTO & productTypeDTO)
{
	ProductTypesTable productTypesTable;

	if (FAILED(productTypesTable.Insert(productTypeDTO.productType)))
		return FALSE;

	return TRUE;
}

BOOL ProductTypesBusinessLogic::DeleteWhereID(int id)
{
	ProductTypesTable productTypesTable;

	if (FAILED(productTypesTable.DeleteWhereID(id)))
		return FALSE;

	return TRUE;
}

BOOL ProductTypesBusinessLogic::UpdateByID(ProductTypeDTO & productTypeDTO)
{
	ProductTypesTable productTypesTable;

	if (FAILED(productTypesTable.UpdateWhereID(productTypeDTO.productType.ID, productTypeDTO.productType)))
		return FALSE;

	return TRUE;
}

BOOL ProductTypesBusinessLogic::SelectWhereID(int id, ProductTypeDTO & productTypeDTO)
{
	CSession session;

	// Отваряме сесия
	if (session.Open(DBConnection::GetInstance().GetDataSource()))
		return FALSE;

	// Започваме транзакция
	if (FAILED(session.StartTransaction()))
		return FALSE;

	// PRODUCT_TYPE
	ProductTypesTable productTypesTable(&session);
	if (FAILED(productTypesTable.SelectWhereID(id, productTypeDTO.productType)))
		return FALSE;

	// CATEGORY   
	CategoriesTable categoriesTable(&session);
	if (FAILED(categoriesTable.SelectWhereID(productTypeDTO.productType.categoryID, productTypeDTO.category)))
		return FALSE;

	// MODEL
	ModelsTable modelsTable(&session);
	if (FAILED(modelsTable.SelectWhereID(productTypeDTO.productType.modelID, productTypeDTO.model)))
		return FALSE;

	// BRAND 
	BrandsTable brandsTable(&session);
	if (FAILED(brandsTable.SelectWhereID(productTypeDTO.productType.brandID, productTypeDTO.brand)))
		return FALSE;

	// Commit-ваме транзакцията
	if (FAILED(session.Commit()))
		return FALSE;

	// Затваряме сесията
	session.Close();
	return TRUE;
}
