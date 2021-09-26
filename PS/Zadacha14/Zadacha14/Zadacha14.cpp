// Zadacha14.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Zadacha14.h"
#include "commctrl.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Zadacha14(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_ZADACHA14, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_ZADACHA14));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ZADACHA14));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_ZADACHA14);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
			case ID_ZADACHA14_OPEN_DIALOG:
				DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, Zadacha14);
				break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

#define MY_TIMER 500

INT_PTR CALLBACK Zadacha14(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{

		case WM_INITDIALOG:
		{
			SendDlgItemMessage(hDlg, IDC_COMBO_C, CB_ADDSTRING, 0, (LPARAM) "17.4");
			SendDlgItemMessage(hDlg, IDC_COMBO_C, CB_ADDSTRING, 0, (LPARAM) "-9.1");
			return (INT_PTR)TRUE;
		}

		case WM_COMMAND:
		{
			if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
			{
				EndDialog(hDlg, LOWORD(wParam));
				return (INT_PTR)TRUE;
			}
			else if (LOWORD(wParam) == IDC_BUTTON_INSERT)
			{
				char input[100];
				GetDlgItemText(hDlg, IDC_EDIT_INSERT, input, 100);

				if (SendDlgItemMessage(hDlg, IDC_COMBO_INSERT, CB_FINDSTRING, 0, (LPARAM)input) < 0)
				{
					SendDlgItemMessage(hDlg, IDC_COMBO_INSERT, CB_ADDSTRING, 0, (LPARAM)input);
				}
			}
			else if (LOWORD(wParam) == IDC_BUTTON_EQUALS)
			{
				char aText[100], bText[100], cText[100], resultText[100];
				double a = 0, b = 0, c = 0, result = 0;

				if (IsDlgButtonChecked(hDlg, IDC_CHECK_A))
				{
					GetDlgItemText(hDlg, IDC_EDIT_A, aText, 100);
					a = atof(aText);
				}
				if (IsDlgButtonChecked(hDlg, IDC_CHECK_B))
				{
					GetDlgItemText(hDlg, IDC_EDIT_B, bText, 100);
					b = atof(bText);
				}
				if (IsDlgButtonChecked(hDlg, IDC_CHECK_C))
				{
					int index = SendDlgItemMessage(hDlg, IDC_COMBO_C, CB_GETCURSEL, 0, 0);
					SendDlgItemMessage(hDlg, IDC_COMBO_C, CB_GETLBTEXT, index, (LPARAM)cText);
					c = atof(cText);
				}

				if (!IsDlgButtonChecked(hDlg, IDC_CHECK_A) &&
					!IsDlgButtonChecked(hDlg, IDC_CHECK_B) &&
					!IsDlgButtonChecked(hDlg, IDC_CHECK_C))
					SetDlgItemText(hDlg, IDC_EDIT_RESULT, "0");
				else 
				{
					result = c + b - a;
					_gcvt_s(resultText, 100, result, 5);
					SetDlgItemText(hDlg, IDC_EDIT_RESULT, resultText);
				}

			}

			if (LOWORD(wParam) == IDC_BUTTON_START) {
				SetTimer(hDlg, MY_TIMER, 100, NULL);
				break;
			}

			if (LOWORD(wParam) == IDC_BUTTON_STOP) {
				KillTimer(hDlg, MY_TIMER);

				SetDlgItemInt(hDlg, IDC_EDIT_TIMER, 0, NULL);

				SendDlgItemMessage(hDlg, IDC_PROGRESS_1, PBM_SETPOS, 0, 0);
				SendDlgItemMessage(hDlg, IDC_PROGRESS_2, PBM_SETPOS, 0, 0);

				break;
			}


			break;
		}

		case WM_TIMER:
		{
			int counter = GetDlgItemInt(hDlg, IDC_EDIT_TIMER, NULL, FALSE);
			counter += 1;
			SetDlgItemInt(hDlg, IDC_EDIT_TIMER, counter, NULL);

			if (SendDlgItemMessage(hDlg, IDC_RADIO_1, BM_GETCHECK, 0, 0)) 
			{
				SendDlgItemMessage(hDlg, IDC_PROGRESS_1, PBM_SETSTEP, 3, 0);
				SendDlgItemMessage(hDlg, IDC_PROGRESS_1, PBM_STEPIT, 0, 0);
			}
			else if (SendDlgItemMessage(hDlg, IDC_RADIO_2, BM_GETCHECK, 0, 0))
			{
				SendDlgItemMessage(hDlg, IDC_PROGRESS_2, PBM_SETSTEP, 3, 0);
				SendDlgItemMessage(hDlg, IDC_PROGRESS_2, PBM_STEPIT, 0, 0);
			}
		}

	}

	return (INT_PTR)FALSE;
}
