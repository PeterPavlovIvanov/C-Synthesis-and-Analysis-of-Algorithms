// BrandsDocument.cpp : implementation file
//

#include "stdafx.h"
#include "PCShop.h"
#include "BrandsDocument.h"

// BrandsDocument

IMPLEMENT_DYNCREATE(BrandsDocument, CDocument)

BEGIN_MESSAGE_MAP(BrandsDocument, CDocument)
END_MESSAGE_MAP()

BrandsDocument::BrandsDocument()
{
}

BOOL BrandsDocument::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

BrandsDocument::~BrandsDocument()
{
}


BOOL BrandsDocument::SelectAll()
{
	return brandsBusinessLogic.SelectAll(brandsArray);
}

BOOL BrandsDocument::SelectByID(int id, BRANDS & brand, ModelsArray& modelsArray)
{
	return brandsBusinessLogic.SelectWhereID(id, brand, modelsArray);
}

BOOL BrandsDocument::DeleteByID(int id)
{
	BOOL bResult = brandsBusinessLogic.DeleteWhereID(id);

	if (bResult != TRUE)
	{
		AfxMessageBox(_T("Error in removing brand with ID: %d.\n"), id);
		return FALSE;
	}

	for (int i = 0; i < brandsArray.GetCount(); i++)
	{
		if (brandsArray.GetAt(i)->ID == id)
		{
			brandsArray.DeleteByIndex(i);
			break;
		}
	}

	BRANDS brand;
	brand.ID = id;

	UpdateCodes eUpdateCode = UpdateCodeDelete;
	OnUpdateAllViews(eUpdateCode, brand);
	return bResult;
}

BOOL BrandsDocument::UpdateBrand(BRANDS & brand)
{
	BOOL bResult = brandsBusinessLogic.UpdateByID(brand);

	if (bResult != TRUE)
	{
		return FALSE;
	}

	for (int i = 0; i < brandsArray.GetCount(); i++)
	{
		if (brandsArray.GetAt(i)->ID == brand.ID)
		{
			*(brandsArray.GetAt(i)) = brand;
			break;
		}
	}

	UpdateCodes eUpdateCode = UpdateCodeUpdate;
	OnUpdateAllViews(eUpdateCode, brand);
	return bResult;
};

BOOL BrandsDocument::InsertBrand(BRANDS & brand)
{
	BOOL bResult = brandsBusinessLogic.Insert(brand);

	if (bResult != TRUE)
	{
		return FALSE;
	}

	BRANDS* pointerBrand = new BRANDS();
	*pointerBrand = brand;
	brandsArray.Add(pointerBrand);

	UpdateCodes eUpdateCode = UpdateCodeInsert;
	OnUpdateAllViews(eUpdateCode, brand);
	return bResult;
}

void BrandsDocument::OnUpdateAllViews(UpdateCodes updateCodeN, BRANDS brand)
{
	UpdateAllViews(NULL, updateCodeN, (CObject*)&brand);
}

// BrandsDocument diagnostics

#ifdef _DEBUG
void BrandsDocument::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void BrandsDocument::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// BrandsDocument serialization

void BrandsDocument::Serialize(CArchive& ar)
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


// BrandsDocument commands
