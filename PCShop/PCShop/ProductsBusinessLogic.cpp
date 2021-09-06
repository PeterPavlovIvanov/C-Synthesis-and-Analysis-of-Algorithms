#include "stdafx.h"
#include "DBConnection.h"
#include "ProductsBusinessLogic.h"
#include "afxwin.h"

#include "BrandsTable.h"
#include "ProductTypes.h"
#include "ProductsTable.h"
#include "CategoriesTable.h"
#include "ModelsTable.h"
#include "ProductsTable.h"
#include "ProductTypesTable.h"
#include "ShelvesTable.h"
#include "RacksTable.h"

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

	
	// Commit-ваме транзакцията
	if (FAILED(session.Commit()))
		return FALSE;

	// Затваряме сесията
	session.Close();
	return TRUE;
}

BOOL ProductsBusinessLogic::Insert(PRODUCTS & product, PRODUCT_TYPES & productType)
{
	CSession session;

	// Отваряме сесия
	if (session.Open(DBConnection::GetInstance().GetDataSource()))
		return FALSE;

	// Започваме транзакция
	if (FAILED(session.StartTransaction()))
		return FALSE;

	// Check if product type exists in DB
	ProductTypesTable productTypesTable(&session);
	
	if (FAILED(productTypesTable.SelectByAll(productType)))
		return FALSE;

	if (productType.ID == 0)
		if (FAILED(productTypesTable.Insert(productType)))
			return FALSE;

	// Assign product type ID to the product
	product.productTypeID = productType.ID;

	// Check if the shelf has enough space
	SHELVES shelf;
	ShelvesTable shelvesTable(&session);
	shelvesTable.SelectWhereID(product.shelfID, shelf);
	
	if (shelf.capacity - shelf.spaceTaken < productType.productSize)
	{
		CString message;
		message.Format(_T("Shelf: %s does not have enough space for %s!"), shelf.shelfName, productType.productName);
		AfxMessageBox(message);
		return FALSE;
	}

	// Insert the product in the DB
	ProductsTable productsTable(&session);

	if (FAILED(productsTable.Insert(product)))
		return FALSE;

	// Update the shelf's storage data
	shelf.spaceTaken += productType.productSize;
	shelf.productCount += 1;

	if (FAILED(shelvesTable.UpdateWhereID(product.shelfID, shelf)))
		return FALSE;

	// Update product type's quantity
	productType.quantity += 1;
	if (FAILED(productTypesTable.UpdateWhereID(productType.ID, productType)))
		return FALSE;

	// Commit-ваме транзакцията
	if (FAILED(session.Commit()))
		return FALSE;

	// Затваряме сесията
	session.Close();

	return TRUE;
}

BOOL ProductsBusinessLogic::DeleteWhereID(int id)
{
	CSession session;

	// Отваряме сесия
	if (session.Open(DBConnection::GetInstance().GetDataSource()))
		return FALSE;

	// Започваме транзакция
	if (FAILED(session.StartTransaction()))
		return FALSE;

	// delete product and keep product type id
	ProductsTable productsTable(&session);
	PRODUCTS product;

	if (FAILED(productsTable.SelectWhereID(id, product)))
		return FALSE;

	if (FAILED(productsTable.DeleteWhereID(id)))
		return FALSE;

	// update product type's quantity
	ProductTypesTable productTypesTable(&session);
	PRODUCT_TYPES productType;

	if (FAILED(productTypesTable.SelectWhereID(product.productTypeID, productType)))
		return FALSE;

	productType.quantity -= 1;

	if (FAILED(productTypesTable.UpdateWhereID(productType.ID, productType)))
		return FALSE;

	// update shelves data
	ShelvesTable shelvesTable(&session);
	SHELVES shelf;

	if (FAILED(shelvesTable.SelectWhereID(product.shelfID, shelf)))
		return FALSE;

	shelf.productCount -= 1;
	shelf.spaceTaken -= productType.productSize;

	if (FAILED(shelvesTable.UpdateWhereID(shelf.ID, shelf)))
		return FALSE;

	// Commit-ваме транзакцията
	if (FAILED(session.Commit()))
		return FALSE;

	// Затваряме сесията
	session.Close();

	return TRUE;
}

BOOL ProductsBusinessLogic::UpdateByID(PRODUCTS & product)
{
	ProductsTable productsTable;

	if (FAILED(productsTable.UpdateWhereID(product.serialID, product)))
		return FALSE;

	return TRUE;
}

BOOL ProductsBusinessLogic::SelectWhereID(int id, PRODUCTS & product, PRODUCT_TYPES& productType, ModelsArray& modelsArray, CategoriesArray & categoriesArray, BrandsArray & brandsArray, ShelvesArray& shelvesArray, RacksArray& racksArray)
{
	CSession session;

	// Отваряме сесия
	if (session.Open(DBConnection::GetInstance().GetDataSource()))
		return FALSE;

	// Започваме транзакция
	if (FAILED(session.StartTransaction()))
		return FALSE;

	ProductsTable productsTable(&session);
	if (FAILED(productsTable.SelectWhereID(id, product)))
		return FALSE;

	ProductTypesTable productTypesTable(&session);
	if (FAILED(productTypesTable.SelectWhereID(product.productTypeID, productType)))
		return FALSE;

	CategoriesTable categoriesTable(&session);
	if (FAILED(categoriesTable.SelectAll(categoriesArray)))
		return FALSE;

	ModelsTable modelsTable(&session);
	if (FAILED(modelsTable.SelectAll(modelsArray)))
		return FALSE;
 
	BrandsTable brandsTable(&session);
	if (FAILED(brandsTable.SelectAll(brandsArray)))
		return FALSE;

	ShelvesTable shelvesTable(&session);
	if (FAILED(shelvesTable.SelectAll(shelvesArray)))
		return FALSE;

	RacksTable racksTable(&session);
	if (FAILED(racksTable.SelectAll(racksArray)))
		return FALSE;

	// Commit-ваме транзакцията
	if (FAILED(session.Commit()))
		return FALSE;

	// Затваряме сесията
	session.Close();
	return TRUE;
}
