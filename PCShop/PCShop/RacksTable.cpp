#include "stdafx.h"
#include "RacksTable.h"

RacksTable::RacksTable()
{
	tableName.Format(_T("RACKS"));
}

RacksTable::RacksTable(CSession* session) : AbstractTable(session)
{
	tableName.Format(_T("RACKS"));
}

RacksTable::~RacksTable()
{
}

void RacksTable::Trim()
{
	wchar_t cSpace = ' ';
	CString rackName(rack.rackName);

	int nIndex = rackName.GetLength() - FIX_TO_LAST_INDEX;
	//премахваме space-овете от името на марката
	while (rack.rackName[nIndex] == cSpace) {
		rack.rackName[nIndex] = NULL;
		nIndex--;
	}
}

RACKS& RacksTable::GetRowSet()
{
	return rack;
}; 
