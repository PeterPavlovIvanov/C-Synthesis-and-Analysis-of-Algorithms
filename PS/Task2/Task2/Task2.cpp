// Task2.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Task2.h"
#include "resource.h"

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
INT_PTR CALLBACK    A1(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    A12(HWND, UINT, WPARAM, LPARAM);

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
    LoadStringW(hInstance, IDC_TASK2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TASK2));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TASK2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_TASK2);
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
			case IDM_EXIT:
				DestroyWindow(hWnd);
				break;
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
			case ID_A1:
			{
				MessageBox(hWnd, _T("Листо А1"), _T("А1"), MB_OK | MB_ICONINFORMATION);
				break;
			}
			case ID_A2:
				{
					HMENU hMenu = GetMenu(hWnd);
					DeleteMenu(hMenu, ID_A8, MF_BYCOMMAND);
					break;
				}
			case ID_A3:
				{
					HMENU hMenu = GetMenu(hWnd);
					UINT res = GetMenuState(hMenu, ID_A4, MF_BYCOMMAND);
					if (res & MF_CHECKED)
						CheckMenuItem(hMenu, ID_A4, MF_BYCOMMAND | MF_UNCHECKED);
					else
						CheckMenuItem(hMenu, ID_A4, MF_BYCOMMAND | MF_CHECKED);
					break;
				}
			case ID_A4:
				{
					HMENU hMenu = GetMenu(hWnd);
					UINT res = GetMenuState(hMenu, ID_A7, MF_BYCOMMAND);
					if (res & MF_GRAYED)
						EnableMenuItem(hMenu, ID_A7, MF_BYCOMMAND | MF_ENABLED);
					else
						EnableMenuItem(hMenu, ID_A7, MF_BYCOMMAND | MF_GRAYED);
					break;
				}
			case ID_A9:
				{
					HMENU hMenu = GetMenu(hWnd);

					if (GetMenuState(hMenu, ID_A12 + 1, MF_BYCOMMAND) == -1) // or disable
					{
						MENUITEMINFO mii;
						ZeroMemory(&mii, sizeof(mii));
						mii.cbSize = sizeof(mii);
						mii.fMask = MIIM_ID | MIIM_TYPE | MIIM_STATE;
						mii.wID = ID_A12 + 1;
						mii.fType = MFT_STRING;
						mii.dwTypeData = TEXT("A10");
						mii.fState = MFS_ENABLED;

						InsertMenuItem(hMenu, ID_A1 + 1, FALSE, &mii);
					}

					break;
				}
			case ID_A12:
			{
				MessageBox(hWnd, _T("Листо А12"), _T("А12"), MB_OK | MB_ICONINFORMATION);
				break;
			}
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
	case WM_RBUTTONDOWN:
		{
			HMENU hMenu = LoadMenu(hInst, MAKEINTRESOURCE(IDR_MENU1));
			HMENU hSubMenu = GetSubMenu(hMenu, 0);
			POINT pt = { LOWORD(lParam), HIWORD(lParam) };
			ClientToScreen(hWnd, &pt);
			TrackPopupMenu(hSubMenu, TPM_RIGHTBUTTON, pt.x, pt.y, 0, hWnd, NULL);
			DestroyMenu(hMenu);
			break;
		}
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