// RacksView.cpp : implementation file
//

#include "stdafx.h"
#include "PCShop.h"
#include "RacksView.h"
#include "TypeDefs.h" 
#include "DialogModes.h"
#include "UpdateCodes.h"
#include "RacksDialog.h"

// RacksView

IMPLEMENT_DYNCREATE(RacksView, CListView)

RacksView::RacksView()
{

}

RacksView::~RacksView()
{
}

BEGIN_MESSAGE_MAP(RacksView, CListView)
	ON_COMMAND(INSERT_RACK_OPTION, &RacksView::OnRackInsert)
	ON_COMMAND(UPDATE_RACK_OPTION, &RacksView::OnRackUpdate)
	ON_COMMAND(PREVIEW_RACK_OPTION, &RacksView::OnRackPreview)
	ON_COMMAND(DELETE_RACK_OPTION, &RacksView::OnRackDelete)
	ON_WM_PAINT()
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()

// RacksView diagnostics

#ifdef _DEBUG
void RacksView::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void RacksView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif
#endif //_DEBUG

RacksDocument * RacksView::GetDocument() const
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(RacksDocument)));
	return (RacksDocument*)m_pDocument;
}

void RacksView::OnContextMenu(CWnd * pWnd, CPoint point)
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
		MainMenu.AppendMenu(MF_STRING, INSERT_RACK_OPTION, _T("Add Rack"));
		if (listCtrl.GetNextItem(-1, LVNI_SELECTED) > -1)
		{
			MainMenu.AppendMenu(MF_STRING, UPDATE_RACK_OPTION, _T("Update Rack"));
			MainMenu.AppendMenu(MF_STRING, DELETE_RACK_OPTION, _T("Delete Rack"));
			MainMenu.AppendMenu(MF_STRING, PREVIEW_RACK_OPTION, _T("Preview Rack"));
		}

		//Display the Popup Menu
		MainMenu.TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);
	}
	else
	{
		CWnd::OnContextMenu(pWnd, point);
	}
}

void RacksView::OnRackInsert()
{
	//Взимаме документа
	RacksDocument* racksDocument = GetDocument();
	ShelvesArray empty;
	//Инициализираме диалога със съответните заглавие и полета
	RACKS rack;
	RacksDialog dialog(rack, empty, DialogModeInsert);

	if (dialog.DoModal() != IDOK)
		return;

	racksDocument->InsertRack(rack);
}

void RacksView::OnRackPreview()
{	
	//Взимаме документа
	RacksDocument* racksDocument = GetDocument();

	//Взимаме select-натия Rack
	int index = listCtrl.GetSelectionMark();
	long ID = (long)listCtrl.GetItemData(index);

	//взимаме актуалния Rack от базата
	RACKS rack;
	ShelvesArray shelvesArray;
	if (racksDocument->SelectByID(ID, rack, shelvesArray) == FALSE)
		return;

	//Инициализираме диалога със съответните заглавие и полета
	RacksDialog dialog(rack, shelvesArray, DialogModePreview);

	dialog.DoModal();
}

void RacksView::OnRackDelete()
{
	//Взимаме документа
	RacksDocument* racksDocument = GetDocument();

	//Взимаме select-натия Rack
	int index = listCtrl.GetSelectionMark();
	long ID = (long)listCtrl.GetItemData(index);

	//взимаме актуалния Rack от базата 
	RACKS rack;
	ShelvesArray shelvesArray;
	if (racksDocument->SelectByID(ID, rack, shelvesArray) == FALSE)
		return;

	//Инициализираме диалога със съответните заглавие и полета
	RacksDialog dialog(rack, shelvesArray, DialogModeDelete);

	if (dialog.DoModal() != IDOK)
		return;

	GetDocument()->DeleteByID(ID);
}

void RacksView::OnRackUpdate()
{
	//Взимаме документа
	RacksDocument* racksDocument = GetDocument();

	//Взимаме ID на select-натия person
	int index = listCtrl.GetSelectionMark();
	long ID = (long)listCtrl.GetItemData(index);

	//взимаме актуалния Shelf от базата 
	RACKS rack;
	ShelvesArray shelvesArray;
	if (racksDocument->SelectByID(ID, rack, shelvesArray) == FALSE)
		return;

	//Инициализираме диалога със съответните заглавие и полета
	RacksDialog dialog(rack, shelvesArray, DialogModeUpdate);

	if (dialog.DoModal() != IDOK)
		return;

	GetDocument()->UpdateRack(rack);
}

void RacksView::OnUpdate(CView * pSender, LPARAM lHint, CObject * pHint)
{
	switch (lHint)
	{
	case (UpdateCodes::UpdateCodeUpdate):
	{
		UpdateRackInListCtrl(pHint);
		break;
	}
	case (UpdateCodes::UpdateCodeInsert):
	{
		InsertRackInListCtrl(pHint);
		break;
	}
	case (UpdateCodes::UpdateCodeDelete):
	{
		DeleteRackInListCtrl(pHint);
		break;
	}
	default:
		break;
	}
	__super::OnUpdate(pSender, lHint, pHint);
}

void RacksView::OnInitialUpdate()
{
	SetColumnsRacksListCtrl();

	CListView::OnInitialUpdate();

	if (GetDocument()->SelectAll() == FALSE)
	{
		return;
	}

	for (int i = 0; i < GetDocument()->GetRacksArray().GetCount(); i++)
	{
		RACKS* rack = GetDocument()->GetRacksArray().GetAt(i);
		CString strID;
		strID.Format(_T("%d"), rack->ID);

		int index = listCtrl.InsertItem(0, rack->rackName);
		listCtrl.SetItemText(index, 1, rack->rackName);
		listCtrl.SetItemText(index, 2, strID);
		listCtrl.SetItemData(index, rack->ID);
	}

	listCtrl.DeleteColumn(0);
}

// RacksView message handlers

void RacksView::DeleteRackInListCtrl(CObject * pHint)
{
	for (int i = 0; i < listCtrl.GetItemCount(); i++)
	{
		RACKS* rack = (RACKS*)pHint;
		if (listCtrl.GetItemData(i) == rack->ID)
		{
			listCtrl.DeleteItem(i);
			break;
		}
	}
}

void RacksView::UpdateRackInListCtrl(CObject * pHint)
{
	for (int i = 0; i < listCtrl.GetItemCount(); i++)
	{
		RACKS* rack = (RACKS*)pHint;
		if (listCtrl.GetItemData(i) == rack->ID)
		{
			CString strID;
			strID.Format(_T("%d"), rack->ID);

			listCtrl.SetItemText(i, 0, rack->rackName);
			listCtrl.SetItemText(i, 1, strID);
			listCtrl.SetItemData(i, rack->ID);

			break;
		}//if
	}//for
}

void RacksView::InsertRackInListCtrl(CObject * pHint)
{
	RACKS* rack = (RACKS*)pHint;
	CString strID;
	strID.Format(_T("%d"), rack->ID);
	int index = listCtrl.InsertItem(0, rack->rackName);
	listCtrl.SetItemText(index, 1, strID);
	listCtrl.SetItemData(index, rack->ID);
}

void RacksView::SetColumnsRacksListCtrl()
{
	listCtrl.SetView(LVS_REPORT);
	//todo: LVS_SINGLESEL
	listCtrl.SetExtendedStyle(listCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT);

	listCtrl.InsertColumn(0, _T(""), LVCFMT_RIGHT);
	listCtrl.InsertColumn(1, _T("Rack name"), LVCFMT_RIGHT, COLUMN_WIDTH_BASIC);
	listCtrl.InsertColumn(2, _T("Rack number"), LVCFMT_RIGHT, COLUMN_WIDTH_BASIC);
}
