#pragma once
#include "TypeDefs.h"
#include "ProductTypesBusinessLogic.h"
#include "ProductsBusinessLogic.h"
#include "ModelsBusinessLogic.h"
#include "BrandsBusinessLogic.h"
#include "CategoriesBusinessLogic.h"
#include "RacksBusinessLogic.h"
#include "ShelvesBusinessLogic.h"

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

	BOOL SelectByID(int id, ProductDTO& productDTO);

	BOOL DeleteByID(int id);

	BOOL UpdateProduct(ProductDTO& productDTO);

	BOOL InsertProduct(ProductDTO& productDTO);

	ProductsArray& GetProductsArray()
	{
		return productsArray;
	}

	ProductTypesArray& GetProductTypesArray()
	{
		return productTypesArray;
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

	//void OnUpdateAllViews(UpdateCodes eUpdateCode, RACKS rack);

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
	ProductTypesArray productTypesArray;
	RacksArray racksArray;
	ShelvesArray shelvesArray;
	CategoriesArray categoriesArray;
	ModelsArray modelsArray;
	BrandsArray brandsArray;
};