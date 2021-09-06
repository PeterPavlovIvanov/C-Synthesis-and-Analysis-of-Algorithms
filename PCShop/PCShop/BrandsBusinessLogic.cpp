#include "stdafx.h"
#include "BrandsBusinessLogic.h"
#include "BrandsTable.h"
#include "ModelsTable.h"

BrandsBusinessLogic::BrandsBusinessLogic()
{
}

BrandsBusinessLogic::~BrandsBusinessLogic()
{
}

BOOL BrandsBusinessLogic::SelectAll(BrandsArray & brandsArray)
{
	BrandsTable brandsTable;

	BOOL hResult = brandsTable.SelectAll(brandsArray);

	return hResult;
}

BOOL BrandsBusinessLogic::Insert(BRANDS & brand)
{
	BrandsTable brandsTable;

	BOOL hResult = brandsTable.Insert(brand);

	return hResult;
}

BOOL BrandsBusinessLogic::DeleteWhereID(int id)
{
	BrandsTable brandsTable;

	BOOL hResult = brandsTable.DeleteWhereID(id);

	return hResult;
}

BOOL BrandsBusinessLogic::UpdateByID(BRANDS & brand)
{
	BrandsTable brandsTable;

	BOOL hResult = brandsTable.UpdateWhereID(brand.ID, brand);

	return hResult;
}

BOOL BrandsBusinessLogic::SelectWhereID(int id, BRANDS & brand, ModelsArray& modelsArray)
{
	CSession session;

	// Отваряме сесия
	if (session.Open(DBConnection::GetInstance().GetDataSource()))
		return FALSE;

	// Започваме транзакция
	if (FAILED(session.StartTransaction()))
		return FALSE;

	BrandsTable brandsTable(&session);

	if (!brandsTable.SelectWhereID(id, brand))
		return FALSE;

	ModelsTable modelsTable(&session);

	if (!modelsTable.SelectAllByBrandID(id, modelsArray))
		return FALSE;

	// Commit-ваме транзакцията
	if (FAILED(session.Commit()))
		return FALSE;

	// Затваряме сесията
	session.Close();

	return TRUE;
}
