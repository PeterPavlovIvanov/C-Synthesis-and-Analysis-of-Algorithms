#include "stdafx.h"
#include "BrandsBusinessLogic.h"
#include "BrandsTable.h"

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

BOOL BrandsBusinessLogic::SelectWhereID(int id, BRANDS & brand)
{
	BrandsTable brandsTable;

	BOOL hResult = brandsTable.SelectWhereID(id, brand);

	return hResult;
}
