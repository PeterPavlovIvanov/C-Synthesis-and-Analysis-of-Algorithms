#pragma once
#include "TypeDefs.h"
#include "BrandsDocument.h"


// BrandsView view

class BrandsView : public CListView
{
public:
	DECLARE_DYNCREATE(BrandsView)
	DECLARE_MESSAGE_MAP()
protected:
	BrandsView();           // protected constructor used by dynamic creation
	virtual ~BrandsView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

public:

	void OnInitialUpdate();

	BrandsDocument* GetDocument() const;

	void OnContextMenu(CWnd* pWnd, CPoint point);

	void OnBrandInsert();

	void OnBrandPreview();

	void OnBrandDelete();

	void OnBrandUpdate();

	void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) override;

private:

	void UpdateBrandInListCtrl(CObject * pHint);

	void InsertBrandInListCtrl(CObject * pHint);

	void DeleteBrandInListCtrl(CObject * pHint);

	void SetColumnsBrandsListCtrl();

	//Members
	// ----------------
private:
	///<summary>Инстанция на List Control-ата</summary>
	CListCtrl& listCtrl = GetListCtrl();
};


