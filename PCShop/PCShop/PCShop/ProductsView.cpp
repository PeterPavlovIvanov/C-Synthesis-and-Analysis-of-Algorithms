// ProductsView.cpp : implementation file
//

#include "stdafx.h"
#include "PCShop.h"
#include "ProductsView.h"


// ProductsView

IMPLEMENT_DYNCREATE(ProductsView, CListView)

ProductsView::ProductsView()
{

}

ProductsView::~ProductsView()
{
}

BEGIN_MESSAGE_MAP(ProductsView, CListView)
/*ON_COMMAND(INSERT_OPTION_ID, &CCitiesView::OnCitiesInsert)
ON_COMMAND(VIEW_OPTION_ID, &CCitiesView::OnView)
ON_COMMAND(DELETE_OPTION_ID, &CCitiesView::OnDelete)
ON_COMMAND(UPDATE_OPTION_ID, &CCitiesView::OnCityUpdate)*/
ON_WM_PAINT()
ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()

// ProductsView diagnostics

#ifdef _DEBUG
void ProductsView::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void ProductsView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif
#endif //_DEBUG

ProductsDocument * ProductsView::GetDocument() const
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(ProductsDocument)));
	return (ProductsDocument*)m_pDocument;
}

void ProductsView::OnContextMenu(CWnd * pWnd, CPoint point)
{
};

void ProductsView::OnInitialUpdate()
{
	SetColumnsProductsListCtrl();

	CListView::OnInitialUpdate();

	if (GetDocument()->SelectAll() == FALSE)
		return;

	for (int i = 0; i < GetDocument()->GetProductsArray().GetCount(); i++)
	{
		PRODUCTS* product = GetDocument()->GetProductsArray().GetAt(i);
		PRODUCT_TYPES* productType = NULL;
		CATEGORIES* category = NULL;
		BRANDS* brand = NULL;
		MODELS* model = NULL;

		//get the type of the product
		for (int j = 0; j < GetDocument()->GetProductTypesArray().GetCount(); j++)
		{
			if (GetDocument()->GetProductTypesArray().GetAt(j)->ID == product->productTypeID)
			{
				productType = GetDocument()->GetProductTypesArray().GetAt(j);
				break;
			}
		}

		if (!productType)
			return;

		//get the category of the current product 
		for (int j = 0; j < GetDocument()->GetCategoriesArray().GetCount(); j++)
			if (GetDocument()->GetCategoriesArray().GetAt(j)->ID == productType->categoryID)
			{
				category = GetDocument()->GetCategoriesArray().GetAt(j);
				break;
			}

		//get the brand of the current product 
		for (int j = 0; j < GetDocument()->GetBrandsArray().GetCount(); j++)
			if (GetDocument()->GetBrandsArray().GetAt(j)->ID == productType->brandID)
			{
				brand = GetDocument()->GetBrandsArray().GetAt(j);
				break;
			}

		//get the model of the current product 
		for (int j = 0; j < GetDocument()->GetModelsArray().GetCount(); j++)
			if (GetDocument()->GetModelsArray().GetAt(j)->ID == productType->modelID)
			{
				model = GetDocument()->GetModelsArray().GetAt(j);
				break;
			}

		if (!(category && brand && model))
			continue;

		CString strPrice, strSerialNumber;
		strPrice.Format(_T("%.2f"), productType->price);
		strSerialNumber.Format(_T("%d"), product->serialID);

		int nIndex = listControl.InsertItem(0, productType->productName);
		listControl.SetItemText(nIndex, 1, strSerialNumber);
		listControl.SetItemText(nIndex, 2, productType->productName);
		listControl.SetItemText(nIndex, 3, productType->description);
		listControl.SetItemText(nIndex, 4, strPrice);
		listControl.SetItemText(nIndex, 5, brand->brandName);
		listControl.SetItemText(nIndex, 6, model->modelName);
		listControl.SetItemText(nIndex, 7, category->categoryName);
	}

	listControl.DeleteColumn(0);
}

// ProductsView message handlers

void ProductsView::SetColumnsProductsListCtrl()
{
	listControl.SetView(LVS_REPORT);
	//todo: LVS_SINGLESEL
	listControl.SetExtendedStyle(listControl.GetExtendedStyle() | LVS_EX_FULLROWSELECT);

	listControl.InsertColumn(0, _T(""), LVCFMT_RIGHT);
	listControl.InsertColumn(1, _T("SERIAL_NUMBER"), LVCFMT_RIGHT, COLUMN_WIDTH_BASIC);
	listControl.InsertColumn(2, _T("PRODUCT_NAME"), LVCFMT_RIGHT, COLUMN_WIDTH_BASIC);
	listControl.InsertColumn(3, _T("DESCRIPTION"), LVCFMT_RIGHT, COLUMN_WIDTH_DESCRIPTION);
	listControl.InsertColumn(4, _T("PRICE"), LVCFMT_RIGHT, COLUMN_WIDTH_BASIC);
	listControl.InsertColumn(5, _T("BRAND"), LVCFMT_RIGHT, COLUMN_WIDTH_BASIC);
	listControl.InsertColumn(6, _T("MODEL"), LVCFMT_RIGHT, COLUMN_WIDTH_BASIC);
	listControl.InsertColumn(7, _T("CATEGORY"), LVCFMT_RIGHT, COLUMN_WIDTH_BASIC);

}
