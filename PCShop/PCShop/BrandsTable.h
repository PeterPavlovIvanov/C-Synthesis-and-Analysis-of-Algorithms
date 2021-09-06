#pragma once
#include "AbstractTable.h"
#include "Brands.h"
#include "TypeDefs.h"

class BrandsAccessor
{
protected:
	BRANDS brand;

	BEGIN_ACCESSOR_MAP(BrandsAccessor, 2)
		BEGIN_ACCESSOR(0, true)
		COLUMN_ENTRY(1, brand.ID)
		END_ACCESSOR()

		BEGIN_ACCESSOR(1, true)
		COLUMN_ENTRY(2, brand.brandName)
		END_ACCESSOR()
	END_ACCESSOR_MAP()
};

class BrandsTable : public AbstractTable<BrandsAccessor, BRANDS>
{
public:
	BrandsTable();
	BrandsTable(CSession* session);
	~BrandsTable();

	void Trim() override;

	BRANDS & GetRowSet();
};