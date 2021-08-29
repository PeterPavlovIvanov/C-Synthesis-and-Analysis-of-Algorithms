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
	///<summary>Отваря диалога за Insert на град</summary>
	afx_msg void OnRacksInsert();

	void OnInitialUpdate();

	BOOL InsertRack(RACKS& rack);

	BOOL UpdateRack(RACKS& rack);

	BOOL DeleteRack(int nID);

	BOOL SelectRack(int nID, RACKS& rack);

	RacksDocument* GetDocument() const;

	void OnContextMenu(CWnd* pWnd, CPoint point);

	void OnView();

	void OnDelete();

	void OnCityUpdate();

	//void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) override;

private:
	///<summary>Обновява град в лист контролата</summary>
	///<param "pHint">Обект съдържащ информацията за града</param>
	void UpdateCityInListCtrl(CObject * pHint);

	///<summary>Добавя град в лист контролата</summary>
	///<param "pHint">Обект съдържащ информацията за града</param>
	void InsertCityInListCtrl(CObject * pHint);

	///<summary>Изтрива град от лист контролата</summary>
	///<param "pHint">Обект съдържащ информацията за града</param>
	void DeleteCityInListCtrl(CObject * pHint);

	///<summary>Задава колонките на лист контролата</summary>
	void SetColumnsCitiesListCtrl();

	//Members
	// ----------------
private:
	///<summary>Инстанция на List Control-ата</summary>
	CListCtrl& m_ListCtrl = GetListCtrl();
};


