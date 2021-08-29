
// PCShopView.h : interface of the CPCShopView class
//

#pragma once

class CPCShopCntrItem;
class CPCShopSet;

class CPCShopView : public COleDBRecordView
{
protected: // create from serialization only
	CPCShopView();
	DECLARE_DYNCREATE(CPCShopView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_PCSHOP_FORM };
#endif
	CPCShopSet* m_pSet;

// Attributes
public:
	CPCShopDoc* GetDocument() const;
	// m_pSelection holds the selection to the current CPCShopCntrItem.
	// For many applications, such a member variable isn't adequate to
	//  represent a selection, such as a multiple selection or a selection
	//  of objects that are not CPCShopCntrItem objects.  This selection
	//  mechanism is provided just to help you get started

	// TODO: replace this selection mechanism with one appropriate to your app
	CPCShopCntrItem* m_pSelection;

// Operations
public:

// Overrides
public:
	virtual CRowset<>* OnGetRowset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual BOOL IsSelected(const CObject* pDocItem) const;// Container support

// Implementation
public:
	virtual ~CPCShopView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnDestroy();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnInsertObject();
	afx_msg void OnCancelEditCntr();
	afx_msg void OnFilePrint();
	afx_msg void OnCancelEditSrvr();
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PCShopView.cpp
inline CPCShopDoc* CPCShopView::GetDocument() const
   { return reinterpret_cast<CPCShopDoc*>(m_pDocument); }
#endif

