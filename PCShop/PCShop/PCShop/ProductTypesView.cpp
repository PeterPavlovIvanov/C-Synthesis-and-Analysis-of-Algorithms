// ProductTypesView.cpp : implementation file
//

#include "stdafx.h"
#include "PCShop.h"
#include "ProductTypesView.h"
#include "TypeDefs.h" 

// ProductTypesView

IMPLEMENT_DYNCREATE(ProductTypesView, CListView)

ProductTypesView::ProductTypesView()
{

}

ProductTypesView::~ProductTypesView()
{
}

BEGIN_MESSAGE_MAP(ProductTypesView, CListView)
	/*ON_COMMAND(INSERT_OPTION_ID, &CCitiesView::OnCitiesInsert)
	ON_COMMAND(VIEW_OPTION_ID, &CCitiesView::OnView)
	ON_COMMAND(DELETE_OPTION_ID, &CCitiesView::OnDelete)
	ON_COMMAND(UPDATE_OPTION_ID, &CCitiesView::OnCityUpdate)*/
	ON_WM_PAINT()
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()

// ProductTypesView diagnostics

#ifdef _DEBUG
void ProductTypesView::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void ProductTypesView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif
#endif //_DEBUG

ProductTypesDocument * ProductTypesView::GetDocument() const
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(ProductTypesDocument)));
	return (ProductTypesDocument*)m_pDocument;
}

void ProductTypesView::OnContextMenu(CWnd * pWnd, CPoint point)
{
};

void ProductTypesView::OnInitialUpdate()
{
	SetColumnsProductTypesListCtrl();

	CListView::OnInitialUpdate();

	if (GetDocument()->SelectAll() == FALSE)
		return;

	for (int i = 0; i < GetDocument()->GetProductTypesArray().GetCount(); i++)
	{
		PRODUCT_TYPES* productType = GetDocument()->GetProductTypesArray().GetAt(i);
		CATEGORIES* category = NULL;
		BRANDS* brand = NULL;
		MODELS* model = NULL;

		//get the category of the current product Type
		for (int j = 0; j < GetDocument()->GetCategoriesArray().GetCount(); j++)
			if (GetDocument()->GetCategoriesArray().GetAt(j)->ID == productType->categoryID)
			{
				category = GetDocument()->GetCategoriesArray().GetAt(j);
				break;
			}

		//get the brand of the current product Type
		for (int j = 0; j < GetDocument()->GetBrandsArray().GetCount(); j++)
			if (GetDocument()->GetBrandsArray().GetAt(j)->ID == productType->brandID)
			{
				brand = GetDocument()->GetBrandsArray().GetAt(j);
				break;
			}

		//get the model of the current product Type
		for (int j = 0; j < GetDocument()->GetModelsArray().GetCount(); j++)
			if (GetDocument()->GetModelsArray().GetAt(j)->ID == productType->modelID)
			{
				model = GetDocument()->GetModelsArray().GetAt(j);
				break;
			}

		if (!(category && brand && model))
			continue;

		CString strPrice;
		strPrice.Format(_T("%.2f"), productType->price);

		int nIndex = listControl.InsertItem(0, productType->productName);
		listControl.SetItemText(nIndex, 1, productType->productName);
		listControl.SetItemText(nIndex, 2, productType->description);
		listControl.SetItemText(nIndex, 3, strPrice);
		listControl.SetItemText(nIndex, 4, brand->brandName);
		listControl.SetItemText(nIndex, 5, model->modelName);
		listControl.SetItemText(nIndex, 6, category->categoryName);
	}

	listControl.DeleteColumn(0);
}

// ProductTypesView message handlers

void ProductTypesView::SetColumnsProductTypesListCtrl()
{
	listControl.SetView(LVS_REPORT);
	//todo: LVS_SINGLESEL
	listControl.SetExtendedStyle(listControl.GetExtendedStyle() | LVS_EX_FULLROWSELECT);

	listControl.InsertColumn(0, _T(""), LVCFMT_RIGHT);
	listControl.InsertColumn(1, _T("PRODUCT_NAME"), LVCFMT_RIGHT, COLUMN_WIDTH_BASIC);
	listControl.InsertColumn(2, _T("DESCRIPTION"), LVCFMT_RIGHT, COLUMN_WIDTH_DESCRIPTION);
	listControl.InsertColumn(3, _T("PRICE"), LVCFMT_RIGHT, COLUMN_WIDTH_BASIC);
	listControl.InsertColumn(4, _T("BRAND"), LVCFMT_RIGHT, COLUMN_WIDTH_BASIC);
	listControl.InsertColumn(5, _T("MODEL"), LVCFMT_RIGHT, COLUMN_WIDTH_BASIC);
	listControl.InsertColumn(6, _T("CATEGORY"), LVCFMT_RIGHT, COLUMN_WIDTH_BASIC);

}