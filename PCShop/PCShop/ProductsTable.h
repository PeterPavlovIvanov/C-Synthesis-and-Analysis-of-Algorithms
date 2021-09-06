#pragma once
#include "AbstractTable.h"
#include "Products.h"

class ProductsAccessor
{
protected:
	PRODUCTS product;

	BEGIN_ACCESSOR_MAP(ProductsAccessor, 2)
		BEGIN_ACCESSOR(0, true)
		COLUMN_ENTRY(1, product.serialID)
		END_ACCESSOR()

		BEGIN_ACCESSOR(1, true)
		COLUMN_ENTRY(2, product.productTypeID)
		COLUMN_ENTRY(3, product.registerDate)
		COLUMN_ENTRY(4, product.soldDate)
		COLUMN_ENTRY(5, product.addressDate)
		COLUMN_ENTRY(6, product.shelfID)
		COLUMN_ENTRY(7, product.rackID)
		END_ACCESSOR()
	END_ACCESSOR_MAP()
};

class ProductsTable : public AbstractTable<ProductsAccessor, PRODUCTS>
{
public:
	ProductsTable();
	ProductsTable(CSession* session);
	~ProductsTable();

	void Trim() override;

	PRODUCTS & GetRowSet();

};