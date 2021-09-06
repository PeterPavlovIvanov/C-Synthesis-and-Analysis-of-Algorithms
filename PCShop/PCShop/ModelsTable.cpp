#include "stdafx.h"
#include "ModelsTable.h"

ModelsTable::ModelsTable()
{
	tableName.Format(_T("MODELS"));
}

ModelsTable::ModelsTable(CSession* session) : AbstractTable(session)
{
	tableName.Format(_T("MODELS"));
}

ModelsTable::~ModelsTable()
{
}

void ModelsTable::Trim()
{
	wchar_t cSpace = ' ';
	CString modelName(model.modelName);

	int nIndex = modelName.GetLength() - FIX_TO_LAST_INDEX;
	//премахваме space-овете от името на модела
	while (model.modelName[nIndex] == cSpace) {
		model.modelName[nIndex] = NULL;
		nIndex--;
	}
}

BOOL ModelsTable::SelectAllByBrandID(long brandID, ModelsArray & modelsArray)
{
	HRESULT hResult = S_OK;
	CString strQuery;
	strQuery.Format(_T("SELECT * FROM %s WHERE BRAND_ID = %d"), tableName, brandID);

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
			MODELS* model = new MODELS();
			*model = GetRowSet();

			modelsArray.Add(model);
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
}

MODELS& ModelsTable::GetRowSet()
{
	return model;
};