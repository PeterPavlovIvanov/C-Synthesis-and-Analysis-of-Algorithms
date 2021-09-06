#include "stdafx.h"
#include "ProductsTable.h"

ProductsTable::ProductsTable()
{
	tableName.Format(_T("PRODUCTS"));
}

ProductsTable::ProductsTable(CSession* session) : AbstractTable(session)
{
	tableName.Format(_T("PRODUCTS"));
}

ProductsTable::~ProductsTable()
{
}

void ProductsTable::Trim()
{
}

PRODUCTS& ProductsTable::GetRowSet()
{
	return product;
};