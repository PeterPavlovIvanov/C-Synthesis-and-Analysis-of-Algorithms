#include "stdafx.h"
#include "CategoriesTable.h"

CategoriesTable::CategoriesTable()
{
	tableName.Format(_T("CATEGORIES"));
}

CategoriesTable::CategoriesTable(CSession* session) : AbstractTable(session)
{
	tableName.Format(_T("CATEGORIES"));
}

CategoriesTable::~CategoriesTable()
{
}

void CategoriesTable::Trim()
{
	wchar_t cSpace = ' ';
	CString categoryName(category.categoryName);

	int nIndex = categoryName.GetLength() - FIX_TO_LAST_INDEX;
	//премахваме space-овете от името на модела
	while (category.categoryName[nIndex] == cSpace) {
		category.categoryName[nIndex] = NULL;
		nIndex--;
	}
}

CATEGORIES& CategoriesTable::GetRowSet()
{
	return category;
};