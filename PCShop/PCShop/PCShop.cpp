
// PCShop.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "PCShop.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "IpFrame.h"
#include "PCShopSet.h"
#include "PCShopDoc.h"
#include "PCShopView.h"

#include "ConnectionProps.h"
#include "ProductTypesTable.h"
#include "ProductsTable.h"
#include "MemoryArray.h"
#include "Products.h"
#include "DBConnection.h"

#include "RacksView.h"
#include "BrandsView.h"
#include "ModelsView.h"
#include "ProductTypesView.h"
#include "ShelvesView.h"
#include "ProductsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPCShopApp

BEGIN_MESSAGE_MAP(CPCShopApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CPCShopApp::OnAppAbout)
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
END_MESSAGE_MAP()


// CPCShopApp construction

CPCShopApp::CPCShopApp()
{
	m_bHiColorIcons = TRUE;

	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// If the application is built using Common Language Runtime support (/clr):
	//     1) This additional setting is needed for Restart Manager support to work properly.
	//     2) In your project, you must add a reference to System.Windows.Forms in order to build.
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: replace application ID string below with unique ID string; recommended
	// format for string is CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("PCShop.AppID.NoVersion"));

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

// The one and only CPCShopApp object

CPCShopApp theApp;
// This identifier was generated to be statistically unique for your app
// You may change it if you prefer to choose a specific identifier

// {C7CFE5C8-DCFC-4EFA-844F-254A2EA3BE7D}
static const CLSID clsid =
{ 0xC7CFE5C8, 0xDCFC, 0x4EFA, { 0x84, 0x4F, 0x25, 0x4A, 0x2E, 0xA3, 0xBE, 0x7D } };


// CPCShopApp initialization

BOOL CPCShopApp::InitInstance()
{
	CoInitialize(0);
	DBConnection::GetInstance().CreateConnection();
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();

	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();
	
	EnableTaskbarInteraction();

	// AfxInitRichEdit2() is required to use RichEdit control	
	// AfxInitRichEdit2();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));
	LoadStdProfileSettings(4);  // Load standard INI file options (including MRU)


	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views
	CMultiDocTemplate* pDocTemplate;

	pDocTemplate = new CMultiDocTemplate(IDR_PRODUCTS_VIEW,
		RUNTIME_CLASS(ProductsDocument),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(ProductsView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	pDocTemplate = new CMultiDocTemplate(IDR_RACKS_VIEW,
		RUNTIME_CLASS(RacksDocument),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(RacksView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	pDocTemplate = new CMultiDocTemplate(IDR_BRANDS_VIEW,
		RUNTIME_CLASS(BrandsDocument),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(BrandsView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	pDocTemplate = new CMultiDocTemplate(IDR_MODELS_VIEW,
		RUNTIME_CLASS(ModelsDocument),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(ModelsView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	pDocTemplate = new CMultiDocTemplate(IDR_PRODUCT_TYPES_VIEW,
		RUNTIME_CLASS(ProductTypesDocument),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(ProductTypesView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	pDocTemplate = new CMultiDocTemplate(IDR_SHELVES_VIEW,
		RUNTIME_CLASS(ShelvesDocument),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(ShelvesView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	//CMultiDocTemplate* pDocTemplate;
	//pDocTemplate = new CMultiDocTemplate(IDR_PCShopTYPE,
	//	RUNTIME_CLASS(CPCShopDoc),
	//	RUNTIME_CLASS(CChildFrame), // custom MDI child frame
	//	RUNTIME_CLASS(CPCShopView));
	//if (!pDocTemplate)
	//	return FALSE;
	//pDocTemplate->SetContainerInfo(IDR_PCShopTYPE_CNTR_IP);
	//pDocTemplate->SetServerInfo(
	//	IDR_PCShopTYPE_SRVR_EMB, IDR_PCShopTYPE_SRVR_IP,
	//	RUNTIME_CLASS(CInPlaceFrame));
	//AddDocTemplate(pDocTemplate);
	//// Connect the COleTemplateServer to the document template
	////  The COleTemplateServer creates new documents on behalf
	////  of requesting OLE containers by using information
	////  specified in the document template
	//m_server.ConnectTemplate(clsid, pDocTemplate, FALSE);
	//// Register all OLE server factories as running.  This enables the
	////  OLE libraries to create objects from other applications
	//COleTemplateServer::RegisterAll();
	//	// Note: MDI applications register all server objects without regard
	//	//  to the /Embedding or /Automation on the command line

	// create main MDI Frame window
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;


	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);


	//// App was launched with /Embedding or /Automation switch.
	//// Run app as automation server.
	//if (cmdInfo.m_bRunEmbedded || cmdInfo.m_bRunAutomated)
	//{
	//	// Don't show the main window
	//	return TRUE;
	//}
	//// App was launched with /Unregserver or /Unregister switch.  Unregister
	//// typelibrary.  Other unregistration occurs in ProcessShellCommand().
	//else if (cmdInfo.m_nShellCommand == CCommandLineInfo::AppUnregister)
	//{
	//	m_server.UpdateRegistry(OAT_INPLACE_SERVER, NULL, NULL, FALSE);
	//}
	//// App was launched standalone or with other switches (e.g. /Register
	//// or /Regserver).  Update registry entries, including typelibrary.
	//else
	//{
	//	m_server.UpdateRegistry(OAT_INPLACE_SERVER);
	//}

	// Dispatch commands specified on the command line.  Will return FALSE if
	// app was launched with /RegServer, /Register, /Unregserver or /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// The main window has been initialized, so show and update it
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}

int CPCShopApp::ExitInstance()
{
	//TODO: handle additional resources you may have added
	AfxOleTerm(FALSE);

	CoUninitialize();

	return CWinAppEx::ExitInstance();
}

// CPCShopApp message handlers


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// App command to run the dialog
void CPCShopApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CPCShopApp customization load/save methods

void CPCShopApp::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
}

void CPCShopApp::LoadCustomState()
{
}

void CPCShopApp::SaveCustomState()
{
}

// CPCShopApp message handlers



