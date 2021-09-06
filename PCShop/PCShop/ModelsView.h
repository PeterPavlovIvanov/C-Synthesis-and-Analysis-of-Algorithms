#pragma once
#include "TypeDefs.h"
#include "ModelsDocument.h"

// ModelsView view

class ModelsView : public CListView
{
public:
	DECLARE_DYNCREATE(ModelsView)
	DECLARE_MESSAGE_MAP()

protected:
	ModelsView();           // protected constructor used by dynamic creation
	virtual ~ModelsView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

public:
	///<summary>Отваря диалога за Insert на град</summary>
	afx_msg void OnModelsInsert();

	void OnInitialUpdate();

	BOOL InsertModel(MODELS& model);

	BOOL UpdateModel(MODELS& model);

	BOOL DeleteModel(int nID);

	BOOL SelectModel(int nID, MODELS& model);

	ModelsDocument* GetDocument() const;

	void OnContextMenu(CWnd* pWnd, CPoint point);

	void OnView();

	void OnDelete();

	void OnModelUpdate();

	//void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) override;

private:
	///<summary>Обновява град в лист контролата</summary>
	///<param "pHint">Обект съдържащ информацията за града</param>
	void UpdateModelInListCtrl(CObject * pHint);

	///<summary>Добавя град в лист контролата</summary>
	///<param "pHint">Обект съдържащ информацията за града</param>
	void InsertModelInListCtrl(CObject * pHint);

	///<summary>Изтрива град от лист контролата</summary>
	///<param "pHint">Обект съдържащ информацията за града</param>
	void DeleteModelInListCtrl(CObject * pHint);

	///<summary>Задава колонките на лист контролата</summary>
	void SetColumnsModelsListCtrl();

	//Members
	// ----------------
private:
	///<summary>Инстанция на List Control-ата</summary>
	CListCtrl& m_ListCtrl = GetListCtrl();
};


