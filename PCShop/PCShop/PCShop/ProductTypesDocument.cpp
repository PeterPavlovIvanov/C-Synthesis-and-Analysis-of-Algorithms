﻿// ProductTypesDocument.cpp : implementation file
//

#include "stdafx.h"
#include "PCShop.h"
#include "ProductTypesDocument.h"


// ProductTypesDocument

IMPLEMENT_DYNCREATE(ProductTypesDocument, CDocument)

BEGIN_MESSAGE_MAP(ProductTypesDocument, CDocument)
END_MESSAGE_MAP()

ProductTypesDocument::ProductTypesDocument()
{
}

BOOL ProductTypesDocument::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

ProductTypesDocument::~ProductTypesDocument()
{
}

// ProductTypesDocument diagnostics

#ifdef _DEBUG
void ProductTypesDocument::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void ProductTypesDocument::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}

BOOL ProductTypesDocument::SelectAll()
{
	if (FAILED(productTypesBusinessLogic.SelectAll(productTypesArray)))
		return FALSE;

	if (FAILED(categoriesBusinessLogic.SelectAll(categoriesArray)))
		return FALSE;

	if (FAILED(modelsBusinessLogic.SelectAll(modelsArray)))
		return FALSE;

	if (FAILED(brandsBusinessLogic.SelectAll(brandsArray)))
		return FALSE;

	return TRUE;
}

BOOL ProductTypesDocument::SelectByID(int id, ProductTypeDTO & ptDTO)
{
	return productTypesBusinessLogic.SelectWhereID(id, ptDTO);
}

BOOL ProductTypesDocument::DeleteByID(int id)
{
	BOOL bResult = productTypesBusinessLogic.DeleteWhereID(id);

	if (bResult != TRUE)
	{
		AfxMessageBox(_T("Error in removing product type with ID: %d.\n", id));
		return FALSE;
	}

	for (int i = 0; i < productTypesArray.GetCount(); i++)
		if (productTypesArray.GetAt(i)->ID == id)
		{
			productTypesArray.DeleteByIndex(i);
			break;
		}

	ProductTypeDTO ptDTO;
	ptDTO.productType.ID = id;

	//UpdateCodes eUpdateCode = UpdateCodeDelete;
	//OnUpdateAllViews(eUpdateCode, rack);
	return bResult;
}

BOOL ProductTypesDocument::UpdateProductType(ProductTypeDTO & ptDTO)
{
	BOOL bResult = productTypesBusinessLogic.UpdateByID(ptDTO);

	if (bResult != TRUE)
		return FALSE;

	for (int i = 0; i < productTypesArray.GetCount(); i++)
		if (productTypesArray.GetAt(i)->ID == ptDTO.productType.ID)
		{
			productTypesArray.SetAt(i, &(ptDTO.productType));
			break;
		}

	//UpdateCodes eUpdateCode = UpdateCodeUpdate;
	//OnUpdateAllViews(eUpdateCode, recCity);
	return bResult;
}

BOOL ProductTypesDocument::InsertProductType(ProductTypeDTO & ptDTO)
{
	BOOL bResult = productTypesBusinessLogic.Insert(ptDTO);

	if (bResult != TRUE)
		return FALSE;

	productTypesArray.Add(&(ptDTO.productType)); //TODO: check Append

	//UpdateCodes eUpdateCode = UpdateCodeInsert;
	//OnUpdateAllViews(eUpdateCode, recCities);
	return bResult;
}

#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// ProductTypesDocument serialization

void ProductTypesDocument::Serialize(CArchive& ar)
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


// ProductTypesDocument commands
