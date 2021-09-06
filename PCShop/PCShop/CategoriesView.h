#pragma once
#include "TypeDefs.h"
#include "CategoriesDocument.h"


// CategoriesView view

class CategoriesView : public CListView
{
	DECLARE_DYNCREATE(CategoriesView)

protected:
	CategoriesView();           // protected constructor used by dynamic creation
	virtual ~CategoriesView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()

public:
	void OnInitialUpdate();

	CategoriesDocument* GetDocument() const;

	void OnContextMenu(CWnd* pWnd, CPoint point);

	void OnCategoryInsert();

	void OnCategoryPreview();

	void OnCategoryDelete();

	void OnCategoryUpdate();

	void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) override;

private:

	void UpdateCategoryInListCtrl(CObject * pHint);

	void InsertCategoryInListCtrl(CObject * pHint);

	void DeleteCategoryInListCtrl(CObject * pHint);

	void SetColumnsCategoriesListCtrl();

	//Members
	// ----------------
private:
	///<summary>Инстанция на List Control-ата</summary>
	CListCtrl& listCtrl = GetListCtrl();
};

