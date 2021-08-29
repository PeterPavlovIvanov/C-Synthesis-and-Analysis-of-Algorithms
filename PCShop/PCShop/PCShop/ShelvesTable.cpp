#include "stdafx.h"
#include "ShelvesTable.h"

ShelvesTable::ShelvesTable()
{
	tableName.Format(_T("SHELVES"));
}

ShelvesTable::ShelvesTable(CSession* session) : AbstractTable(session)
{
	tableName.Format(_T("SHELVES"));
}

ShelvesTable::~ShelvesTable()
{
}

void ShelvesTable::Trim()
{
	wchar_t cSpace = ' '; 
	CString shelfName(shelf.shelfName);

	int nIndex = shelfName.GetLength() - FIX_TO_LAST_INDEX;
	//премахваме space-овете от името на марката
	while (shelf.shelfName[nIndex] == cSpace) {
		shelf.shelfName[nIndex] = NULL;
		nIndex--;
	}
}

SHELVES& ShelvesTable::GetRowSet()
{
	return shelf;
};