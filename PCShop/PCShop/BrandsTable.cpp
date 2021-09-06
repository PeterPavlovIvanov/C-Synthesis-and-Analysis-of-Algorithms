#include "stdafx.h"
#include "BrandsTable.h"

BrandsTable::BrandsTable()
{
	tableName.Format(_T("BRANDS"));
}

BrandsTable::BrandsTable(CSession* session) : AbstractTable(session)
{
	tableName.Format(_T("BRANDS"));
}

BrandsTable::~BrandsTable()
{
}

void BrandsTable::Trim()
{
	wchar_t cSpace = ' ';
	CString brandName(brand.brandName);

	int nIndex = brandName.GetLength() - FIX_TO_LAST_INDEX;
	//премахваме space-овете от името на марката
	while (brand.brandName[nIndex] == cSpace) {
		brand.brandName[nIndex] = NULL;
		nIndex--;
	}
}

BRANDS& BrandsTable::GetRowSet()
{
	return brand;
};