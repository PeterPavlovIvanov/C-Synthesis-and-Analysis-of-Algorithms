#pragma once
#include "TypeDefs.h"
#include "ProductsDocument.h"

// ProductsView view

class ProductsView : public CListView
{
protected:
	DECLARE_DYNCREATE(ProductsView)
	DECLARE_MESSAGE_MAP()
	
protected:
	ProductsView();           // protected constructor used by dynamic creation
	virtual ~ProductsView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

public:
	void OnInitialUpdate();

	ProductsDocument* GetDocument() const;

	void OnContextMenu(CWnd* pWnd, CPoint point);

	void OnProductInsert();

	void OnProductPreview();

	void OnProductDelete();

	void OnProductUpdate();

	void SetTextOnRow(int index, PRODUCTS * product);

	void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) override;

private:
	
	void UpdateProductInListCtrl(CObject * pHint);

	void InsertProductInListCtrl(CObject * pHint);

	void DeleteProductInListCtrl(CObject * pHint);

	void SetColumnsProductsListCtrl();

	//Members
	// ----------------
private:
	///<summary>Инстанция на List Control-ата</summary>
	CListCtrl& listControl = GetListCtrl();
};


