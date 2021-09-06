// ProductsView.cpp : implementation file
//

#include "stdafx.h"
#include "PCShop.h"
#include "ProductsView.h"
#include "ProductsDialog.h"
#include "DialogModes.h"

// ProductsView

IMPLEMENT_DYNCREATE(ProductsView, CListView)

ProductsView::ProductsView()
{

}

ProductsView::~ProductsView()
{
}

BEGIN_MESSAGE_MAP(ProductsView, CListView)
	ON_COMMAND(INSERT_PRODUCT_OPTION, &ProductsView::OnProductInsert)
	ON_COMMAND(UPDATE_PRODUCT_OPTION, &ProductsView::OnProductUpdate)
	ON_COMMAND(PREVIEW_PRODUCT_OPTION, &ProductsView::OnProductPreview)
	ON_COMMAND(DELETE_PRODUCT_OPTION, &ProductsView::OnProductDelete)
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
		MainMenu.AppendMenu(MF_STRING, INSERT_PRODUCT_OPTION, _T("Add product"));
		if (listControl.GetNextItem(-1, LVNI_SELECTED) > -1)
		{
			MainMenu.AppendMenu(MF_STRING, UPDATE_PRODUCT_OPTION, _T("Update product"));
			MainMenu.AppendMenu(MF_STRING, DELETE_PRODUCT_OPTION, _T("Delete product"));
			MainMenu.AppendMenu(MF_STRING, PREVIEW_PRODUCT_OPTION, _T("Preview product"));
		}

		//Display the Popup Menu
		MainMenu.TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);
	}
	else
	{
		CWnd::OnContextMenu(pWnd, point);
	}
}

void ProductsView::OnProductInsert()
{	
	//Взимаме документа
	ProductsDocument* document = GetDocument();

	//Инициализираме диалога със съответните заглавие и полета
	PRODUCTS product;
	PRODUCT_TYPES productType;
	ProductsDialog dialog(product, productType, document->GetModelsArray(), document->GetCategoriesArray(), document->GetBrandsArray(),
		document->GetShelvesArray(), document->GetRacksArray(), DialogModeInsert);

	if (dialog.DoModal() != IDOK)
		return;


	document->InsertProduct(product, productType);
}

void ProductsView::OnProductPreview()
{
	//Взимаме документа
	ProductsDocument* productsDocument = GetDocument();

	//Взимаме select-натия Product
	int index = listControl.GetSelectionMark();
	long ID = (long)listControl.GetItemData(index);

	//взимаме актуалния Product от базата
	PRODUCTS product;
	PRODUCT_TYPES productType;
	ModelsArray modelsArray;
	CategoriesArray categoriesArray;
	BrandsArray brandsArray;
	ShelvesArray shelvesArray;
	RacksArray racksArray;

	if (productsDocument->SelectByID(ID, product, productType, modelsArray, categoriesArray, brandsArray, shelvesArray, racksArray) == FALSE)
		return;

	//Инициализираме диалога със съответните заглавие и полета
	ProductsDialog dialog(product, productType, modelsArray, categoriesArray, brandsArray, shelvesArray, racksArray, DialogModePreview);

	dialog.DoModal();
}

void ProductsView::OnProductDelete()
{
	//Взимаме документа
	ProductsDocument* productsDocument = GetDocument();

	//Взимаме select-натия Product Type
	int index = listControl.GetSelectionMark();
	long ID = (long)listControl.GetItemData(index);

	//взимаме актуалния Product от базата
	PRODUCTS product;
	PRODUCT_TYPES productType;
	ModelsArray modelsArray;
	CategoriesArray categoriesArray;
	BrandsArray brandsArray;
	ShelvesArray shelvesArray;
	RacksArray racksArray;

	if (productsDocument->SelectByID(ID, product, productType, modelsArray, categoriesArray, brandsArray, shelvesArray, racksArray) == FALSE)
		return;

	//Инициализираме диалога със съответните заглавие и полета
	ProductsDialog dialog(product, productType, modelsArray, categoriesArray, brandsArray, shelvesArray, racksArray, DialogModeDelete);

	if (dialog.DoModal() != IDOK)
		return;

	productsDocument->DeleteByID(ID);
}

void ProductsView::OnProductUpdate()
{
	//Взимаме документа
	ProductsDocument* productsDocument = GetDocument();

	//Взимаме ID на select-натия Product 
	int index = listControl.GetSelectionMark();
	long ID = (long)listControl.GetItemData(index);

	//взимаме актуалния Product от базата
	PRODUCTS product;
	PRODUCT_TYPES productType;
	ModelsArray modelsArray;
	CategoriesArray categoriesArray;
	BrandsArray brandsArray;
	ShelvesArray shelvesArray;
	RacksArray racksArray;

	if (productsDocument->SelectByID(ID, product, productType, modelsArray, categoriesArray, brandsArray, shelvesArray, racksArray) == FALSE)
		return;

	//Инициализираме диалога със съответните заглавие и полета
	ProductsDialog dialog(product, productType, modelsArray, categoriesArray, brandsArray, shelvesArray, racksArray, DialogModeUpdate);

	if (dialog.DoModal() != IDOK)
		return;

	productsDocument->UpdateProduct(product);
}

void ProductsView::OnUpdate(CView * pSender, LPARAM lHint, CObject * pHint)
{
	switch (lHint)
	{
	case (UpdateCodes::UpdateCodeUpdate):
	{
		UpdateProductInListCtrl(pHint);
		break;
	}
	case (UpdateCodes::UpdateCodeInsert):
	{
		InsertProductInListCtrl(pHint);
		break;
	}
	case (UpdateCodes::UpdateCodeDelete):
	{
		DeleteProductInListCtrl(pHint);
		break;
	}
	default:
		break;
	}
	__super::OnUpdate(pSender, lHint, pHint);
}

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

		//get the product type of the current product 
		for (int j = 0; j < GetDocument()->GetProductTypesArray().GetCount(); j++)
			if (GetDocument()->GetProductTypesArray().GetAt(j)->ID == product->productTypeID)
			{
				productType = GetDocument()->GetProductTypesArray().GetAt(j);
				break;
			}

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

		if (!(category && brand && model && productType))
			continue;

		CString strPrice, strSerialNumber;
		strPrice.Format(_T("%.2f"), productType->price);
		strSerialNumber.Format(_T("%d"), product->serialID);

		int index = listControl.InsertItem(0, productType->productName);
		listControl.SetItemText(index, 1, strSerialNumber);
		listControl.SetItemText(index, 2, productType->productName);
		listControl.SetItemText(index, 3, productType->description);
		listControl.SetItemText(index, 4, strPrice);
		listControl.SetItemText(index, 5, brand->brandName);
		listControl.SetItemText(index, 6, model->modelName);
		listControl.SetItemText(index, 7, category->categoryName);
		listControl.SetItemData(index, product->serialID);
	}

	listControl.DeleteColumn(0);
}

void ProductsView::UpdateProductInListCtrl(CObject * pHint)
{
	for (int i = 0; i < listControl.GetItemCount(); i++)
	{
		PRODUCTS* product = (PRODUCTS*)pHint;
		if (listControl.GetItemData(i) == product->serialID)
		{
			CString strID;
			strID.Format(_T("%d"), product->serialID);

			listControl.SetItemText(i, 0, strID);

			SetTextOnRow(i, product);

			break;
		}//if
	}//for
}

void ProductsView::InsertProductInListCtrl(CObject * pHint)
{
	PRODUCTS* product = (PRODUCTS*)pHint;
	CString strID;
	strID.Format(_T("%d"), product->serialID);

	if (GetDocument()->SelectAll() == FALSE)
		return;

	int index = listControl.InsertItem(0, strID);
	SetTextOnRow(index, product);

	listControl.SetItemData(index, product->serialID);
}

void ProductsView::DeleteProductInListCtrl(CObject * pHint)
{
	for (int i = 0; i < listControl.GetItemCount(); i++)
	{
		PRODUCTS* product = (PRODUCTS*)pHint;
		if (listControl.GetItemData(i) == product->serialID)
		{
			listControl.DeleteItem(i);
			break;
		}
	}
}

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

void ProductsView::SetTextOnRow(int index, PRODUCTS * product)
{
	PRODUCT_TYPES* pt = NULL;
	BRANDS* b = NULL;
	CATEGORIES* c = NULL;
	MODELS* m = NULL;

	for (int j = 0; j < GetDocument()->GetProductTypesArray().GetCount(); j++)
		if (GetDocument()->GetProductTypesArray().GetAt(j)->ID == product->productTypeID)
		{
			pt = GetDocument()->GetProductTypesArray().GetAt(j);
			break;
		}

	if (!pt)
		return;

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

	CString strPrice;
	strPrice.Format(_T("%.2f"), pt->price);

	listControl.SetItemText(index, 1, pt->productName);
	listControl.SetItemText(index, 2, pt->description);
	listControl.SetItemText(index, 3, strPrice);
	listControl.SetItemText(index, 4, b->brandName);
	listControl.SetItemText(index, 5, m->modelName);
	listControl.SetItemText(index, 5, c->categoryName);
}