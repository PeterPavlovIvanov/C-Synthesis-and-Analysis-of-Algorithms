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
	///<summary>Отваря диалога за Insert на продукт</summary>
	afx_msg void OnProductsInsert();

	void OnInitialUpdate();

	BOOL InsertProduct(ProductDTO& productDTO);

	BOOL UpdateProduct(ProductDTO& productDTO);

	BOOL DeleteProduct(int nID);

	BOOL SelectProduct(int nID, ProductDTO& productDTO);

	ProductsDocument* GetDocument() const;

	void OnContextMenu(CWnd* pWnd, CPoint point);

	void OnView();

	void OnDelete();

	void OnProductUpdate();

	//void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) override;

private:
	///<summary>Обновява град в лист контролата</summary>
	///<param "pHint">Обект съдържащ информацията за града</param>
	void UpdateProductInListCtrl(CObject * pHint);

	///<summary>Добавя град в лист контролата</summary>
	///<param "pHint">Обект съдържащ информацията за града</param>
	void InsertProductInListCtrl(CObject * pHint);

	///<summary>Изтрива град от лист контролата</summary>
	///<param "pHint">Обект съдържащ информацията за града</param>
	void DeleteProductInListCtrl(CObject * pHint);

	///<summary>Задава колонките на лист контролата</summary>
	void SetColumnsProductsListCtrl();

	//Members
	// ----------------
private:
	///<summary>Инстанция на List Control-ата</summary>
	CListCtrl& listControl = GetListCtrl();
};


