// BrandsView.cpp : implementation file
//

#include "stdafx.h"
#include "PCShop.h"
#include "BrandsView.h"
#include "TypeDefs.h" 
#include "UpdateCodes.h"
#include "BrandsDialog.h"

// BrandsView

IMPLEMENT_DYNCREATE(BrandsView, CListView)

BrandsView::BrandsView()
{

}

BrandsView::~BrandsView()
{
}

BEGIN_MESSAGE_MAP(BrandsView, CListView)
	ON_COMMAND(INSERT_BRAND_OPTION, &BrandsView::OnBrandInsert)
	ON_COMMAND(UPDATE_BRAND_OPTION, &BrandsView::OnBrandUpdate)
	ON_COMMAND(PREVIEW_BRAND_OPTION, &BrandsView::OnBrandPreview)
	ON_COMMAND(DELETE_BRAND_OPTION, &BrandsView::OnBrandDelete)
	ON_WM_PAINT()
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()


// BrandsView diagnostics

#ifdef _DEBUG
void BrandsView::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void BrandsView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif
#endif //_DEBUG

BrandsDocument * BrandsView::GetDocument() const
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(BrandsDocument)));
	return (BrandsDocument*)m_pDocument;
}

void BrandsView::OnContextMenu(CWnd * pWnd, CPoint point)
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
		MainMenu.AppendMenu(MF_STRING, INSERT_BRAND_OPTION, _T("Add Brand"));
		if (listCtrl.GetNextItem(-1, LVNI_SELECTED) > -1)
		{
			MainMenu.AppendMenu(MF_STRING, UPDATE_BRAND_OPTION, _T("Update Brand"));
			MainMenu.AppendMenu(MF_STRING, DELETE_BRAND_OPTION, _T("Delete Brand"));
			MainMenu.AppendMenu(MF_STRING, PREVIEW_BRAND_OPTION, _T("Preview Brand"));
		}

		//Display the Popup Menu
		MainMenu.TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);
	}
	else
	{
		CWnd::OnContextMenu(pWnd, point);
	}
}

void BrandsView::OnBrandInsert()
{
	//Взимаме документа
	BrandsDocument* brandsDocument = GetDocument();
	ModelsArray empty;
	//Инициализираме диалога със съответните заглавие и полета
	BRANDS brand;
	BrandsDialog dialog(brand, empty, DialogModeInsert);

	if (dialog.DoModal() != IDOK)
		return;

	brandsDocument->InsertBrand(brand);
}

void BrandsView::OnBrandPreview()
{
	//Взимаме документа
	BrandsDocument* brandsDocument = GetDocument();

	int index = listCtrl.GetSelectionMark();
	long ID = (long)listCtrl.GetItemData(index);

	BRANDS brand;
	ModelsArray modelsArray;
	if (brandsDocument->SelectByID(ID, brand, modelsArray) == FALSE)
		return;

	//Инициализираме диалога със съответните заглавие и полета
	BrandsDialog dialog(brand, modelsArray, DialogModePreview);

	dialog.DoModal();
}

void BrandsView::OnBrandDelete()
{
	//Взимаме документа
	BrandsDocument* brandsDocument = GetDocument();

	int index = listCtrl.GetSelectionMark();
	long ID = (long)listCtrl.GetItemData(index);

	BRANDS brand;
	ModelsArray modelsArray;
	if (brandsDocument->SelectByID(ID, brand, modelsArray) == FALSE)
		return;

	//Инициализираме диалога със съответните заглавие и полета
	BrandsDialog dialog(brand, modelsArray, DialogModeDelete);

	if (dialog.DoModal() != IDOK)
		return;

	GetDocument()->DeleteByID(ID);
}

void BrandsView::OnBrandUpdate()
{
	//Взимаме документа
	BrandsDocument* brandsDocument = GetDocument();

	int index = listCtrl.GetSelectionMark();
	long ID = (long)listCtrl.GetItemData(index);

	BRANDS brand;
	ModelsArray modelsArray;
	if (brandsDocument->SelectByID(ID, brand, modelsArray) == FALSE)
		return;

	//Инициализираме диалога със съответните заглавие и полета
	BrandsDialog dialog(brand, modelsArray, DialogModeUpdate);

	if (dialog.DoModal() != IDOK)
		return;

	GetDocument()->UpdateBrand(brand);
}

void BrandsView::OnUpdate(CView * pSender, LPARAM lHint, CObject * pHint)
{
	switch (lHint)
	{
	case (UpdateCodes::UpdateCodeUpdate):
	{
		UpdateBrandInListCtrl(pHint);
		break;
	}
	case (UpdateCodes::UpdateCodeInsert):
	{
		InsertBrandInListCtrl(pHint);
		break;
	}
	case (UpdateCodes::UpdateCodeDelete):
	{
		DeleteBrandInListCtrl(pHint);
		break;
	}
	default:
		break;
	}
	__super::OnUpdate(pSender, lHint, pHint);
}

void BrandsView::UpdateBrandInListCtrl(CObject * pHint)
{
	for (int i = 0; i < listCtrl.GetItemCount(); i++)
	{
		BRANDS* brand = (BRANDS*)pHint;
		if (listCtrl.GetItemData(i) == brand->ID)
		{
			listCtrl.SetItemText(i, 0, brand->brandName);
			listCtrl.SetItemData(i, brand->ID);

			break;
		}//if
	}//for
}

void BrandsView::InsertBrandInListCtrl(CObject * pHint)
{
	BRANDS* brand = (BRANDS*)pHint;
	int index = listCtrl.InsertItem(0, brand->brandName);
	listCtrl.SetItemData(index, brand->ID);
}

void BrandsView::DeleteBrandInListCtrl(CObject * pHint)
{
	for (int i = 0; i < listCtrl.GetItemCount(); i++)
	{
		BRANDS* brand = (BRANDS*)pHint;
		if (listCtrl.GetItemData(i) == brand->ID)
		{
			listCtrl.DeleteItem(i);
			break;
		}
	}
}

void BrandsView::OnInitialUpdate()
{
	SetColumnsBrandsListCtrl();

	CListView::OnInitialUpdate();

	if (GetDocument()->SelectAll() == FALSE)
	{
		return;
	}

	for (int i = 0; i < GetDocument()->GetBrandsArray().GetCount(); i++)
	{
		BRANDS* brand = GetDocument()->GetBrandsArray().GetAt(i);
		CString strID;
		strID.Format(_T("%d"), brand->ID);

		int index = listCtrl.InsertItem(0, brand->brandName);
		listCtrl.SetItemText(index, 1, brand->brandName);
		listCtrl.SetItemData(index, brand->ID);
	}

	listCtrl.DeleteColumn(0);
}

// BrandsView message handlers

void BrandsView::SetColumnsBrandsListCtrl()
{
	listCtrl.SetView(LVS_REPORT);
	//todo: LVS_SINGLESEL
	listCtrl.SetExtendedStyle(listCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT);

	listCtrl.InsertColumn(0, _T(""), LVCFMT_RIGHT);
	listCtrl.InsertColumn(1, _T("BRAND_NAME"), LVCFMT_CENTER, COLUMN_WIDTH_BASIC);
}


