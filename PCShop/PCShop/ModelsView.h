#pragma once
#include "TypeDefs.h"
#include "ModelsDocument.h"
#include "UpdateCodes.h"

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

	void OnInitialUpdate();

	ModelsDocument* GetDocument() const;

	void OnContextMenu(CWnd* pWnd, CPoint point);

    void OnModelInsert();

	void OnModelPreview();

	void OnModelDelete();

	void OnModelUpdate();

	void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) override;

private:
	
	void UpdateModelInListCtrl(CObject * pHint);

	void InsertModelInListCtrl(CObject * pHint);

	void DeleteModelInListCtrl(CObject * pHint);

	void SetColumnsModelsListCtrl();

	//Members
	// ----------------
private:
	///<summary>Инстанция на List Control-ата</summary>
	CListCtrl& listCtrl = GetListCtrl();
};


