#pragma once
#include "TypeDefs.h"
#include "ProductTypesDocument.h"

// ProductTypesView view

class ProductTypesView : public CListView
{
public:
	DECLARE_DYNCREATE(ProductTypesView)
	DECLARE_MESSAGE_MAP()

protected:
	ProductTypesView();           // protected constructor used by dynamic creation
	virtual ~ProductTypesView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

public:
	///<summary>Отваря диалога за Insert на град</summary>
	afx_msg void OnProductTypesInsert();

	void OnInitialUpdate();

	BOOL InsertProductType(ProductTypeDTO& productTypeDTO);

	BOOL UpdateProductType(ProductTypeDTO& productTypeDTO);

	BOOL DeleteProductType(int nID);

	BOOL SelectProductType(int nID, ProductTypeDTO& productTypeDTO);

	ProductTypesDocument* GetDocument() const;

	void OnContextMenu(CWnd* pWnd, CPoint point);

	void OnView();

	void OnDelete();

	void OnProductTypeUpdate();

	//void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) override;

private:
	///<summary>Обновява град в лист контролата</summary>
	///<param "pHint">Обект съдържащ информацията за града</param>
	void UpdateProductTypeInListCtrl(CObject * pHint);

	///<summary>Добавя град в лист контролата</summary>
	///<param "pHint">Обект съдържащ информацията за града</param>
	void InsertProductTypeInListCtrl(CObject * pHint);

	///<summary>Изтрива град от лист контролата</summary>
	///<param "pHint">Обект съдържащ информацията за града</param>
	void DeleteProductTypeInListCtrl(CObject * pHint);

	///<summary>Задава колонките на лист контролата</summary>
	void SetColumnsProductTypesListCtrl();

	//Members
	// ----------------
private:
	///<summary>Инстанция на List Control-ата</summary>
	CListCtrl& listControl = GetListCtrl();
};


