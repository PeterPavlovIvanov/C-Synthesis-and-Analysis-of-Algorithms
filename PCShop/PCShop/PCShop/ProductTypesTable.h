#pragma once
#include "AbstractTable.h"
#include "ProductTypes.h"

class ProductTypesAccessor
{
public:
	PRODUCT_TYPES productType;

	BEGIN_ACCESSOR_MAP(ProductTypesAccessor, 2)
		BEGIN_ACCESSOR(0, true)
			COLUMN_ENTRY(1, productType.ID)
		END_ACCESSOR()

		BEGIN_ACCESSOR(1, true)
			COLUMN_ENTRY(2, productType.productName)
			COLUMN_ENTRY(3, productType.productSize)
			COLUMN_ENTRY(4, productType.description)
			COLUMN_ENTRY(5, productType.price)
			COLUMN_ENTRY(6, productType.categoryID)
			COLUMN_ENTRY(7, productType.quantity)
			COLUMN_ENTRY(8, productType.brandID)
			COLUMN_ENTRY(9, productType.modelID)
		END_ACCESSOR()
	END_ACCESSOR_MAP()
};

class ProductTypesTable : public AbstractTable<ProductTypesAccessor, PRODUCT_TYPES>
{
public:
	ProductTypesTable();
	ProductTypesTable(CSession* session);
	~ProductTypesTable();

	void Trim() override;

	///<summary>Взима rowset-а</summary>
	virtual PRODUCT_TYPES& GetRowSet() override;
};