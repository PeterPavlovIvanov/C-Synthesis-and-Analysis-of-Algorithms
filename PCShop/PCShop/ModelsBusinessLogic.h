#pragma once
#include "TypeDefs.h"

class ModelsBusinessLogic
{
public:
	ModelsBusinessLogic();
	~ModelsBusinessLogic();

public:
	BOOL SelectAll(ModelsArray& modelsArray);

	BOOL Insert(MODELS& model, BRANDS& brand);

	BOOL DeleteWhereID(int id);

	BOOL UpdateByID(MODELS& model);

	BOOL SelectWhereID(int id, MODELS& model);
};