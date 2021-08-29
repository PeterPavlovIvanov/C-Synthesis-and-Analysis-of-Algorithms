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

BOOL ProductsDocument::SelectByID(int id, ProductDTO & productDTO)
{
	return productsBusinessLogic.SelectWhereID(id, productDTO);
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

	ProductDTO productDTO;
	productDTO.product.serialID = id;

	//UpdateCodes eUpdateCode = UpdateCodeDelete;
	//OnUpdateAllViews(eUpdateCode, rack);
	return bResult;
}

BOOL ProductsDocument::UpdateProduct(ProductDTO & productDTO)
{
	BOOL bResult = productsBusinessLogic.UpdateByID(productDTO);

	if (bResult != TRUE)
		return FALSE;

	for (int i = 0; i < productsArray.GetCount(); i++)
		if (productsArray.GetAt(i)->serialID == productDTO.product.serialID)
		{
			productsArray.SetAt(i, &(productDTO.product));
			break;
		}

	//UpdateCodes eUpdateCode = UpdateCodeUpdate;
	//OnUpdateAllViews(eUpdateCode, recCity);
	return bResult;
}

BOOL ProductsDocument::InsertProduct(ProductDTO & productDTO)
{
	BOOL bResult = productsBusinessLogic.Insert(productDTO);

	if (bResult != TRUE)
		return FALSE;

	productsArray.Add(&(productDTO.product)); //TODO: check Append

	//UpdateCodes eUpdateCode = UpdateCodeInsert;
	//OnUpdateAllViews(eUpdateCode, recCities);
	return bResult;
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
