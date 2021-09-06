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

BOOL ModelsDocument::SelectByID(int id, MODELS & model, BRANDS& brand)
{
	if (!modelsBusinessLogic.SelectWhereID(id, model))
		return FALSE;

	if (!brandsBusinessLogic.SelectWhereID(model.brandID, brand, modelsArray))
		return FALSE;

	return TRUE;
}

BOOL ModelsDocument::DeleteByID(int id)
{
	BOOL bResult = modelsBusinessLogic.DeleteWhereID(id);

	if (bResult != TRUE)
	{
		AfxMessageBox(_T("Error in removing model with ID: %d.\n"), id);
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

	UpdateCodes eUpdateCode = UpdateCodeDelete;
	OnUpdateAllViews(eUpdateCode, model);
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

	UpdateCodes eUpdateCode = UpdateCodeUpdate;
	OnUpdateAllViews(eUpdateCode, model);
	return bResult;
};

BOOL ModelsDocument::InsertModel(MODELS & model, BRANDS& brand)
{
	BOOL bResult = modelsBusinessLogic.Insert(model, brand);

	if (bResult != TRUE)
	{
		return FALSE;
	}

	MODELS* pointerBrand = new MODELS();
	*pointerBrand = model;
	modelsArray.Add(pointerBrand); 

	UpdateCodes eUpdateCode = UpdateCodeInsert;
	OnUpdateAllViews(eUpdateCode, model);
	return bResult;
}

void ModelsDocument::OnUpdateAllViews(UpdateCodes updateCodeN, MODELS model)
{
	UpdateAllViews(NULL, updateCodeN, (CObject*)&model);
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
