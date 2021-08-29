// ShelvesDocument.cpp : implementation file
//

#include "stdafx.h"
#include "PCShop.h"
#include "ShelvesDocument.h"
#include "UpdateCodes.h"

// ShelvesDocument

IMPLEMENT_DYNCREATE(ShelvesDocument, CDocument)

BEGIN_MESSAGE_MAP(ShelvesDocument, CDocument)
END_MESSAGE_MAP()

ShelvesDocument::ShelvesDocument()
{
}

BOOL ShelvesDocument::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

ShelvesDocument::~ShelvesDocument()
{
}



// ShelvesDocument diagnostics

#ifdef _DEBUG
void ShelvesDocument::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void ShelvesDocument::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}

BOOL ShelvesDocument::SelectAll()
{
	if(FAILED(shelvesBusinessLogic.SelectAll(shelvesArray)))
		return FALSE;

	if(FAILED(racksBusinessLogic.SelectAll(racksArray)))
		return FALSE;

	return TRUE;
}

BOOL ShelvesDocument::SelectByID(int id, SHELVES & shelf)
{
	return shelvesBusinessLogic.SelectWhereID(id, shelf);
}

BOOL ShelvesDocument::DeleteByID(int id)
{
	BOOL bResult = shelvesBusinessLogic.DeleteWhereID(id);

	if (bResult != TRUE)
	{
		AfxMessageBox(_T("Error in removing shelf with ID: %d.\n", id));
		return FALSE;
	}

	for (int i = 0; i < shelvesArray.GetCount(); i++)
	{
		if (shelvesArray.GetAt(i)->ID == id)
		{
			shelvesArray.DeleteByIndex(i);
			break;
		}
	}

	SHELVES shelf;
	shelf.ID = id;

	UpdateCodes eUpdateCode = UpdateCodeDelete;
	OnUpdateAllViews(eUpdateCode, shelf);
	return bResult;
}

BOOL ShelvesDocument::UpdateShelf(SHELVES & shelf)
{
	BOOL bResult = shelvesBusinessLogic.UpdateByID(shelf);

	if (bResult != TRUE)
	{
		return FALSE;
	}

	for (int i = 0; i < shelvesArray.GetCount(); i++)
	{
		if (shelvesArray.GetAt(i)->ID == shelf.ID)
		{
			*(shelvesArray.GetAt(i)) = shelf;
			break;
		}
	}

	UpdateCodes eUpdateCode = UpdateCodeUpdate;
	OnUpdateAllViews(eUpdateCode, shelf);
	return bResult;
};

BOOL ShelvesDocument::InsertShelf(SHELVES & shelf)
{
	BOOL bResult = shelvesBusinessLogic.Insert(shelf);

	if (bResult != TRUE)
	{
		return FALSE;
	}

	SHELVES* pointerShelf = new SHELVES();
	*pointerShelf = shelf;
	shelvesArray.Add(pointerShelf); //TODO: check Append

	UpdateCodes updateCode = UpdateCodeInsert;
	OnUpdateAllViews(updateCode, shelf);
	return bResult;
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// ShelvesDocument serialization

void ShelvesDocument::Serialize(CArchive& ar)
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


// ShelvesDocument commands

void ShelvesDocument::OnUpdateAllViews(UpdateCodes updateCodeN, SHELVES shelf)
{
	UpdateAllViews(NULL, updateCodeN, (CObject*)&shelf);
};
