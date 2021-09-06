#pragma once
#include "AbstractTable.h"
#include "Models.h"
#include "TypeDefs.h"

class ModelsAccessor
{
protected:
	MODELS model;

	BEGIN_ACCESSOR_MAP(ModelsAccessor, 2)
		BEGIN_ACCESSOR(0, true)
		COLUMN_ENTRY(1, model.ID)
		END_ACCESSOR()

		BEGIN_ACCESSOR(1, true)
		COLUMN_ENTRY(2, model.modelName)
		COLUMN_ENTRY(3, model.brandID)
		END_ACCESSOR()
	END_ACCESSOR_MAP()
};

class ModelsTable : public AbstractTable<ModelsAccessor, MODELS>
{
public:
	ModelsTable();
	ModelsTable(CSession* session);
	~ModelsTable();

	void Trim() override;

	BOOL SelectAllByBrandID(long brandID, ModelsArray& modelsArray);

	MODELS & GetRowSet();
};