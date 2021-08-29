// RacksView.cpp : implementation file
//

#include "stdafx.h"
#include "PCShop.h"
#include "RacksView.h"
#include "TypeDefs.h" 
// RacksView

IMPLEMENT_DYNCREATE(RacksView, CListView)

RacksView::RacksView()
{

}

RacksView::~RacksView()
{
}

BEGIN_MESSAGE_MAP(RacksView, CListView)
	/*ON_COMMAND(INSERT_OPTION_ID, &CCitiesView::OnCitiesInsert)
	ON_COMMAND(VIEW_OPTION_ID, &CCitiesView::OnView)
	ON_COMMAND(DELETE_OPTION_ID, &CCitiesView::OnDelete)
	ON_COMMAND(UPDATE_OPTION_ID, &CCitiesView::OnCityUpdate)*/
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
}
;

void RacksView::OnInitialUpdate()
{
	SetColumnsCitiesListCtrl();

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

		int nIndex = m_ListCtrl.InsertItem(0, rack->rackName);
		m_ListCtrl.SetItemText(nIndex, 1, rack->rackName);
		m_ListCtrl.SetItemText(nIndex, 2, strID);
	}

	m_ListCtrl.DeleteColumn(0);
}

// RacksView message handlers

void RacksView::SetColumnsCitiesListCtrl()
{
	m_ListCtrl.SetView(LVS_REPORT);
	//todo: LVS_SINGLESEL
	m_ListCtrl.SetExtendedStyle(m_ListCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT);

	m_ListCtrl.InsertColumn(0, _T(""), LVCFMT_RIGHT);
	m_ListCtrl.InsertColumn(1, _T("RACK_NAME"), LVCFMT_RIGHT, COLUMN_WIDTH_BASIC);
	m_ListCtrl.InsertColumn(2, _T("ID"), LVCFMT_RIGHT, COLUMN_WIDTH_BASIC);
}

