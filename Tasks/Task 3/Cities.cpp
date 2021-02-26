
// Cities.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "Cities.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "CitiesSet.h"
#include "CitiesDoc.h"
#include "CitiesView.h"
#include "Operations.h"
#include "CitiesTable.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCitiesApp

BEGIN_MESSAGE_MAP(CCitiesApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CCitiesApp::OnAppAbout)
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
END_MESSAGE_MAP()


// CCitiesApp construction

CCitiesApp::CCitiesApp()
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
	SetAppID(_T("Cities.AppID.NoVersion"));

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

// The one and only CCitiesApp object

CCitiesApp theApp;


// CCitiesApp initialization

#define PERSON_ID_TO_SEARCH 4
#define CITY_ID_TO_SEARCH 5
#define CITY_NAME "Petrich"
#define CITY_REGION "Petrich Province"
#define INIT_UPDATE_COUNTER 0

BOOL CCitiesApp::InitInstance()
{
	HRESULT hResult = CoInitialize(0);

	CString message;
	message.AppendFormat(_T("TASK 3: \r\n"));

	/////////Task 3/////////
	CCitiesTable oCitiesTable;
	CITIES oCity;
	
	//UPDATE BY ID
	oCity.lID = CITY_ID_TO_SEARCH;
	wcscpy_s(oCity.szCITY_NAME, _T("Ruse test 2222"));
	wcscpy_s(oCity.szREGION, _T("Ruse Province test"));
	oCitiesTable.UpdateWhereID((long)CITY_ID_TO_SEARCH, oCity, hResult);
	
	//SELECT BY ID
	oCitiesTable.SelectWhereID((long)CITY_ID_TO_SEARCH, oCity, hResult);
	message.AppendFormat(_T("City with ID - %d from DB: %s, %s\r\n"),
		oCity.lID, oCity.szCITY_NAME, oCity.szREGION);

	//INSERT 
	//CITIES oCityInsert;
	//oCityInsert.lUPDATE_COUNTER = INIT_UPDATE_COUNTER;
	//wcscpy_s(oCityInsert.szCITY_NAME, _T(CITY_NAME));
	//wcscpy_s(oCityInsert.szREGION, _T(CITY_REGION));
	//oCitiesTable.Insert(oCityInsert, hResult);

	//DELETE BY ID
	//oCitiesTable.DeleteWhereID(11, hResult);
	//oCitiesTable.DeleteWhereID(12, hResult);

	
	//SELECT ALL
	CCitiesArray oCitiesDB;
	oCitiesTable.SelectAll(oCitiesDB, hResult);

	message.AppendFormat(_T("Cities from DB:\r\n"));
	for (int i = 0; i < oCitiesDB.GetCount(); i++)
	{
		message.AppendFormat(_T("ID: %d, UPDATE_COUNTER: %d, CITY_NAME: %s, REGION: %s\r\n"),
			oCitiesDB.GetAt(i)->lID, oCitiesDB.GetAt(i)->lUPDATE_COUNTER,
			oCitiesDB.GetAt(i)->szCITY_NAME, oCitiesDB.GetAt(i)->szREGION);
	}

	message.AppendFormat(_T("\r\nTASK 2: \r\n"));

	/////////Task 2/////////
	//Init containers
	CCitiesArray oCities;
	CPersonsArray oPersons;
	CPhone_TypesArray oPhoneTypes;
	CPhone_NumbersArray oPhoneNumbers;
	CPersonsCitiesMap oPersonsCities;
	CPhone_NumbersMap oPhoneNumbersMap;

	//Fill containers
	Operations* o1 = new Operations();
	o1->CreateCities(oCities);
	o1->CreatePersons(oPersons);
	o1->CreatePhoneTypes(oPhoneTypes);
	o1->CreatePhoneNumbers(oPhoneNumbers);
	o1->FillPersonsCities(oPersonsCities, oPersons, oCities);
	o1->FillPhoneNumbers(oPhoneNumbersMap);
	
	//print data from containers
	message.AppendFormat(_T("Cities:\r\n"));
	for (int i = 0; i < oCities.GetCount(); i++)
	{
		message.AppendFormat(_T("ID: %d (%s), "), oCities.GetAt(i)->lID, oCities.GetAt(i)->szCITY_NAME);
	}

	message.AppendFormat(_T("\r\nPersons:\r\n"));
	for (int i = 0; i < oPersons.GetCount(); i++)
	{
		message.AppendFormat(_T("%s %s, "), oPersons.GetAt(i)->szFIRST_NAME, oPersons.GetAt(i)->szLAST_NAME);
	}

	message.AppendFormat(_T("\r\nPhone Types:\r\n"));
	for (int i = 0; i < oPhoneTypes.GetCount(); i++)
	{
		message.AppendFormat(_T("ID: %d (%s), "), oPhoneTypes.GetAt(i)->lID, oPhoneTypes.GetAt(i)->szPHONE_TYPE);
	}

	message.AppendFormat(_T("\r\nPhone Numbers:\r\n"));
	for (int i = 0; i < oPhoneNumbers.GetCount(); i++)
	{
		message.AppendFormat(_T("PERSON_ID: %d (%s), "), oPhoneNumbers.GetAt(i)->lID, oPhoneNumbers.GetAt(i)->szNUMBER);
	}

	message.AppendFormat(_T("\r\nPersons - Cities:\r\n"));
	POSITION pos = oPersonsCities.GetStartPosition();
	for (int i = 0; i < oPersonsCities.GetCount(); i++)
	{		
		int nKey;
		CITIES recCity;
		oPersonsCities.GetNextAssoc(pos, nKey, recCity);
		message.AppendFormat(_T("PERSON_ID: %d live in %s\r\n "), nKey, recCity.szCITY_NAME);
	}

	message.AppendFormat(_T("\r\nSearch phone number by ID: %d\r\n"), PERSON_ID_TO_SEARCH);
	pos = oPhoneNumbersMap.GetStartPosition();
	for (int i = 0; i < oPhoneNumbersMap.GetCount(); i++)
	{
		int nKey;
		PHONE_NUMBERS recPhoneNumber;
		oPhoneNumbersMap.GetNextAssoc(pos, nKey, recPhoneNumber);
		if ((int)PERSON_ID_TO_SEARCH == nKey)
			message.AppendFormat(_T("NUMBERS: %s, "), recPhoneNumber.szNUMBER);
	}

	AfxMessageBox(message);

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

	CoInitialize(NULL);

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
	pDocTemplate = new CMultiDocTemplate(IDR_CitiesTYPE,
		RUNTIME_CLASS(CCitiesDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CCitiesView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

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



	// Dispatch commands specified on the command line.  Will return FALSE if
	// app was launched with /RegServer, /Register, /Unregserver or /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// The main window has been initialized, so show and update it
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}

int CCitiesApp::ExitInstance()
{
	//TODO: handle additional resources you may have added
	AfxOleTerm(FALSE);

	CoUninitialize();

	return CWinAppEx::ExitInstance();
}

// CCitiesApp message handlers


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
void CCitiesApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CCitiesApp customization load/save methods

void CCitiesApp::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
}

void CCitiesApp::LoadCustomState()
{
}

void CCitiesApp::SaveCustomState()
{
}

// CCitiesApp message handlers



