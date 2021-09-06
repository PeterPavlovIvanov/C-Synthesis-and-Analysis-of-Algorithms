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

MODELS& ModelsTable::GetRowSet()
{
	return model;
};