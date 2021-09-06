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
}

BOOL ProductTypesTable::SelectByAll(PRODUCT_TYPES & productType)
{
	HRESULT hResult = S_OK;
	CString strQuery;
	strQuery.Format(_T("SELECT TOP 1 * FROM %s WHERE PRODUCT_NAME = '%s' AND PRODUCT_SIZE = %d AND DESCRIPTION = '%s' AND PRICE = %.2f AND CATEGORY_ID = %d AND BRAND_ID = %d AND MODEL_ID = %d")
		, tableName, productType.productName, productType.productSize, productType.description, productType.price, productType.categoryID, productType.brandID, productType.modelID);

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
			PRODUCT_TYPES* pt = new PRODUCT_TYPES();
			*pt = GetRowSet();

			productType = *pt;
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