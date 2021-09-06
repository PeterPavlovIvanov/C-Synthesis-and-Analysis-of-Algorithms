#pragma once
#include "AbstractTable.h"
#include "Racks.h"
#include "TypeDefs.h"
class RacksAccessor
{
protected:
	RACKS rack;

	BEGIN_ACCESSOR_MAP(RacksAccessor, 2)
		BEGIN_ACCESSOR(0, true)
			COLUMN_ENTRY(1, rack.ID)
		END_ACCESSOR()

		BEGIN_ACCESSOR(1, true)
			COLUMN_ENTRY(2, rack.rackName)
		END_ACCESSOR()
	END_ACCESSOR_MAP()
};

class RacksTable : public AbstractTable<RacksAccessor, RACKS>
{
public:
	RacksTable();
	RacksTable(CSession* session);
	~RacksTable();

	void Trim() override;

	RACKS & GetRowSet();
};