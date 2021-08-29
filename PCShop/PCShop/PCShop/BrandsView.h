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
	///<summary>Отваря диалога за Insert на град</summary>
	afx_msg void OnBrandsInsert();

	void OnInitialUpdate();

	BOOL InsertBrand(BRANDS& brand);

	BOOL UpdateBrand(BRANDS& brand);

	BOOL DeleteBrand(int nID);

	BOOL SelectBrand(int nID, BRANDS& brand);

	BrandsDocument* GetDocument() const;

	void OnContextMenu(CWnd* pWnd, CPoint point);

	void OnView();

	void OnDelete();

	void OnCityUpdate();

	//void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) override;

private:
	///<summary>Обновява град в лист контролата</summary>
	///<param "pHint">Обект съдържащ информацията за града</param>
	void UpdateBrandInListCtrl(CObject * pHint);

	///<summary>Добавя град в лист контролата</summary>
	///<param "pHint">Обект съдържащ информацията за града</param>
	void InsertBrandInListCtrl(CObject * pHint);

	///<summary>Изтрива град от лист контролата</summary>
	///<param "pHint">Обект съдържащ информацията за града</param>
	void DeleteBrandInListCtrl(CObject * pHint);

	///<summary>Задава колонките на лист контролата</summary>
	void SetColumnsBrandsListCtrl();

	//Members
	// ----------------
private:
	///<summary>Инстанция на List Control-ата</summary>
	CListCtrl& m_ListCtrl = GetListCtrl();
};


