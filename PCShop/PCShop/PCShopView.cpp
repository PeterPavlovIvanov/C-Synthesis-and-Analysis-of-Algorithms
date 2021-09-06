
// PCShopView.cpp : implementation of the CPCShopView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "PCShop.h"
#endif

#include "PCShopSet.h"
#include "PCShopDoc.h"
#include "CntrItem.h"
#include "resource.h"
#include "PCShopView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPCShopView

IMPLEMENT_DYNCREATE(CPCShopView, COleDBRecordView)

BEGIN_MESSAGE_MAP(CPCShopView, COleDBRecordView)
	ON_WM_DESTROY()
	ON_WM_SETFOCUS()
	ON_WM_SIZE()
	ON_COMMAND(ID_OLE_INSERT_NEW, &CPCShopView::OnInsertObject)
	ON_COMMAND(ID_CANCEL_EDIT_CNTR, &CPCShopView::OnCancelEditCntr)
	ON_COMMAND(ID_FILE_PRINT, &CPCShopView::OnFilePrint)
	ON_COMMAND(ID_CANCEL_EDIT_SRVR, &CPCShopView::OnCancelEditSrvr)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &COleDBRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPCShopView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CPCShopView construction/destruction

CPCShopView::CPCShopView()
	: COleDBRecordView(IDD_PCSHOP_FORM)
{
	m_pSet = NULL;
	m_pSelection = NULL;
	// TODO: add construction code here

}

CPCShopView::~CPCShopView()
{
}

void CPCShopView::DoDataExchange(CDataExchange* pDX)
{
	COleDBRecordView::DoDataExchange(pDX);
	// you can insert DDX_* functions, as well as SetDlgItem*/GetDlgItem* API calls to link your database to the view
	// ex. ::SetDlgItemText(m_hWnd, IDC_MYCONTROL, m_pSet->m_MyColumn);
	// See MSDN and OLEDB samples for more information
}

BOOL CPCShopView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return COleDBRecordView::PreCreateWindow(cs);
}

void CPCShopView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_PCShopSet;
	{
		CWaitCursor wait;
		HRESULT hr = m_pSet->OpenAll();
		if (FAILED(hr))
		{
			// Failed to open recordset.  If the recordset is a 
			// stored procedure, make sure that you have properly
			// initialized any input parameters before calling
			// the OpenAll() method.

			AfxMessageBox(_T("Record set failed to open."), MB_OK);
			// Disable the Next and Previous record commands,
			// since attempting to change the current record without an
			// open RowSet will cause a crash
			m_bOnFirstRecord = TRUE;
			m_bOnLastRecord = TRUE;
		}
		if( hr == DB_S_ENDOFROWSET )
		{
			// the rowset is empty (does not contain any rows)
			AfxMessageBox(_T("Record set opened but there were no rows to return."), MB_OK);
			// Disable the Next and Previous record commands
			m_bOnFirstRecord = TRUE;
			m_bOnLastRecord = TRUE;
		}
	}
	COleDBRecordView::OnInitialUpdate();


	// TODO: remove this code when final selection model code is written
	m_pSelection = NULL;    // initialize selection

}


// CPCShopView printing


void CPCShopView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPCShopView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPCShopView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPCShopView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CPCShopView::OnDestroy()
{
	// Deactivate the item on destruction; this is important
	// when a splitter view is being used
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
   COleDBRecordView::OnDestroy();
}



// OLE Client support and commands

BOOL CPCShopView::IsSelected(const CObject* pDocItem) const
{
	// The implementation below is adequate if your selection consists of
	//  only CPCShopCntrItem objects.  To handle different selection
	//  mechanisms, the implementation here should be replaced

	// TODO: implement this function that tests for a selected OLE client item

	return pDocItem == m_pSelection;
}

void CPCShopView::OnInsertObject()
{
	// Invoke the standard Insert Object dialog box to obtain information
	//  for new CPCShopCntrItem object
	COleInsertDialog dlg;
	if (dlg.DoModal() != IDOK)
		return;

	BeginWaitCursor();

	CPCShopCntrItem* pItem = NULL;
	TRY
	{
		// Create new item connected to this document
		CPCShopDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pItem = new CPCShopCntrItem(pDoc);
		ASSERT_VALID(pItem);

		// Initialize the item from the dialog data
		if (!dlg.CreateItem(pItem))
			AfxThrowMemoryException();  // any exception will do
		ASSERT_VALID(pItem);
		
        if (dlg.GetSelectionType() == COleInsertDialog::createNewItem)
			pItem->DoVerb(OLEIVERB_SHOW, this);

		ASSERT_VALID(pItem);
		// As an arbitrary user interface design, this sets the selection
		//  to the last item inserted

		// TODO: reimplement selection as appropriate for your application
		m_pSelection = pItem;   // set selection to last inserted item
		pDoc->UpdateAllViews(NULL);
	}
	CATCH(CException, e)
	{
		if (pItem != NULL)
		{
			ASSERT_VALID(pItem);
			pItem->Delete();
		}
		AfxMessageBox(IDP_FAILED_TO_CREATE);
	}
	END_CATCH

	EndWaitCursor();
}

// The following command handler provides the standard keyboard
//  user interface to cancel an in-place editing session.  Here,
//  the container (not the server) causes the deactivation
void CPCShopView::OnCancelEditCntr()
{
	// Close any in-place active item on this view.
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
	{
		pActiveItem->Close();
	}
	ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
}

// Special handling of OnSetFocus and OnSize are required for a container
//  when an object is being edited in-place
void CPCShopView::OnSetFocus(CWnd* pOldWnd)
{
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL &&
		pActiveItem->GetItemState() == COleClientItem::activeUIState)
	{
		// need to set focus to this item if it is in the same view
		CWnd* pWnd = pActiveItem->GetInPlaceWindow();
		if (pWnd != NULL)
		{
			pWnd->SetFocus();   // don't call the base class
			return;
		}
	}

	COleDBRecordView::OnSetFocus(pOldWnd);
}

void CPCShopView::OnSize(UINT nType, int cx, int cy)
{
	COleDBRecordView::OnSize(nType, cx, cy);
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
		pActiveItem->SetItemRects();
}

void CPCShopView::OnFilePrint()
{
	//By default, we ask the Active document to print itself
	//using IOleCommandTarget. If you don't want this behavior
	//remove the call to COleDocObjectItem::DoDefaultPrinting.
	//If the call fails for some reason, we will try printing
	//the docobject using the IPrint interface.
	CPrintInfo printInfo;
	ASSERT(printInfo.m_pPD != NULL); 
	if (S_OK == COleDocObjectItem::DoDefaultPrinting(this, &printInfo))
		return;
	
	CView::OnFilePrint();

}


void CPCShopView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPCShopView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}

// OLE Server support

// The following command handler provides the standard keyboard
//  user interface to cancel an in-place editing session.  Here,
//  the server (not the container) causes the deactivation
void CPCShopView::OnCancelEditSrvr()
{
	GetDocument()->OnDeactivateUI(FALSE);
}


// CPCShopView diagnostics

#ifdef _DEBUG
void CPCShopView::AssertValid() const
{
	COleDBRecordView::AssertValid();
}

void CPCShopView::Dump(CDumpContext& dc) const
{
	COleDBRecordView::Dump(dc);
}

CPCShopDoc* CPCShopView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPCShopDoc)));
	return (CPCShopDoc*)m_pDocument;
}
#endif //_DEBUG


// CPCShopView database support
CRowset<>* CPCShopView::OnGetRowset()
{
	return m_pSet->GetRowsetBase();
}



// CPCShopView message handlers
