#pragma once
#include "TypeDefs.h"
#include "ProductTypesBusinessLogic.h"
#include "ModelsBusinessLogic.h"
#include "BrandsBusinessLogic.h"
#include "CategoriesBusinessLogic.h"


// ProductTypesDocument document

class ProductTypesDocument : public CDocument
{
protected:
	DECLARE_DYNCREATE(ProductTypesDocument)
	DECLARE_MESSAGE_MAP()

	virtual BOOL OnNewDocument();

public:
	ProductTypesDocument();
	virtual ~ProductTypesDocument();
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

	BOOL SelectByID(int id, ProductTypeDTO& ptDTO);

	BOOL DeleteByID(int id);

	BOOL UpdateProductType(ProductTypeDTO& ptDTO);

	BOOL InsertProductType(ProductTypeDTO& ptDTO);

	ProductTypesArray& GetProductTypesArray()
	{
		return productTypesArray;
	}

	CategoriesArray& GetCategoriesArray()
	{
		return categoriesArray;
	}

	BrandsArray& GetBrandsArray()
	{
		return brandsArray;
	}

	ModelsArray& GetModelsArray()
	{
		return modelsArray;
	}

	//void OnUpdateAllViews(UpdateCodes eUpdateCode, RACKS rack);

	//BusinessLogic Objects
public:
	ProductTypesBusinessLogic productTypesBusinessLogic;
	CategoriesBusinessLogic categoriesBusinessLogic;
	ModelsBusinessLogic modelsBusinessLogic;
	BrandsBusinessLogic brandsBusinessLogic;

	//Arrays for storing the displayed data
private:
	ProductTypesArray productTypesArray; //масив хранилище на документа за view-тата
	CategoriesArray categoriesArray; //масив хранилище на документа за view-тата
	ModelsArray modelsArray; //масив хранилище на документа за view-тата
	BrandsArray brandsArray; //масив хранилище на документа за view-тата
};
