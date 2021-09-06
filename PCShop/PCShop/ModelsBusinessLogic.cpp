#include "stdafx.h"
#include "ModelsBusinessLogic.h"
#include "ModelsTable.h"

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

BOOL ModelsBusinessLogic::Insert(MODELS & model)
{
	ModelsTable modelsTable;

	BOOL hResult = modelsTable.Insert(model);

	return hResult;
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
