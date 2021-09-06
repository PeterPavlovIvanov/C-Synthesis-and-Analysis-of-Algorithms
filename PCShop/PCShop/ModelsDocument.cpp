// ModelsDocument.cpp : implementation file
//

#include "stdafx.h"
#include "PCShop.h"
#include "ModelsDocument.h"


// ModelsDocument

IMPLEMENT_DYNCREATE(ModelsDocument, CDocument)

BEGIN_MESSAGE_MAP(ModelsDocument, CDocument)
END_MESSAGE_MAP()

ModelsDocument::ModelsDocument()
{
}

BOOL ModelsDocument::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

ModelsDocument::~ModelsDocument()
{
}

BOOL ModelsDocument::SelectAll()
{
	if (FAILED(modelsBusinessLogic.SelectAll(modelsArray)))
		return FALSE;

	if (FAILED(brandsBusinessLogic.SelectAll(brandsArray)))
		return FALSE;

	return TRUE;
}

BOOL ModelsDocument::SelectByID(int id, MODELS & model)
{
	return modelsBusinessLogic.SelectWhereID(id, model);
}

BOOL ModelsDocument::DeleteByID(int id)
{
	BOOL bResult = modelsBusinessLogic.DeleteWhereID(id);

	if (bResult != TRUE)
	{
		AfxMessageBox(_T("Error in removing model with ID: %d.\n", id));
		return FALSE;
	}

	for (int i = 0; i < modelsArray.GetCount(); i++)
	{
		if (modelsArray.GetAt(i)->ID == id)
		{
			modelsArray.DeleteByIndex(i);
			break;
		}
	}

	MODELS model;
	model.ID = id;

	//UpdateCodes eUpdateCode = UpdateCodeDelete;
	//OnUpdateAllViews(eUpdateCode, rack);
	return bResult;
}

BOOL ModelsDocument::UpdateModel(MODELS & model)
{
	BOOL bResult = modelsBusinessLogic.UpdateByID(model);

	if (bResult != TRUE)
	{
		return FALSE;
	}

	for (int i = 0; i < modelsArray.GetCount(); i++)
	{
		if (modelsArray.GetAt(i)->ID == model.ID)
		{
			*(modelsArray.GetAt(i)) = model;
			break;
		}
	}

	//UpdateCodes eUpdateCode = UpdateCodeUpdate;
	//OnUpdateAllViews(eUpdateCode, recCity);
	return bResult;
};

BOOL ModelsDocument::InsertModel(MODELS & model)
{
	BOOL bResult = modelsBusinessLogic.Insert(model);

	if (bResult != TRUE)
	{
		return FALSE;
	}

	MODELS* pointerBrand = new MODELS();
	*pointerBrand = model;
	modelsArray.Add(pointerBrand); //TODO: check Append

								  //UpdateCodes eUpdateCode = UpdateCodeInsert;
								  //OnUpdateAllViews(eUpdateCode, recCities);
	return bResult;
}



// ModelsDocument diagnostics

#ifdef _DEBUG
void ModelsDocument::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void ModelsDocument::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// ModelsDocument serialization

void ModelsDocument::Serialize(CArchive& ar)
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


// ModelsDocument commands
