#include "stdafx.h"
#include "ProductTypesTable.h"
#include "TypeDefs.h"

ProductTypesTable::ProductTypesTable()
{
	tableName.Format(_T("PRODUCT_TYPES"));
}

ProductTypesTable::ProductTypesTable(CSession* session) : AbstractTable(session)
{
	tableName.Format(_T("PRODUCT_TYPES"));
}

ProductTypesTable::~ProductTypesTable()
{
}


PRODUCT_TYPES& ProductTypesTable::GetRowSet()
{
	return productType;
};


void ProductTypesTable::Trim()
{
	wchar_t cSpace = ' ';
	CString description(productType.description), ptName(productType.productName);

	int nIndex = description.GetLength() - FIX_TO_LAST_INDEX;
	//премахваме space-овете от описанието
	while (productType.description[nIndex] == cSpace) {
		productType.description[nIndex] = NULL;
		nIndex--;
	}

	nIndex = ptName.GetLength() - FIX_TO_LAST_INDEX;

	//премахваме space-овете от името
	while (productType.productName[nIndex] == cSpace) {
		productType.productName[nIndex] = NULL;
		nIndex--;
	}
};