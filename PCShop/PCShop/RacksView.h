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
	///<summary>Обновява град в лист контролата</summary>
	///<param "pHint">Обект съдържащ информацията за града</param>
	void UpdateRackInListCtrl(CObject * pHint);

	///<summary>Добавя град в лист контролата</summary>
	///<param "pHint">Обект съдържащ информацията за града</param>
	void InsertRackInListCtrl(CObject * pHint);

	///<summary>Изтрива град от лист контролата</summary>
	///<param "pHint">Обект съдържащ информацията за града</param>
	void DeleteRackInListCtrl(CObject * pHint);

	///<summary>Задава колонките на лист контролата</summary>
	void SetColumnsRacksListCtrl();

	//Members
	// ----------------
private:
	///<summary>Инстанция на List Control-ата</summary>
	CListCtrl& listCtrl = GetListCtrl();
};


