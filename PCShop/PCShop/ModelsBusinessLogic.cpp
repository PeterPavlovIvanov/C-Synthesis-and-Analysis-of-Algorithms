#include "stdafx.h"
#include "ModelsBusinessLogic.h"
#include "ModelsTable.h"
#include "brandsTable.h"

ModelsBusinessLogic::ModelsBusinessLogic()
{
}

ModelsBusinessLogic::~ModelsBusinessLogic()
{
}

BOOL ModelsBusinessLogic::SelectAll(ModelsArray & modelsArray)
{
	ModelsTable modelsTable;

	BOOL hResult = modelsTable.SelectAll(modelsArray);

	return hResult;
}

BOOL ModelsBusinessLogic::Insert(MODELS & model, BRANDS& brand)
{
	CSession session;

	// Отваряме сесия
	if (session.Open(DBConnection::GetInstance().GetDataSource()))
		return FALSE;

	// Започваме транзакция
	if (FAILED(session.StartTransaction()))
		return FALSE;

	BrandsTable brandsTable;
	BRANDS brandDB;

	if (!brandsTable.SelectWherebrandName(brand.brandName, brandDB))
		return FALSE;

	if (brandDB.ID == 0)
		if (!brandsTable.Insert(brand))
			return FALSE;

	model.brandID = brandDB.ID;
	ModelsTable modelsTable;

	if (!modelsTable.Insert(model))
		return FALSE;

	// Commit-ваме транзакцията
	if (FAILED(session.Commit()))
		return FALSE;

	// Затваряме сесията
	session.Close();

	return TRUE;
}

BOOL ModelsBusinessLogic::DeleteWhereID(int id)
{
	ModelsTable modelsTable;

	BOOL hResult = modelsTable.DeleteWhereID(id);

	return hResult;
}

BOOL ModelsBusinessLogic::UpdateByID(MODELS & model)
{
	ModelsTable modelsTable;

	BOOL hResult = modelsTable.UpdateWhereID(model.ID, model);

	return hResult;
}

BOOL ModelsBusinessLogic::SelectWhereID(int id, MODELS & model)
{
	ModelsTable modelsTable;

	BOOL hResult = modelsTable.SelectWhereID(id, model);

	return hResult;
}
