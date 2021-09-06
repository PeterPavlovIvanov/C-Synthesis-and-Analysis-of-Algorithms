// RacksDocument.cpp : implementation file
//

#include "stdafx.h"
#include "PCShop.h"
#include "RacksDocument.h"
#include "UpdateCodes.h"

// RacksDocument

IMPLEMENT_DYNCREATE(RacksDocument, CDocument)

BEGIN_MESSAGE_MAP(RacksDocument, CDocument)
END_MESSAGE_MAP()

RacksDocument::RacksDocument()
{
}

BOOL RacksDocument::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

RacksDocument::~RacksDocument()
{
}

// RacksDocument diagnostics

#ifdef _DEBUG
void RacksDocument::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void RacksDocument::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}

BOOL RacksDocument::SelectAll()
{
	return racksBusinessLogic.SelectAll(racksArray);
}

BOOL RacksDocument::SelectByID(int id, RACKS & rack, ShelvesArray & shelvesArray)
{
	if (FAILED(racksBusinessLogic.SelectWhereID(id, rack)))
		return FALSE;

	if (FAILED(racksBusinessLogic.SelectAllByRackID(shelvesArray, id)))
		return FALSE;

	return TRUE;
}

BOOL RacksDocument::DeleteByID(int id)
{
	BOOL bResult = racksBusinessLogic.DeleteWhereID(id);

	if (bResult != TRUE)
	{
		AfxMessageBox(_T("Error in removing rack with ID: %d.\n", id));
		return FALSE;
	}

	for (int i = 0; i < racksArray.GetCount(); i++)
	{
		if (racksArray.GetAt(i)->ID == id)
		{
			racksArray.DeleteByIndex(i);
			break;
		}
	}

	RACKS rack;
	rack.ID = id;

	UpdateCodes eUpdateCode = UpdateCodeDelete;
	OnUpdateAllViews(eUpdateCode, rack);
	return bResult;
}

BOOL RacksDocument::UpdateRack(RACKS & rack)
{
	BOOL bResult = racksBusinessLogic.UpdateByID(rack);

	if (bResult != TRUE)
	{
		return FALSE;
	}

	for (int i = 0; i < racksArray.GetCount(); i++)
	{
		if (racksArray.GetAt(i)->ID == rack.ID)
		{
			*(racksArray.GetAt(i)) = rack;
			break;
		}
	}

	UpdateCodes eUpdateCode = UpdateCodeUpdate;
	OnUpdateAllViews(eUpdateCode, rack);
	return bResult;
};

BOOL RacksDocument::InsertRack(RACKS & rack)
{
	BOOL bResult = racksBusinessLogic.Insert(rack);

	if (bResult != TRUE)
	{
		return FALSE;
	}

	RACKS* pointerRack = new RACKS();
	*pointerRack = rack;
	racksArray.Add(pointerRack); //TODO: check Append

	UpdateCodes eUpdateCode = UpdateCodeInsert;
	OnUpdateAllViews(eUpdateCode, rack);
	return bResult;
}

#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// RacksDocument serialization

void RacksDocument::Serialize(CArchive& ar)
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

void RacksDocument::OnUpdateAllViews(UpdateCodes updateCodeN, RACKS rack)
{
	UpdateAllViews(NULL, updateCodeN, (CObject*)&rack);
};

// RacksDocument commands
