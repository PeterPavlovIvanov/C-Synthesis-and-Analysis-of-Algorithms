// ProductTypesView.cpp : implementation file
//

#include "stdafx.h"
#include "PCShop.h"
#include "ProductTypesView.h"
#include "TypeDefs.h" 
#include "ProductTypesDocument.h"
#include "ProductTypesDialog.h"
#include "UpdateCodes.h"

// ProductTypesView

IMPLEMENT_DYNCREATE(ProductTypesView, CListView)

ProductTypesView::ProductTypesView()
{

}

ProductTypesView::~ProductTypesView()
{
}

BEGIN_MESSAGE_MAP(ProductTypesView, CListView)
	ON_COMMAND(INSERT_PRODUCT_TYPE_OPTION, &ProductTypesView::OnProductTypeInsert)
	ON_COMMAND(UPDATE_PRODUCT_TYPE_OPTION, &ProductTypesView::OnProductTypeUpdate)
	ON_COMMAND(PREVIEW_PRODUCT_TYPE_OPTION, &ProductTypesView::OnProductTypePreview)
	ON_COMMAND(DELETE_PRODUCT_TYPE_OPTION, &ProductTypesView::OnProductTypeDelete)
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
		MainMenu.AppendMenu(MF_STRING, INSERT_PRODUCT_TYPE_OPTION, _T("Add product type"));
		if (listControl.GetNextItem(-1, LVNI_SELECTED) > -1)
		{
			MainMenu.AppendMenu(MF_STRING, UPDATE_PRODUCT_TYPE_OPTION, _T("Update product type"));
			MainMenu.AppendMenu(MF_STRING, DELETE_PRODUCT_TYPE_OPTION, _T("Delete product type"));
			MainMenu.AppendMenu(MF_STRING, PREVIEW_PRODUCT_TYPE_OPTION, _T("Preview product type"));
		}

		//Display the Popup Menu
		MainMenu.TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);
	}
	else
	{
		CWnd::OnContextMenu(pWnd, point);
	}
}

void ProductTypesView::OnProductTypeInsert()
{
	//Взимаме документа
	ProductTypesDocument* ptDocument = GetDocument();

	//Инициализираме диалога със съответните заглавие и полета
	PRODUCT_TYPES pt;
	ProductTypesDialog dialog(pt, ptDocument->GetModelsArray(),
		ptDocument->GetCategoriesArray(), ptDocument->GetBrandsArray(), DialogModeInsert);

	if (dialog.DoModal() != IDOK)
		return;

	ptDocument->InsertProductType(pt);
}

void ProductTypesView::OnProductTypePreview()
{
	//Взимаме документа
	ProductTypesDocument* productTypesDocument = GetDocument();

	//Взимаме select-натия Product Type
	int index = listControl.GetSelectionMark();
	long ID = (long)listControl.GetItemData(index);

	//взимаме актуалния Product Type от базата
	PRODUCT_TYPES pt;
	ModelsArray modelsArray;
	CategoriesArray categoriesArray;
	BrandsArray brandsArray;
	if (productTypesDocument->SelectByID(ID, pt, modelsArray, categoriesArray, brandsArray) == FALSE)
		return;

	//Инициализираме диалога със съответните заглавие и полета
	ProductTypesDialog dialog(pt, modelsArray, categoriesArray, brandsArray, DialogModePreview);

	dialog.DoModal();
}

void ProductTypesView::OnProductTypeDelete()
{
	//Взимаме документа
	ProductTypesDocument* productTypesDocument = GetDocument();

	//Взимаме select-натия Product Type
	int index = listControl.GetSelectionMark();
	long ID = (long)listControl.GetItemData(index);

	//взимаме актуалния Product Type от базата 
	PRODUCT_TYPES pt;
	ModelsArray modelsArray;
	CategoriesArray categoriesArray;
	BrandsArray brandsArray;
	if (productTypesDocument->SelectByID(ID, pt, modelsArray, categoriesArray, brandsArray) == FALSE)
		return;

	//Инициализираме диалога със съответните заглавие и полета
	ProductTypesDialog dialog(pt, modelsArray, categoriesArray, brandsArray, DialogModeDelete);

	if (dialog.DoModal() != IDOK)
		return;

	productTypesDocument->DeleteByID(ID);
}

void ProductTypesView::OnProductTypeUpdate()
{
	//Взимаме документа
	ProductTypesDocument* productTypesDocument = GetDocument();

	//Взимаме ID на select-натия Product Type
	int index = listControl.GetSelectionMark();
	long ID = (long)listControl.GetItemData(index);

	//взимаме актуалния Product Type от базата 
	PRODUCT_TYPES pt;
	ModelsArray modelsArray;
	CategoriesArray categoriesArray;
	BrandsArray brandsArray;
	if (productTypesDocument->SelectByID(ID, pt, modelsArray, categoriesArray, brandsArray) == FALSE)
		return;

	//Инициализираме диалога със съответните заглавие и полета
	ProductTypesDialog dialog(pt, modelsArray, categoriesArray, brandsArray, DialogModeUpdate);

	if (dialog.DoModal() != IDOK)
		return;

	productTypesDocument->UpdateProductType(pt);
}

void ProductTypesView::OnUpdate(CView * pSender, LPARAM lHint, CObject * pHint)
{
	switch (lHint)
	{
	case (UpdateCodes::UpdateCodeUpdate):
	{
		UpdateProductTypeInListCtrl(pHint);
		break;
	}
	case (UpdateCodes::UpdateCodeInsert):
	{
		InsertProductTypeInListCtrl(pHint);
		break;
	}
	case (UpdateCodes::UpdateCodeDelete):
	{
		DeleteProductTypeInListCtrl(pHint);
		break;
	}
	default:
		break;
	}
	__super::OnUpdate(pSender, lHint, pHint);
}

void ProductTypesView::UpdateProductTypeInListCtrl(CObject * pHint)
{
	for (int i = 0; i < listControl.GetItemCount(); i++)
	{
		PRODUCT_TYPES* productType = (PRODUCT_TYPES*)pHint;
		if (listControl.GetItemData(i) == productType->ID)
		{
			CString strID, strPrice;
			strID.Format(_T("%d"), productType->ID);
			strPrice.Format(_T("%.2f"), productType->price);

			listControl.SetItemText(i, 0, productType->productName);

			SetTextOnRow(i, productType, strID, strPrice);

			break;
		}//if
	}//for
}

void ProductTypesView::InsertProductTypeInListCtrl(CObject * pHint)
{
	PRODUCT_TYPES* productType = (PRODUCT_TYPES*)pHint;
	CString strID, strPrice;
	strID.Format(_T("%d"), productType->ID);
	strPrice.Format(_T("%.2f"), productType->price);

	int index = listControl.InsertItem(0, productType->productName);
	SetTextOnRow(index, productType, strID, strPrice);

	listControl.SetItemData(index, productType->ID);
}

void ProductTypesView::DeleteProductTypeInListCtrl(CObject * pHint)
{
	for (int i = 0; i < listControl.GetItemCount(); i++)
	{
		PRODUCT_TYPES* productType = (PRODUCT_TYPES*)pHint;
		if (listControl.GetItemData(i) == productType->ID)
		{
			listControl.DeleteItem(i);
			break;
		}
	}
}

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

		int index = listControl.InsertItem(0, productType->productName);
		listControl.SetItemText(index, 1, productType->productName);
		listControl.SetItemText(index, 2, productType->description);
		listControl.SetItemText(index, 3, strPrice);
		listControl.SetItemText(index, 4, brand->brandName);
		listControl.SetItemText(index, 5, model->modelName);
		listControl.SetItemText(index, 6, category->categoryName);
		listControl.SetItemData(index, productType->ID);
	}

	listControl.DeleteColumn(0);
}

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

void ProductTypesView::SetTextOnRow(int index, PRODUCT_TYPES * pt, CString strID, CString strPrice)
{
	BRANDS* b = NULL;
	CATEGORIES* c = NULL;
	MODELS* m = NULL;

	for (int j = 0; j < GetDocument()->GetBrandsArray().GetCount(); j++)
		if (GetDocument()->GetBrandsArray().GetAt(j)->ID == pt->brandID)
		{
			b = GetDocument()->GetBrandsArray().GetAt(j);
			break;
		}

	for (int j = 0; j < GetDocument()->GetModelsArray().GetCount(); j++)
		if (GetDocument()->GetModelsArray().GetAt(j)->ID == pt->modelID)
		{
			m = GetDocument()->GetModelsArray().GetAt(j);
			break;
		}

	for (int j = 0; j < GetDocument()->GetCategoriesArray().GetCount(); j++)
		if (GetDocument()->GetCategoriesArray().GetAt(j)->ID == pt->categoryID)
		{
			c = GetDocument()->GetCategoriesArray().GetAt(j);
			break;
		}

	if (!m || !b || !c)
		return;

	listControl.SetItemText(index, 1, pt->description);
	listControl.SetItemText(index, 2, strPrice);
	listControl.SetItemText(index, 3, b->brandName);
	listControl.SetItemText(index, 4, m->modelName);
	listControl.SetItemText(index, 5, c->categoryName);
}