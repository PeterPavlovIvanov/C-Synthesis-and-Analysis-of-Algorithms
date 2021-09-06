// CategoriesDocument.cpp : implementation file
//

#include "stdafx.h"
#include "PCShop.h"
#include "CategoriesDocument.h"


// CategoriesDocument

IMPLEMENT_DYNCREATE(CategoriesDocument, CDocument)

CategoriesDocument::CategoriesDocument()
{
}

BOOL CategoriesDocument::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CategoriesDocument::~CategoriesDocument()
{
}


BEGIN_MESSAGE_MAP(CategoriesDocument, CDocument)
END_MESSAGE_MAP()


// CategoriesDocument diagnostics

#ifdef _DEBUG
void CategoriesDocument::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void CategoriesDocument::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}

BOOL CategoriesDocument::SelectAll()
{
	return categoriesBusinessLogic.SelectAll(categoriesArray);
}

BOOL CategoriesDocument::SelectByID(int id, CATEGORIES & category)
{
	return categoriesBusinessLogic.SelectWhereID(id, category);
}

BOOL CategoriesDocument::DeleteByID(int id)
{
	BOOL bResult = categoriesBusinessLogic.DeleteWhereID(id);

	if (bResult != TRUE)
	{
		AfxMessageBox(_T("Error in removing category with ID: %d.\n", id));
		return FALSE;
	}

	for (int i = 0; i < categoriesArray.GetCount(); i++)
	{
		if (categoriesArray.GetAt(i)->ID == id)
		{
			categoriesArray.DeleteByIndex(i);
			break;
		}
	}

	CATEGORIES category;
	category.ID = id;

	UpdateCodes eUpdateCode = UpdateCodeDelete;
	OnUpdateAllViews(eUpdateCode, category);
	return bResult;
}

BOOL CategoriesDocument::UpdateCategory(CATEGORIES & category)
{
	BOOL bResult = categoriesBusinessLogic.UpdateByID(category);

	if (bResult != TRUE)
	{
		return FALSE;
	}

	for (int i = 0; i < categoriesArray.GetCount(); i++)
	{
		if (categoriesArray.GetAt(i)->ID == category.ID)
		{
			*(categoriesArray.GetAt(i)) = category;
			break;
		}
	}

	UpdateCodes eUpdateCode = UpdateCodeUpdate;
	OnUpdateAllViews(eUpdateCode, category);
	return bResult;
}

BOOL CategoriesDocument::InsertCategory(CATEGORIES & category)
{
	BOOL bResult = categoriesBusinessLogic.Insert(category);

	if (bResult != TRUE)
	{
		return FALSE;
	}

	CATEGORIES* pointerCategory = new CATEGORIES();
	*pointerCategory = category;
	categoriesArray.Add(pointerCategory); 

	UpdateCodes eUpdateCode = UpdateCodeInsert;
	OnUpdateAllViews(eUpdateCode, category);
	return bResult;
}

void CategoriesDocument::OnUpdateAllViews(UpdateCodes updateCodeN, CATEGORIES category)
{
	UpdateAllViews(NULL, updateCodeN, (CObject*)&category);
}

#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// CategoriesDocument serialization

void CategoriesDocument::Serialize(CArchive& ar)
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


// CategoriesDocument commands
