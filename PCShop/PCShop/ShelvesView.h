#pragma once
#include "TypeDefs.h"
#include "ShelvesDocument.h"

// ShelvesView view

class ShelvesView : public CListView
{
public:
	DECLARE_DYNCREATE(ShelvesView)
	DECLARE_MESSAGE_MAP()

protected:
	ShelvesView();           // protected constructor used by dynamic creation
	virtual ~ShelvesView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

public:
	void OnInitialUpdate();

	ShelvesDocument* GetDocument() const;

	void OnContextMenu(CWnd* pWnd, CPoint point);

	void OnShelfInsert();

	void OnShelfPreview();

	void OnShelfDelete();

	void OnShelfUpdate();

	void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) override;

private:
	void UpdateShelfInListCtrl(CObject * pHint);

	void InsertShelfInListCtrl(CObject * pHint);

	void DeleteShelfInListCtrl(CObject * pHint);

	void SetColumnsShelvesListCtrl();

	void SetTextOnRow(int index, SHELVES* shelf, CString strID);

	//Members
	// ----------------
private:
	///<summary>Инстанция на List Control-ата</summary>
	CListCtrl& listCtrl = GetListCtrl();
};


