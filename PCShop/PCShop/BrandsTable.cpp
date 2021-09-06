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

BOOL BrandsTable::SelectWherebrandName(CString brandName, BRANDS & brand)
{
	HRESULT hResult = S_OK;
	CString strQuery;
	strQuery.Format(_T("SELECT TOP 1 * FROM BRANDS WHERE BRAND_NAME = '%s'"), brandName);

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
			brand = GetRowSet();
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

BRANDS& BrandsTable::GetRowSet()
{
	return brand;
};