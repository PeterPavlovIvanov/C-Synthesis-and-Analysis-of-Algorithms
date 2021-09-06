// CategoriesView.cpp : implementation file
//

#include "stdafx.h"
#include "PCShop.h"
#include "CategoriesView.h"
#include "CategoriesDialog.h"

// CategoriesView

IMPLEMENT_DYNCREATE(CategoriesView, CListView)

CategoriesView::CategoriesView()
{

}

CategoriesView::~CategoriesView()
{
}

BEGIN_MESSAGE_MAP(CategoriesView, CListView)
	ON_COMMAND(INSERT_CATEGORY_OPTION, &CategoriesView::OnCategoryInsert)
	ON_COMMAND(UPDATE_CATEGORY_OPTION, &CategoriesView::OnCategoryUpdate)
	ON_COMMAND(PREVIEW_CATEGORY_OPTION, &CategoriesView::OnCategoryPreview)
	ON_COMMAND(DELETE_CATEGORY_OPTION, &CategoriesView::OnCategoryDelete)
	ON_WM_PAINT()
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()


// CategoriesView diagnostics

#ifdef _DEBUG
void CategoriesView::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void CategoriesView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

void CategoriesView::OnInitialUpdate()
{
	SetColumnsCategoriesListCtrl();

	CListView::OnInitialUpdate();

	if (GetDocument()->SelectAll() == FALSE)
	{
		return;
	}

	for (int i = 0; i < GetDocument()->GetCategoriesArray().GetCount(); i++)
	{
		CATEGORIES* category = GetDocument()->GetCategoriesArray().GetAt(i);

		int index = listCtrl.InsertItem(0, category->categoryName);
		listCtrl.SetItemText(index, 1, category->categoryName);

		listCtrl.SetItemData(index, category->ID);
	}

	listCtrl.DeleteColumn(0);
}

CategoriesDocument * CategoriesView::GetDocument() const
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CategoriesDocument)));
	return (CategoriesDocument*)m_pDocument;
}

void CategoriesView::OnContextMenu(CWnd * pWnd, CPoint point)
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
		MainMenu.AppendMenu(MF_STRING, INSERT_CATEGORY_OPTION, _T("Add Category"));
		if (listCtrl.GetNextItem(-1, LVNI_SELECTED) > -1)
		{
			MainMenu.AppendMenu(MF_STRING, UPDATE_CATEGORY_OPTION, _T("Update Category"));
			MainMenu.AppendMenu(MF_STRING, DELETE_CATEGORY_OPTION, _T("Delete Category"));
			MainMenu.AppendMenu(MF_STRING, PREVIEW_CATEGORY_OPTION, _T("Preview Category"));
		}

		//Display the Popup Menu
		MainMenu.TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);
	}
	else
	{
		CWnd::OnContextMenu(pWnd, point);
	}
}

void CategoriesView::OnCategoryInsert()
{
	//Взимаме документа
	CategoriesDocument* categoriesDocument = GetDocument();

	//Инициализираме диалога със съответните заглавие и полета
	CATEGORIES category;
	CategoriesDialog dialog(category, DialogModeInsert);

	if (dialog.DoModal() != IDOK)
		return;

	categoriesDocument->InsertCategory(category);
}

void CategoriesView::OnCategoryPreview()
{
	//Взимаме документа
	CategoriesDocument* categoriesDocument = GetDocument();

	//Взимаме select-натото Category
	int index = listCtrl.GetSelectionMark();
	long ID = (long)listCtrl.GetItemData(index);

	//взимаме актуалнoто Category от базата
	CATEGORIES category;
	if (categoriesDocument->SelectByID(ID, category) == FALSE)
		return;

	//Инициализираме диалога със съответните заглавие и полета
	CategoriesDialog dialog(category, DialogModePreview);

	dialog.DoModal();
}

void CategoriesView::OnCategoryDelete()
{
	//Взимаме документа
	CategoriesDocument* categoriesDocument = GetDocument();

	//Взимаме select-натото Category
	int index = listCtrl.GetSelectionMark();
	long ID = (long)listCtrl.GetItemData(index);

	//взимаме актуалнoто Category от базата
	CATEGORIES category;
 	if (categoriesDocument->SelectByID(ID, category) == FALSE)
		return;

	//Инициализираме диалога със съответните заглавие и полета
	CategoriesDialog dialog(category, DialogModeDelete);

	if (dialog.DoModal() != IDOK)
		return;

	GetDocument()->DeleteByID(ID);
}

void CategoriesView::OnCategoryUpdate()
{
	//Взимаме документа
	CategoriesDocument* categoriesDocument = GetDocument();

	//Взимаме select-натото Category
	int index = listCtrl.GetSelectionMark();
	long ID = (long)listCtrl.GetItemData(index);

	//взимаме актуалнoто Category от базата
	CATEGORIES category;
	if (categoriesDocument->SelectByID(ID, category) == FALSE)
		return;

	//Инициализираме диалога със съответните заглавие и полета
	CategoriesDialog dialog(category, DialogModeUpdate);

	if (dialog.DoModal() != IDOK)
		return;

	GetDocument()->UpdateCategory(category);
}

void CategoriesView::OnUpdate(CView * pSender, LPARAM lHint, CObject * pHint)
{
	switch (lHint)
	{
	case (UpdateCodes::UpdateCodeUpdate):
	{
		UpdateCategoryInListCtrl(pHint);
		break;
	}
	case (UpdateCodes::UpdateCodeInsert):
	{
		InsertCategoryInListCtrl(pHint);
		break;
	}
	case (UpdateCodes::UpdateCodeDelete):
	{
		DeleteCategoryInListCtrl(pHint);
		break;
	}
	default:
		break;
	}
	__super::OnUpdate(pSender, lHint, pHint);
}

void CategoriesView::UpdateCategoryInListCtrl(CObject * pHint)
{
	for (int i = 0; i < listCtrl.GetItemCount(); i++)
	{
		CATEGORIES* category = (CATEGORIES*)pHint;
		if (listCtrl.GetItemData(i) == category->ID)
		{
			listCtrl.SetItemText(i, 0, category->categoryName);
			break;
		}//if
	}//for
}

void CategoriesView::InsertCategoryInListCtrl(CObject * pHint)
{
	CATEGORIES* category = (CATEGORIES*)pHint;
	int index = listCtrl.InsertItem(0, category->categoryName);
	listCtrl.SetItemData(index, category->ID);
}

void CategoriesView::DeleteCategoryInListCtrl(CObject * pHint)
{
	for (int i = 0; i < listCtrl.GetItemCount(); i++)
	{
		CATEGORIES* category = (CATEGORIES*)pHint;
		if (listCtrl.GetItemData(i) == category->ID)
		{
			listCtrl.DeleteItem(i);
			break;
		}
	}
}

void CategoriesView::SetColumnsCategoriesListCtrl()
{
	listCtrl.SetView(LVS_REPORT);
	//todo: LVS_SINGLESEL
	listCtrl.SetExtendedStyle(listCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT);

	listCtrl.InsertColumn(0, _T(""), LVCFMT_RIGHT);
	listCtrl.InsertColumn(1, _T("Category name"), LVCFMT_RIGHT, COLUMN_WIDTH_BASIC);
}

#endif
#endif //_DEBUG


// CategoriesView message handlers
