// ModelsView.cpp : implementation file
//

#include "stdafx.h"
#include "PCShop.h"
#include "ModelsView.h"
#include "TypeDefs.h" 
#include "ModelsDialog.h"

// ModelsView

IMPLEMENT_DYNCREATE(ModelsView, CListView)

BEGIN_MESSAGE_MAP(ModelsView, CListView)
	ON_COMMAND(INSERT_MODEL_OPTION, &ModelsView::OnModelInsert)
	ON_COMMAND(UPDATE_MODEL_OPTION, &ModelsView::OnModelUpdate)
	ON_COMMAND(PREVIEW_MODEL_OPTION, &ModelsView::OnModelPreview)
	ON_COMMAND(DELETE_MODEL_OPTION, &ModelsView::OnModelDelete)
	ON_WM_PAINT()
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()

ModelsView::ModelsView()
{

}

ModelsView::~ModelsView()
{
}


// ModelsView diagnostics

#ifdef _DEBUG
void ModelsView::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void ModelsView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif
#endif //_DEBUG


ModelsDocument * ModelsView::GetDocument() const
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(ModelsDocument)));
	return (ModelsDocument*)m_pDocument;
}

void ModelsView::OnInitialUpdate()
{
	SetColumnsModelsListCtrl();

	CListView::OnInitialUpdate();

	if (GetDocument()->SelectAll() == FALSE)
	{
		return;
	}

	for (int i = 0; i < GetDocument()->GetModelsArray().GetCount(); i++)
	{
		MODELS* model = GetDocument()->GetModelsArray().GetAt(i);
		BRANDS* brand = NULL;

		CString strID;
		strID.Format(_T("%d"), model->ID);

		//brand
		for (int j = 0; j < GetDocument()->GetBrandsArray().GetCount(); j++)
			if(GetDocument()->GetBrandsArray().GetAt(j)->ID == model->brandID)
			{
				brand = GetDocument()->GetBrandsArray().GetAt(j);
			}

		if (!brand)
			continue;

		int index = listCtrl.InsertItem(0, model->modelName);
		listCtrl.SetItemText(index, 1, model->modelName);
		listCtrl.SetItemText(index, 2, brand->brandName);
		listCtrl.SetItemData(index, model->ID);
	}

	listCtrl.DeleteColumn(0);
}

// ModelsView message handlers

void ModelsView::SetColumnsModelsListCtrl()
{
	listCtrl.SetView(LVS_REPORT);
	//todo: LVS_SINGLESEL
	listCtrl.SetExtendedStyle(listCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT);

	listCtrl.InsertColumn(0, _T(""), LVCFMT_RIGHT);
	listCtrl.InsertColumn(1, _T("MODEL_NAME"), LVCFMT_RIGHT, COLUMN_WIDTH_BASIC);
	listCtrl.InsertColumn(2, _T("BRAND_NAME"), LVCFMT_RIGHT, COLUMN_WIDTH_BASIC);
}

void ModelsView::OnContextMenu(CWnd * pWnd, CPoint point)
{
	//Sample 01: Declarations
	CRect client_rect;
	CMenu MainMenu;

	//Get Mouse Click position and convert it to the Screen Co-ordinate
	GetClientRect(&client_rect);
	ClientToScreen(&client_rect);

	//Check the mouse pointer position is inside the client area
	if (client_rect.PtInRect(point))
	{
		//Create the Main Menu
		MainMenu.CreatePopupMenu();
		MainMenu.AppendMenu(MF_STRING, INSERT_MODEL_OPTION, _T("Add Model"));
		if (listCtrl.GetNextItem(-1, LVNI_SELECTED) > -1)
		{
			MainMenu.AppendMenu(MF_STRING, UPDATE_MODEL_OPTION, _T("Update Model"));
			MainMenu.AppendMenu(MF_STRING, DELETE_MODEL_OPTION, _T("Delete Model"));
			MainMenu.AppendMenu(MF_STRING, PREVIEW_MODEL_OPTION, _T("Preview Model"));
		}

		//Display the Popup Menu
		MainMenu.TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);
	}
	else
	{
		CWnd::OnContextMenu(pWnd, point);
	}
}

void ModelsView::OnModelInsert()
{//Взимаме документа
	ModelsDocument* modelsDocument = GetDocument();

	//Инициализираме диалога със съответните заглавие и полета
	MODELS model;
	BRANDS brand;
	ModelsDialog dialog(model, brand, DialogModeInsert);

	if (dialog.DoModal() != IDOK)
		return;

	modelsDocument->InsertModel(model, brand);
}

void ModelsView::OnModelPreview()
{
	//Взимаме документа
	ModelsDocument* modelsDocument = GetDocument();

	int index = listCtrl.GetSelectionMark();
	long ID = (long)listCtrl.GetItemData(index);

	MODELS model;
	BRANDS brand;
	if (modelsDocument->SelectByID(ID, model, brand) == FALSE)
		return;

	//Инициализираме диалога със съответните заглавие и полета
	ModelsDialog dialog(model, brand, DialogModePreview);

	dialog.DoModal();
}

void ModelsView::OnModelDelete()
{
	//Взимаме документа
	ModelsDocument* modelsDocument = GetDocument();

	int index = listCtrl.GetSelectionMark();
	long ID = (long)listCtrl.GetItemData(index);

	MODELS model;
	BRANDS brand;
 	if (modelsDocument->SelectByID(ID, model, brand) == FALSE)
		return;

	//Инициализираме диалога със съответните заглавие и полета
	ModelsDialog dialog(model, brand, DialogModeDelete);

	if (dialog.DoModal() != IDOK)
		return;

	modelsDocument->DeleteByID(ID);
}

void ModelsView::OnModelUpdate()
{
	//Взимаме документа
	ModelsDocument* modelsDocument = GetDocument();

	int index = listCtrl.GetSelectionMark();
	long ID = (long)listCtrl.GetItemData(index);

	MODELS model;
	BRANDS brand;
	if (modelsDocument->SelectByID(ID, model, brand) == FALSE)
		return;

	//Инициализираме диалога със съответните заглавие и полета
	ModelsDialog dialog(model, brand, DialogModeUpdate);

	if (dialog.DoModal() != IDOK)
		return;

	modelsDocument->UpdateModel(model);
}

void ModelsView::OnUpdate(CView * pSender, LPARAM lHint, CObject * pHint)
{
	switch (lHint)
	{
	case (UpdateCodes::UpdateCodeUpdate):
	{
		UpdateModelInListCtrl(pHint);
		break;
	}
	case (UpdateCodes::UpdateCodeInsert):
	{
		InsertModelInListCtrl(pHint);
		break;
	}
	case (UpdateCodes::UpdateCodeDelete):
	{
		DeleteModelInListCtrl(pHint);
		break;
	}
	default:
		break;
	}
	__super::OnUpdate(pSender, lHint, pHint);
}

void ModelsView::UpdateModelInListCtrl(CObject * pHint)
{


	for (int i = 0; i < listCtrl.GetItemCount(); i++)
	{
		MODELS* model = (MODELS*)pHint;
		BRANDS* brand = NULL;
	
		for (int j = 0; j < GetDocument()->GetBrandsArray().GetCount(); j++)
			if (GetDocument()->GetBrandsArray().GetAt(j)->ID == model->brandID)
			{
				brand = GetDocument()->GetBrandsArray().GetAt(j);
				break;
			}//if
		
		if (!brand)
			return;

		if (listCtrl.GetItemData(i) == model->ID)
		{
			listCtrl.SetItemText(i, 0, model->modelName);
			listCtrl.SetItemText(i, 1, brand->brandName);
			break;
		}//if
	}//for
}

void ModelsView::InsertModelInListCtrl(CObject * pHint)
{
	MODELS* model = (MODELS*)pHint;
	BRANDS* brand = NULL;

	for (int j = 0; j < GetDocument()->GetBrandsArray().GetCount(); j++)
		if (GetDocument()->GetBrandsArray().GetAt(j)->ID == model->brandID)
		{
			brand = GetDocument()->GetBrandsArray().GetAt(j);
			break;
		}//if

	if (!brand)
		return;

	int index = listCtrl.InsertItem(0, model->modelName);
	listCtrl.SetItemText(index, 1, brand->brandName);
	listCtrl.SetItemData(index, model->ID);
}

void ModelsView::DeleteModelInListCtrl(CObject * pHint)
{
	for (int i = 0; i < listCtrl.GetItemCount(); i++)
	{
		MODELS* model = (MODELS*)pHint;
		if (listCtrl.GetItemData(i) == model->ID)
		{
			listCtrl.DeleteItem(i);
			break;
		}
	}
}
