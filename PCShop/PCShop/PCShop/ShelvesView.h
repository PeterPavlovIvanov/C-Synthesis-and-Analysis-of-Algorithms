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

	BOOL InsertShelf(SHELVES& shelf);

	BOOL UpdateShelf(SHELVES& shelf);

	BOOL DeleteShelf(int nID);

	BOOL SelectShelf(int nID, SHELVES& shelf);

	ShelvesDocument* GetDocument() const;

	void OnContextMenu(CWnd* pWnd, CPoint point);

	void OnShelfInsert();

	void OnShelfPreview();

	void OnShelfDelete();

	void OnShelfUpdate();

	void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) override;

private:
	///<summary>Обновява град в лист контролата</summary>
	///<param "pHint">Обект съдържащ информацията за града</param>
	void UpdateShelfInListCtrl(CObject * pHint);

	///<summary>Добавя град в лист контролата</summary>
	///<param "pHint">Обект съдържащ информацията за града</param>
	void InsertShelfInListCtrl(CObject * pHint);

	///<summary>Изтрива град от лист контролата</summary>
	///<param "pHint">Обект съдържащ информацията за града</param>
	void DeleteShelfInListCtrl(CObject * pHint);

	///<summary>Задава колонките на лист контролата</summary>
	void SetColumnsShelvesListCtrl();

	void SetTextOnRow(int index, SHELVES* shelf, CString strID);

	//Members
	// ----------------
private:
	///<summary>Инстанция на List Control-ата</summary>
	CListCtrl& listCtrl = GetListCtrl();
};


