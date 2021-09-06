#pragma once
#include "TypeDefs.h"
#include "RacksDocument.h"

// RacksView view

class RacksView : public CListView
{
public:
	DECLARE_DYNCREATE(RacksView)
	DECLARE_MESSAGE_MAP()

protected:
	RacksView();           // protected constructor used by dynamic creation
	virtual ~RacksView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

public:
	void OnInitialUpdate();

	RacksDocument* GetDocument() const;

	void OnContextMenu(CWnd* pWnd, CPoint point);

	void OnRackInsert();

	void OnRackPreview();

	void OnRackDelete();

	void OnRackUpdate();

	void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) override;

private:
	void UpdateRackInListCtrl(CObject * pHint);

	void InsertRackInListCtrl(CObject * pHint);

	void DeleteRackInListCtrl(CObject * pHint);

	void SetColumnsRacksListCtrl();

	//Members
	// ----------------
private:
	///<summary>Инстанция на List Control-ата</summary>
	CListCtrl& listCtrl = GetListCtrl();
};


