#pragma once
#include "TypeDefs.h"
#include "ProductTypesBusinessLogic.h"
#include "ProductsBusinessLogic.h"
#include "ModelsBusinessLogic.h"
#include "BrandsBusinessLogic.h"
#include "CategoriesBusinessLogic.h"
#include "RacksBusinessLogic.h"
#include "ShelvesBusinessLogic.h"
#include "UpdateCodes.h"

// ProductsDocument document

class ProductsDocument : public CDocument
{
protected:
	DECLARE_DYNCREATE(ProductsDocument)
	DECLARE_MESSAGE_MAP()

	virtual BOOL OnNewDocument();

public:
	ProductsDocument();
	virtual ~ProductsDocument();
#ifndef _WIN32_WCE
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

public:
	BOOL SelectAll();

	BOOL SelectByID(int id, PRODUCTS & product, PRODUCT_TYPES& productType, ModelsArray& modelsArray, CategoriesArray& categoriesArray, BrandsArray& brandsArray, ShelvesArray& shelvesArray, RacksArray& racksArray);

	BOOL DeleteByID(int id);

	BOOL UpdateProduct(PRODUCTS & product);

	BOOL InsertProduct(PRODUCTS & product, PRODUCT_TYPES & productType);

	ProductsArray& GetProductsArray()
	{
		return productsArray;
	}

	PRODUCT_TYPES* GetProductType()
	{
		return productType;
	}

	RacksArray& GetRacksArray()
	{
		return racksArray;
	}

	ShelvesArray& GetShelvesArray()
	{
		return shelvesArray;
	}

	CategoriesArray& GetCategoriesArray()
	{
		return categoriesArray;
	}

	ModelsArray& GetModelsArray()
	{
		return modelsArray;
	}

	BrandsArray& GetBrandsArray()
	{
		return brandsArray;
	}
	
	ProductTypesArray& GetProductTypesArray()
	{
		return productTypesArray;
	}

	void OnUpdateAllViews(UpdateCodes updateCodeN, PRODUCTS product);

	//BusinessLogic Objects
public:
	ProductsBusinessLogic productsBusinessLogic;
	ProductTypesBusinessLogic productTypesBusinessLogic;
	RacksBusinessLogic racksBusinessLogic;
	ShelvesBusinessLogic shelvesBusinessLogic;
	CategoriesBusinessLogic categoriesBusinessLogic;
	ModelsBusinessLogic modelsBusinessLogic;
	BrandsBusinessLogic brandsBusinessLogic;

	//Arrays for storing the displayed data
private:
	ProductsArray productsArray;
	PRODUCT_TYPES* productType;
	ProductTypesArray productTypesArray;
	RacksArray racksArray;
	ShelvesArray shelvesArray;
	CategoriesArray categoriesArray;
	ModelsArray modelsArray;
	BrandsArray brandsArray;
};