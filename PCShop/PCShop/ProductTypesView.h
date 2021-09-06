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
	void OnInitialUpdate();

	void SetTextOnRow(int index, PRODUCT_TYPES * pt, CString strID, CString strPrice);

	ProductTypesDocument* GetDocument() const;

	void OnContextMenu(CWnd* pWnd, CPoint point);

	void OnProductTypeInsert();

	void OnProductTypePreview();

	void OnProductTypeDelete();

	void OnProductTypeUpdate();

	void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) override;

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


