// ProductsDocument.cpp : implementation file
//

#include "stdafx.h"
#include "PCShop.h"
#include "ProductsDocument.h"


// ProductsDocument

IMPLEMENT_DYNCREATE(ProductsDocument, CDocument)

BEGIN_MESSAGE_MAP(ProductsDocument, CDocument)
END_MESSAGE_MAP()

ProductsDocument::ProductsDocument()
{
}

BOOL ProductsDocument::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

ProductsDocument::~ProductsDocument()
{
}

// ProductsDocument diagnostics

#ifdef _DEBUG
void ProductsDocument::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void ProductsDocument::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG


BOOL ProductsDocument::SelectAll()
{
	if (FAILED(racksBusinessLogic.SelectAll(racksArray)))
		return FALSE;

	if (FAILED(shelvesBusinessLogic.SelectAll(shelvesArray)))
		return FALSE;

	if (FAILED(productTypesBusinessLogic.SelectAll(productTypesArray)))
		return FALSE;

	if (FAILED(categoriesBusinessLogic.SelectAll(categoriesArray)))
		return FALSE;

	if (FAILED(modelsBusinessLogic.SelectAll(modelsArray)))
		return FALSE;

	if (FAILED(brandsBusinessLogic.SelectAll(brandsArray)))
		return FALSE;

	if (FAILED(productsBusinessLogic.SelectAll(productsArray)))
		return FALSE;

	return TRUE;
}

BOOL ProductsDocument::SelectByID(int id, PRODUCTS & product, PRODUCT_TYPES& productType, ModelsArray& modelsArray, CategoriesArray& categoriesArray, BrandsArray& brandsArray, ShelvesArray& shelvesArray, RacksArray& racksArray)
{
	if (FAILED(productsBusinessLogic.SelectWhereID(id, product, productType, modelsArray, categoriesArray, brandsArray, shelvesArray, racksArray)))
		return FALSE;

	return TRUE;
}

BOOL ProductsDocument::DeleteByID(int id)
{
	BOOL bResult = productsBusinessLogic.DeleteWhereID(id);

	if (bResult != TRUE)
	{
		AfxMessageBox(_T("Error in removing product with serial ID: %d.\n", id));
		return FALSE;
	}

	for (int i = 0; i < productsArray.GetCount(); i++)
		if (productsArray.GetAt(i)->serialID == id)
		{
			productsArray.DeleteByIndex(i);
			break;
		}

	PRODUCTS product;
	product.serialID = id;

	UpdateCodes eUpdateCode = UpdateCodeDelete;
	OnUpdateAllViews(eUpdateCode, product);
	return bResult;
}

BOOL ProductsDocument::UpdateProduct(PRODUCTS & product)
{
	BOOL bResult = productsBusinessLogic.UpdateByID(product);

	if (bResult != TRUE)
		return FALSE;

	for (int i = 0; i < productsArray.GetCount(); i++)
		if (productsArray.GetAt(i)->serialID == product.serialID)
		{
			productsArray.SetAt(i, &product);
			break;
		}

	UpdateCodes eUpdateCode = UpdateCodeUpdate;
	OnUpdateAllViews(eUpdateCode, product);
	return bResult;
}

BOOL ProductsDocument::InsertProduct(PRODUCTS & product, PRODUCT_TYPES & productType)
{
	BOOL result = FALSE;
	result = productsBusinessLogic.Insert(product, productType);
	
	if(!result)
		return FALSE;

	productsArray.Add(&product); 
	UpdateCodes eUpdateCode = UpdateCodeInsert;
	OnUpdateAllViews(eUpdateCode, product);
	
	return TRUE;
}

void ProductsDocument::OnUpdateAllViews(UpdateCodes updateCodeN, PRODUCTS product)
{
	UpdateAllViews(NULL, updateCodeN, (CObject*)&product);
}


#ifndef _WIN32_WCE
// ProductsDocument serialization

void ProductsDocument::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}
#endif


// ProductsDocument commands
