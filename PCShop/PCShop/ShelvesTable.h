#pragma once
#include "AbstractTable.h"
#include "Shelves.h"
#include "TypeDefs.h"
class ShelvesAccessor
{
protected:
	SHELVES shelf;

	BEGIN_ACCESSOR_MAP(ShelvesAccessor, 2)
		BEGIN_ACCESSOR(0, true)
		COLUMN_ENTRY(1, shelf.ID)
		END_ACCESSOR()

		BEGIN_ACCESSOR(1, true)
		COLUMN_ENTRY(2, shelf.shelfName)
		COLUMN_ENTRY(3, shelf.capacity)
		COLUMN_ENTRY(4, shelf.spaceTaken)
		COLUMN_ENTRY(5, shelf.rackID)
		COLUMN_ENTRY(6, shelf.productCount)
		END_ACCESSOR()
	END_ACCESSOR_MAP()
};

class ShelvesTable : public AbstractTable<ShelvesAccessor, SHELVES>
{
public:
	ShelvesTable();
	ShelvesTable(CSession* session);
	~ShelvesTable();

	void Trim() override;

	SHELVES & GetRowSet();

public:
	BOOL SelectAllByRackID(ShelvesArray& shelvesArray, int rackID);
};

