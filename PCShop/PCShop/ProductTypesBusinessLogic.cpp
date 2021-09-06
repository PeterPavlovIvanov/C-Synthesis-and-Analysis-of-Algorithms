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

	// Commit-ваме транзакцията
	if (FAILED(session.Commit()))
		return FALSE;

	// Затваряме сесията
	session.Close();
	return TRUE;
}

BOOL ProductTypesBusinessLogic::Insert(PRODUCT_TYPES& productType)
{
	ProductTypesTable productTypesTable;

	if (FAILED(productTypesTable.Insert(productType)))
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

BOOL ProductTypesBusinessLogic::UpdateByID(PRODUCT_TYPES& productType)
{
	ProductTypesTable productTypesTable;

	if (FAILED(productTypesTable.UpdateWhereID(productType.ID, productType)))
		return FALSE;

	return TRUE;
}

BOOL ProductTypesBusinessLogic::SelectWhereID(int id, PRODUCT_TYPES& pt, ModelsArray& modelsArray, CategoriesArray& categoriesArray, BrandsArray& brandsArray)
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
	if (FAILED(productTypesTable.SelectWhereID(id, pt)))
		return FALSE;

	// CATEGORY   
	CategoriesTable categoriesTable(&session);
	if (FAILED(categoriesTable.SelectAll(categoriesArray)))
		return FALSE;

	// MODEL
	ModelsTable modelsTable(&session);
	if (FAILED(modelsTable.SelectAll(modelsArray)))
		return FALSE;

	// BRAND 
	BrandsTable brandsTable(&session);
	if (FAILED(brandsTable.SelectAll(brandsArray)))
		return FALSE;

	// Commit-ваме транзакцията
	if (FAILED(session.Commit()))
		return FALSE;

	// Затваряме сесията
	session.Close();
	return TRUE;
}
