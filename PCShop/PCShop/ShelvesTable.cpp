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
}
BOOL ShelvesTable::SelectAllByRackID(ShelvesArray & shelvesArray, int rackID)
{
	HRESULT hResult = S_OK;
	CString strQuery;
	strQuery.Format(_T("SELECT * FROM %s WHERE RACK_ID = %d"), tableName, rackID);

	if (FAILED(OpenSession()))
		return FALSE;

	if (FAILED(ExecuteQuery(strQuery)))
	{
		Close();
		return FALSE;
	}

	while (true)
	{
		hResult = MoveNext();
		if (hResult == S_OK)
		{
			Trim();
			SHELVES* shelf = new SHELVES();
			*shelf = GetRowSet();

			shelvesArray.Add(shelf);
		}
		else if (hResult == DB_S_ENDOFROWSET)
		{
			break;
		}
		else
		{
			CloseSession();
			Close();
			return FALSE;
		}
	}
	Close();
	return TRUE;
};
