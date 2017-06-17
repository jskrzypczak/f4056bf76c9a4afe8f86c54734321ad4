// Projekt winda.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Projekt winda.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

#pragma region MainWindowDivision

const int Mainrect_x = 200;
const int Mainrect_y = 0;
const int Mainrect_height = 698;
const int Mainrect_width = 700;

const int Floor_height = 128;
const int Floor_width = 300;

const int Elevator_height = Mainrect_height;
const int Elevator_width = 200;

const int Exit_height = Floor_height;
const int Exit_width = 200;

RECT MAINRECT = { Mainrect_x, Mainrect_y, Mainrect_x + Mainrect_width, Mainrect_y + Mainrect_height };

RECT FLOOR_4 = { Mainrect_x, Mainrect_y + Floor_height *0, Mainrect_x + Floor_width, Mainrect_y + Floor_height *1 };
RECT FLOOR_3 = { Mainrect_x, Mainrect_y + Floor_height *1, Mainrect_x + Floor_width, Mainrect_y + Floor_height *2 };
RECT FLOOR_2 = { Mainrect_x, Mainrect_y + Floor_height *2, Mainrect_x + Floor_width, Mainrect_y + Floor_height *3 };
RECT FLOOR_1 = { Mainrect_x, Mainrect_y + Floor_height *3, Mainrect_x + Floor_width, Mainrect_y + Floor_height *4 };
RECT FLOOR_0 = { Mainrect_x, Mainrect_y + Floor_height *4, Mainrect_x + Floor_width, Mainrect_y + Floor_height *5 };

RECT ELEVATOR = {	Mainrect_x + Floor_width, 
					Mainrect_y, 
					Mainrect_x + Floor_width + Elevator_width,
					Mainrect_y + Elevator_height };

RECT EXIT_4 = {		Mainrect_x + Floor_width + Elevator_width,
					Mainrect_y + Exit_height * 0,
					Mainrect_x + Floor_width + Elevator_width + Exit_width,
					Mainrect_y + Exit_height * 1 };

RECT EXIT_3 = {		Mainrect_x + Floor_width + Elevator_width,
					Mainrect_y + Exit_height * 1,
					Mainrect_x + Floor_width + Elevator_width + Exit_width,
					Mainrect_y + Exit_height * 2 };

RECT EXIT_2 = {		Mainrect_x + Floor_width + Elevator_width,
					Mainrect_y + Exit_height * 2,
					Mainrect_x + Floor_width + Elevator_width + Exit_width,
					Mainrect_y + Exit_height * 3 };

RECT EXIT_1 = {		Mainrect_x + Floor_width + Elevator_width,
					Mainrect_y + Exit_height * 3,
					Mainrect_x + Floor_width + Elevator_width + Exit_width,
					Mainrect_y + Exit_height * 4 };

RECT EXIT_0 = {		Mainrect_x + Floor_width + Elevator_width,
					Mainrect_y + Exit_height * 4,
					Mainrect_x + Floor_width + Elevator_width + Exit_width,
					Mainrect_y + Exit_height * 5 };

#pragma endregion

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

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
    LoadStringW(hInstance, IDC_PROJEKTWINDA, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PROJEKTWINDA));

    MSG msg;

	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);


    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

	GdiplusShutdown(gdiplusToken);

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJEKTWINDA));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_PROJEKTWINDA);
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
      0, 0, 900, 698, nullptr, nullptr, hInstance, nullptr);

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
			/*FillRect(hdc, &MAINRECT, (HBRUSH)(COLOR_WINDOW + 13));
			FillRect(hdc, &FLOOR_4, (HBRUSH)(COLOR_WINDOW + 9));
			FillRect(hdc, &FLOOR_3, (HBRUSH)(COLOR_WINDOW + 8));
			FillRect(hdc, &FLOOR_2, (HBRUSH)(COLOR_WINDOW + 7));
			FillRect(hdc, &FLOOR_1, (HBRUSH)(COLOR_WINDOW + 6));
			FillRect(hdc, &FLOOR_0, (HBRUSH)(COLOR_WINDOW + 5));

			FillRect(hdc, &ELEVATOR, (HBRUSH)(COLOR_WINDOW + 14));

			FillRect(hdc, &EXIT_4, (HBRUSH)(COLOR_WINDOW + 9));
			FillRect(hdc, &EXIT_3, (HBRUSH)(COLOR_WINDOW + 8));
			FillRect(hdc, &EXIT_2, (HBRUSH)(COLOR_WINDOW + 7));
			FillRect(hdc, &EXIT_1, (HBRUSH)(COLOR_WINDOW + 6));
			FillRect(hdc, &EXIT_0, (HBRUSH)(COLOR_WINDOW + 5));*/


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
