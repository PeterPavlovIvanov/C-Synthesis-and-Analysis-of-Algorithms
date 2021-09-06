// ShelvesView.cpp : implementation file
//

#include "stdafx.h"
#include "PCShop.h"
#include "ShelvesView.h"
#include "TypeDefs.h" 
#include "ShelvesDialog.h"
#include "UpdateCodes.h"

// ShelvesView

IMPLEMENT_DYNCREATE(ShelvesView, CListView)

ShelvesView::ShelvesView()
{

}

ShelvesView::~ShelvesView()
{
}


BEGIN_MESSAGE_MAP(ShelvesView, CListView)
	ON_COMMAND(INSERT_SHELF_OPTION, &ShelvesView::OnShelfInsert)
	ON_COMMAND(UPDATE_SHELF_OPTION, &ShelvesView::OnShelfUpdate)
	ON_COMMAND(PREVIEW_SHELF_OPTION, &ShelvesView::OnShelfPreview)
	ON_COMMAND(DELETE_SHELF_OPTION, &ShelvesView::OnShelfDelete)
	ON_WM_PAINT()
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()

// ShelvesView diagnostics

#ifdef _DEBUG
void ShelvesView::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void ShelvesView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif
#endif //_DEBUG
ShelvesDocument * ShelvesView::GetDocument() const
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(ShelvesDocument)));
	return (ShelvesDocument*)m_pDocument;
}

void ShelvesView::OnContextMenu(CWnd * pWnd, CPoint point)
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
		MainMenu.AppendMenu(MF_STRING, INSERT_SHELF_OPTION, _T("Add Shelf"));
		if (listCtrl.GetNextItem(-1, LVNI_SELECTED) > -1)
		{
			MainMenu.AppendMenu(MF_STRING, UPDATE_SHELF_OPTION, _T("Update Shelf"));
			MainMenu.AppendMenu(MF_STRING, DELETE_SHELF_OPTION, _T("Delete Shelf"));
			MainMenu.AppendMenu(MF_STRING, PREVIEW_SHELF_OPTION, _T("Preview Shelf"));
		}

		//Display the Popup Menu
		MainMenu.TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);
	}
	else
	{
		CWnd::OnContextMenu(pWnd, point);
	}
}

void ShelvesView::OnShelfInsert()
{
	//Взимаме документа
	ShelvesDocument* shelvesDocument = GetDocument();

	//Инициализираме диалога със съответните заглавие и полета
	SHELVES shelf;
	ShelvesDialog shelfDialog(shelf, shelvesDocument->GetRacksArray(), DialogModeInsert);

	if (shelfDialog.DoModal() != IDOK)
		return;

	shelvesDocument->InsertShelf(shelf);
}

void ShelvesView::OnShelfPreview()
{	
	//Взимаме документа
	ShelvesDocument* shelvesDocument = GetDocument();

	//Взимаме select-натия Shelf
	int index = listCtrl.GetSelectionMark();
	long ID = (long)listCtrl.GetItemData(index);

	//взимаме актуалния Shelf от базата
	SHELVES shelf;
	if (shelvesDocument->SelectByID(ID, shelf) == FALSE)
		return;

	//Инициализираме диалога със съответните заглавие и полета
	ShelvesDialog shelfDialog(shelf, shelvesDocument->GetRacksArray(), DialogModePreview);

	shelfDialog.DoModal();
}

void ShelvesView::OnShelfDelete()
{
	//Взимаме документа
	ShelvesDocument* shelvesDocument = GetDocument();

	//Взимаме select-натия Shelf
	int index = listCtrl.GetSelectionMark();
	long ID = (long)listCtrl.GetItemData(index);

	//взимаме актуалния Shelf от базата 
	SHELVES shelf;
	if (shelvesDocument->SelectByID(ID, shelf) == FALSE)
		return;

	//Инициализираме диалога със съответните заглавие и полета
	ShelvesDialog shelfDialog(shelf, shelvesDocument->GetRacksArray(), DialogModeDelete);

	if (shelfDialog.DoModal() != IDOK)
		return;

	GetDocument()->DeleteByID(ID);
}

void ShelvesView::OnShelfUpdate()
{
	//Взимаме документа
	ShelvesDocument* shelvesDocument = GetDocument();

	//Взимаме ID на select-натия shelf
	int index = listCtrl.GetSelectionMark();
	long ID = (long)listCtrl.GetItemData(index);

	//взимаме актуалния Shelf от базата 
	SHELVES shelf;
	if (shelvesDocument->SelectByID(ID, shelf) == FALSE)
		return;

	//Инициализираме диалога със съответните заглавие и полета
	ShelvesDialog shelfDialog(shelf, shelvesDocument->GetRacksArray(), DialogModeUpdate);

	if (shelfDialog.DoModal() != IDOK)
		return;

	GetDocument()->UpdateShelf(shelf);
}

void ShelvesView::OnInitialUpdate()
{
	SetColumnsShelvesListCtrl();

	CListView::OnInitialUpdate();

	if (GetDocument()->SelectAll() == FALSE)
	{
		return;
	}

	for (int i = 0; i < GetDocument()->GetShelvesArray().GetCount(); i++)
	{
		SHELVES* shelf = GetDocument()->GetShelvesArray().GetAt(i);
		RACKS* rack = NULL;

		CString strID;
		strID.Format(_T("%d"), shelf->ID);

		for(int j = 0; j < GetDocument()->GetRacksArray().GetCount(); j++)
			if (GetDocument()->GetRacksArray().GetAt(j)->ID == shelf->rackID)
			{
				rack = GetDocument()->GetRacksArray().GetAt(j);
				break;
			}

		if (!rack)
			continue;

		int index = listCtrl.InsertItem(0, shelf->shelfName);
		listCtrl.SetItemText(index, 1, shelf->shelfName);
		listCtrl.SetItemText(index, 2, rack->rackName);
		listCtrl.SetItemText(index, 3, strID);
		listCtrl.SetItemData(index, shelf->ID);
	}

	listCtrl.DeleteColumn(0);
}
// ShelvesView message handlers


void ShelvesView::SetColumnsShelvesListCtrl()
{
	listCtrl.SetView(LVS_REPORT);
	//todo: LVS_SINGLESEL
	listCtrl.SetExtendedStyle(listCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT);

	listCtrl.InsertColumn(0, _T(""), LVCFMT_RIGHT);
	listCtrl.InsertColumn(1, _T("Shelf name"), LVCFMT_RIGHT, COLUMN_WIDTH_BASIC);
	listCtrl.InsertColumn(2, _T("Rack name"), LVCFMT_RIGHT, COLUMN_WIDTH_BASIC);
	listCtrl.InsertColumn(3, _T("Shelf number"), LVCFMT_RIGHT, COLUMN_WIDTH_BASIC);
}

void ShelvesView::OnUpdate(CView * pSender, LPARAM lHint, CObject * pHint)
{
	switch (lHint)
	{
	case (UpdateCodes::UpdateCodeUpdate):
	{
		UpdateShelfInListCtrl(pHint);
		break;
	}
	case (UpdateCodes::UpdateCodeInsert):
	{
		InsertShelfInListCtrl(pHint);
		break;
	}
	case (UpdateCodes::UpdateCodeDelete):
	{
		DeleteShelfInListCtrl(pHint);
		break;
	}
	default:
		break;
	}
	__super::OnUpdate(pSender, lHint, pHint);
}

void ShelvesView::UpdateShelfInListCtrl(CObject * pHint)
{
	for (int i = 0; i < listCtrl.GetItemCount(); i++)
	{
		SHELVES* shelf = (SHELVES*)pHint;
		if (listCtrl.GetItemData(i) == shelf->ID)
		{
			CString strID;
			strID.Format(_T("%d"), shelf->ID);

			listCtrl.SetItemText(i, 0, shelf->shelfName);
			SetTextOnRow(i, shelf, strID);

			break;
		}//if
	}//for
}

void ShelvesView::InsertShelfInListCtrl(CObject * pHint)
{
	SHELVES* shelf = (SHELVES*)pHint;
	CString strID;
	strID.Format(_T("%d"), shelf->ID);
	int index = listCtrl.InsertItem(0, shelf->shelfName);
	SetTextOnRow(index, shelf, strID);
	listCtrl.SetItemData(index, shelf->ID);
}

void ShelvesView::DeleteShelfInListCtrl(CObject * pHint)
{
	for (int i = 0; i < listCtrl.GetItemCount(); i++)
	{
		SHELVES* shelf = (SHELVES*)pHint;
		if (listCtrl.GetItemData(i) == shelf->ID)
		{
			listCtrl.DeleteItem(i);
			break;
		}
	}
}


void ShelvesView::SetTextOnRow(int index, SHELVES * shelf, CString strID)
{
	RACKS* rack = NULL;

	for (int j = 0; j < GetDocument()->GetRacksArray().GetCount(); j++)
		if (GetDocument()->GetRacksArray().GetAt(j)->ID == shelf->rackID)
		{
			rack = GetDocument()->GetRacksArray().GetAt(j);
			break;
		}

	if (!rack)
		return;

	listCtrl.SetItemText(index, 1, rack->rackName);
	listCtrl.SetItemText(index, 2, strID);
}