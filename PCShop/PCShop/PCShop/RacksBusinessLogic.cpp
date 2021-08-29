#include "stdafx.h"
#include "RacksBusinessLogic.h"
#include "RacksTable.h"

RacksBusinessLogic::RacksBusinessLogic()
{
}

RacksBusinessLogic::~RacksBusinessLogic()
{
}

BOOL RacksBusinessLogic::SelectAll(RacksArray & racksArray)
{
	RacksTable racksTable;

	BOOL hResult = racksTable.SelectAll(racksArray);

	return hResult;
}

BOOL RacksBusinessLogic::Insert(RACKS & rack)
{
	RacksTable racksTable;

	BOOL hResult = racksTable.Insert(rack);

	return hResult;
}

BOOL RacksBusinessLogic::DeleteWhereID(int id)
{
	RacksTable racksTable;

	BOOL hResult = racksTable.DeleteWhereID(id);

	return hResult;
}

BOOL RacksBusinessLogic::UpdateByID(RACKS & rack)
{
	RacksTable racksTable;

	BOOL hResult = racksTable.UpdateWhereID(rack.ID, rack);

	return hResult;
}

BOOL RacksBusinessLogic::SelectWhereID(int id, RACKS & rack)
{
	RacksTable racksTable;

	BOOL hResult = racksTable.SelectWhereID(id, rack);

	return hResult;
}
