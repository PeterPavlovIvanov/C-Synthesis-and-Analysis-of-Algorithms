// ModelsView.cpp : implementation file
//

#include "stdafx.h"
#include "PCShop.h"
#include "ModelsView.h"
#include "TypeDefs.h" 

// ModelsView

IMPLEMENT_DYNCREATE(ModelsView, CListView)

BEGIN_MESSAGE_MAP(ModelsView, CListView)
	/*ON_COMMAND(INSERT_OPTION_ID, &CCitiesView::OnCitiesInsert)
	ON_COMMAND(VIEW_OPTION_ID, &CCitiesView::OnView)
	ON_COMMAND(DELETE_OPTION_ID, &CCitiesView::OnDelete)
	ON_COMMAND(UPDATE_OPTION_ID, &CCitiesView::OnCityUpdate)*/
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

		int nIndex = m_ListCtrl.InsertItem(0, model->modelName);
		m_ListCtrl.SetItemText(nIndex, 1, model->modelName);
		m_ListCtrl.SetItemText(nIndex, 2, brand->brandName);
		m_ListCtrl.SetItemText(nIndex, 3, strID);
	}

	m_ListCtrl.DeleteColumn(0);
}

// ModelsView message handlers

void ModelsView::SetColumnsModelsListCtrl()
{
	m_ListCtrl.SetView(LVS_REPORT);
	//todo: LVS_SINGLESEL
	m_ListCtrl.SetExtendedStyle(m_ListCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT);

	m_ListCtrl.InsertColumn(0, _T(""), LVCFMT_RIGHT);
	m_ListCtrl.InsertColumn(1, _T("MODEL_NAME"), LVCFMT_RIGHT, COLUMN_WIDTH_BASIC);
	m_ListCtrl.InsertColumn(2, _T("BRAND_NAME"), LVCFMT_RIGHT, COLUMN_WIDTH_BASIC);
	m_ListCtrl.InsertColumn(3, _T("ID"), LVCFMT_RIGHT, COLUMN_WIDTH_BASIC);
}

void ModelsView::OnContextMenu(CWnd * pWnd, CPoint point)
{
}
