#pragma once
#include "AbstractTable.h"
#include "Categories.h"
#include "TypeDefs.h"

class CategoriesAccessor
{
protected:
	CATEGORIES category;

	BEGIN_ACCESSOR_MAP(CategoriesAccessor, 2)
		BEGIN_ACCESSOR(0, true)
		COLUMN_ENTRY(1, category.ID)
		END_ACCESSOR()

		BEGIN_ACCESSOR(1, true)
		COLUMN_ENTRY(2, category.categoryName)
		END_ACCESSOR()
	END_ACCESSOR_MAP()
};

class CategoriesTable : public AbstractTable<CategoriesAccessor, CATEGORIES>
{
public:
	CategoriesTable();
	CategoriesTable(CSession* session);
	~CategoriesTable();

	void Trim() override;

	CATEGORIES & GetRowSet();
};