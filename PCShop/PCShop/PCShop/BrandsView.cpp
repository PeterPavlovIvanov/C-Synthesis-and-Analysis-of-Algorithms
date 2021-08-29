// BrandsView.cpp : implementation file
//

#include "stdafx.h"
#include "PCShop.h"
#include "BrandsView.h"
#include "TypeDefs.h" 

// BrandsView

IMPLEMENT_DYNCREATE(BrandsView, CListView)

BrandsView::BrandsView()
{

}

BrandsView::~BrandsView()
{
}

BEGIN_MESSAGE_MAP(BrandsView, CListView)
	/*ON_COMMAND(INSERT_OPTION_ID, &CCitiesView::OnCitiesInsert)
	ON_COMMAND(VIEW_OPTION_ID, &CCitiesView::OnView)
	ON_COMMAND(DELETE_OPTION_ID, &CCitiesView::OnDelete)
	ON_COMMAND(UPDATE_OPTION_ID, &CCitiesView::OnCityUpdate)*/
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
};

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

		int nIndex = m_ListCtrl.InsertItem(0, brand->brandName);
		m_ListCtrl.SetItemText(nIndex, 1, brand->brandName);
		m_ListCtrl.SetItemText(nIndex, 2, strID);
	}

	m_ListCtrl.DeleteColumn(0);
}

// BrandsView message handlers

void BrandsView::SetColumnsBrandsListCtrl()
{
	m_ListCtrl.SetView(LVS_REPORT);
	//todo: LVS_SINGLESEL
	m_ListCtrl.SetExtendedStyle(m_ListCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT);

	m_ListCtrl.InsertColumn(0, _T(""), LVCFMT_RIGHT);
	m_ListCtrl.InsertColumn(1, _T("BRAND_NAME"), LVCFMT_CENTER, COLUMN_WIDTH_BASIC);
	m_ListCtrl.InsertColumn(2, _T("ID"), LVCFMT_CENTER, COLUMN_WIDTH_BASIC);
}


