// Projekt winda.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Projekt winda.h"

#define MAX_LOADSTRING 100

#define ID_BUTTON_F4_0 0
#define ID_BUTTON_F4_1 1
#define ID_BUTTON_F4_2 2
#define ID_BUTTON_F4_3 3
#define ID_BUTTON_F4_4 4

#define ID_BUTTON_F3_0 5
#define ID_BUTTON_F3_1 6
#define ID_BUTTON_F3_2 7
#define ID_BUTTON_F3_3 8
#define ID_BUTTON_F3_4 9

#define ID_BUTTON_F2_0 10
#define ID_BUTTON_F2_1 11
#define ID_BUTTON_F2_2 12
#define ID_BUTTON_F2_3 13
#define ID_BUTTON_F2_4 14

#define ID_BUTTON_F1_0 15
#define ID_BUTTON_F1_1 16
#define ID_BUTTON_F1_2 17
#define ID_BUTTON_F1_3 18
#define ID_BUTTON_F1_4 19

#define ID_BUTTON_F0_0 20
#define ID_BUTTON_F0_1 21
#define ID_BUTTON_F0_2 22
#define ID_BUTTON_F0_3 23
#define ID_BUTTON_F0_4 24

#define ID_EDIT_F4 25
#define ID_EDIT_F3 26
#define ID_EDIT_F2 27
#define ID_EDIT_F1 28
#define ID_EDIT_F0 29


// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
HWND Floor_4_Passengrs;
HWND Floor_3_Passengrs;
HWND Floor_2_Passengrs;
HWND Floor_1_Passengrs;
HWND Floor_0_Passengrs;

INT i;

//Region rect1;


const int margin = 6;

#pragma region MainWindowDivision

const int Mainrect_x = 200;
const int Mainrect_y = 0;
const int Mainrect_height = 700;
const int Mainrect_width = 700;

const int Floor_height = 130;
const int Floor_width = 300;

const int ElevatorShaft_height = 665;
const int ElevatorShaft_width = 200;

const int Exit_height = Floor_height;
const int Exit_width = 170;

const WORD IDT_TIMER1 = 1;

RECT MAINRECT = { Mainrect_x, Mainrect_y, Mainrect_x + Mainrect_width, Mainrect_y + Mainrect_height };

RECT FLOOR_4 = { Mainrect_x, Mainrect_y + Floor_height *0, Mainrect_x + Floor_width, Mainrect_y + Floor_height *1 };
RECT FLOOR_3 = { Mainrect_x, Mainrect_y + Floor_height *1, Mainrect_x + Floor_width, Mainrect_y + Floor_height *2 };
RECT FLOOR_2 = { Mainrect_x, Mainrect_y + Floor_height *2, Mainrect_x + Floor_width, Mainrect_y + Floor_height *3 };
RECT FLOOR_1 = { Mainrect_x, Mainrect_y + Floor_height *3, Mainrect_x + Floor_width, Mainrect_y + Floor_height *4 };
RECT FLOOR_0 = { Mainrect_x, Mainrect_y + Floor_height *4, Mainrect_x + Floor_width, Mainrect_y + Floor_height *5 };

RECT ELEVATOR_SHAFT = {	Mainrect_x + Floor_width, 
					Mainrect_y, 
					Mainrect_x + Floor_width + ElevatorShaft_width,
					Mainrect_y + ElevatorShaft_height };

RECT EXIT_4 = {		Mainrect_x + Floor_width + ElevatorShaft_width,
					Mainrect_y + Exit_height * 0,
					Mainrect_x + Floor_width + ElevatorShaft_width + Exit_width,
					Mainrect_y + Exit_height * 1 };

RECT EXIT_3 = {		Mainrect_x + Floor_width + ElevatorShaft_width,
					Mainrect_y + Exit_height * 1,
					Mainrect_x + Floor_width + ElevatorShaft_width + Exit_width,
					Mainrect_y + Exit_height * 2 };

RECT EXIT_2 = {		Mainrect_x + Floor_width + ElevatorShaft_width,
					Mainrect_y + Exit_height * 2,
					Mainrect_x + Floor_width + ElevatorShaft_width + Exit_width,
					Mainrect_y + Exit_height * 3 };

RECT EXIT_1 = {		Mainrect_x + Floor_width + ElevatorShaft_width,
					Mainrect_y + Exit_height * 3,
					Mainrect_x + Floor_width + ElevatorShaft_width + Exit_width,
					Mainrect_y + Exit_height * 4 };

RECT EXIT_0 = {		Mainrect_x + Floor_width + ElevatorShaft_width,
					Mainrect_y + Exit_height * 4,
					Mainrect_x + Floor_width + ElevatorShaft_width + Exit_width,
					Mainrect_y + Exit_height * 5 };

#pragma endregion

RECT rect1 = {	Mainrect_x + Floor_width + 3,			//	rectangle in which elevator moves
				Mainrect_y + margin + 3,				
				Mainrect_x + Floor_width + ElevatorShaft_width - 4,			
				Mainrect_y + margin + Floor_height - 7 };
 

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

PAINTSTRUCT ps;
//HDC hdc;

void DrawElevator(HDC, HWND);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

	i = 0;

	/*HRGN CreateRectRegion(
		 Mainrect_x + Floor_width + 3,
		Mainrect_y + margin + 3,
		_In_ int nRightRect,
		_In_ int nBottomRect
	);*/
	


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
   int button_size = 30;

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      0, 0, Mainrect_width + 200, Mainrect_height+30, nullptr, nullptr, hInstance, nullptr);
   //HDC hdc;
   //hdc = GetDC(hWnd);

#pragma region Buttons

   Floor_4_Passengrs = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER,
	   40 + button_size * 1, 5 + margin + Floor_height * 0 + button_size * 2, button_size, button_size, hWnd, (HMENU)ID_EDIT_F4, hInstance, NULL);

   HWND B_F4_0 = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"0", WS_CHILD | WS_VISIBLE | WS_BORDER,
	   40 + button_size * 0, 5 + margin + Floor_height * 0 + button_size * 2, button_size, button_size, hWnd, (HMENU)ID_BUTTON_F4_0, hInstance, NULL);

   HWND B_F4_1 = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"1", WS_CHILD | WS_VISIBLE | WS_BORDER,
	   40 + button_size * 1, 5 + margin + Floor_height * 0 + button_size * 1, button_size, button_size, hWnd, (HMENU)ID_BUTTON_F4_1, hInstance, NULL);

   HWND B_F4_2 = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"2", WS_CHILD | WS_VISIBLE | WS_BORDER,
	   40 + button_size * 0, 5 + margin + Floor_height * 0 + button_size * 1, button_size, button_size, hWnd, (HMENU)ID_BUTTON_F4_2, hInstance, NULL);

   HWND B_F4_3 = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"3", WS_CHILD | WS_VISIBLE | WS_BORDER,
	   40 + button_size * 1, 5 + margin + Floor_height * 0 + button_size * 0, button_size, button_size, hWnd, (HMENU)ID_BUTTON_F4_3, hInstance, NULL);

   HWND B_F4_4 = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"-", WS_CHILD | WS_VISIBLE | WS_BORDER,
	   40 + button_size * 0, 5 + margin + Floor_height * 0 + button_size * 0, button_size, button_size, hWnd, (HMENU)ID_BUTTON_F4_4, hInstance, NULL);


   Floor_3_Passengrs = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER,
	   40 + button_size * 1, 5 + margin + Floor_height * 1 + button_size * 2, button_size, button_size, hWnd, (HMENU)ID_EDIT_F3, hInstance, NULL);

   HWND B_F3_0 = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"0", WS_CHILD | WS_VISIBLE | WS_BORDER,
	   40 + button_size * 0, 5 + margin + Floor_height * 1 + button_size * 2, button_size, button_size, hWnd, (HMENU)ID_BUTTON_F3_0, hInstance, NULL);

   HWND B_F3_1 = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"1", WS_CHILD | WS_VISIBLE | WS_BORDER,
	   40 + button_size * 1, 5 + margin + Floor_height * 1 + button_size * 1, button_size, button_size, hWnd, (HMENU)ID_BUTTON_F3_1, hInstance, NULL);

   HWND B_F3_2 = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"2", WS_CHILD | WS_VISIBLE | WS_BORDER,
	   40 + button_size * 0, 5 + margin + Floor_height * 1 + button_size * 1, button_size, button_size, hWnd, (HMENU)ID_BUTTON_F3_2, hInstance, NULL);

   HWND B_F3_3 = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"-", WS_CHILD | WS_VISIBLE | WS_BORDER,
	   40 + button_size * 1, 5 + margin + Floor_height * 1 + button_size * 0, button_size, button_size, hWnd, (HMENU)ID_BUTTON_F3_3, hInstance, NULL);
																											  
   HWND B_F3_4 = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"4", WS_CHILD | WS_VISIBLE | WS_BORDER,		  
	   40 + button_size * 0, 5 + margin + Floor_height * 1 + button_size * 0, button_size, button_size, hWnd, (HMENU)ID_BUTTON_F3_4, hInstance, NULL);


   Floor_2_Passengrs = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER,
	   40 + button_size * 1, 5 + margin + Floor_height * 2 + button_size * 2, button_size, button_size, hWnd, (HMENU)ID_EDIT_F2, hInstance, NULL);

   HWND B_F2_0 = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"0", WS_CHILD | WS_VISIBLE | WS_BORDER,
	   40 + button_size * 0, 5 + margin + Floor_height * 2 + button_size * 2, button_size, button_size, hWnd, (HMENU)ID_BUTTON_F2_0, hInstance, NULL);

   HWND B_F2_1 = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"1", WS_CHILD | WS_VISIBLE | WS_BORDER,
	   40 + button_size * 1, 5 + margin + Floor_height * 2 + button_size * 1, button_size, button_size, hWnd, (HMENU)ID_BUTTON_F2_1, hInstance, NULL);

   HWND B_F2_2 = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"-", WS_CHILD | WS_VISIBLE | WS_BORDER,
	   40 + button_size * 0, 5 + margin + Floor_height * 2 + button_size * 1, button_size, button_size, hWnd, (HMENU)ID_BUTTON_F2_2, hInstance, NULL);

   HWND B_F2_3 = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"3", WS_CHILD | WS_VISIBLE | WS_BORDER,
	   40 + button_size * 1, 5 + margin + Floor_height * 2 + button_size * 0, button_size, button_size, hWnd, (HMENU)ID_BUTTON_F2_3, hInstance, NULL);

   HWND B_F2_4 = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"4", WS_CHILD | WS_VISIBLE | WS_BORDER,
	   40 + button_size * 0, 5 + margin + Floor_height * 2 + button_size * 0, button_size, button_size, hWnd, (HMENU)ID_BUTTON_F2_4, hInstance, NULL);


   Floor_1_Passengrs = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER,
	   40 + button_size * 1, 5 + margin + Floor_height * 3 + button_size * 2, button_size, button_size, hWnd, (HMENU)ID_EDIT_F1, hInstance, NULL);

   HWND B_F1_0 = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"0", WS_CHILD | WS_VISIBLE | WS_BORDER,
	   40 + button_size * 0, 5 + margin + Floor_height * 3 + button_size * 2, button_size, button_size, hWnd, (HMENU)ID_BUTTON_F1_0, hInstance, NULL);

   HWND B_F1_1 = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"-", WS_CHILD | WS_VISIBLE | WS_BORDER,
	   40 + button_size * 1, 5 + margin + Floor_height * 3 + button_size * 1, button_size, button_size, hWnd, (HMENU)ID_BUTTON_F1_1, hInstance, NULL);

   HWND B_F1_2 = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"2", WS_CHILD | WS_VISIBLE | WS_BORDER,
	   40 + button_size * 0, 5 + margin + Floor_height * 3 + button_size * 1, button_size, button_size, hWnd, (HMENU)ID_BUTTON_F1_2, hInstance, NULL);

   HWND B_F1_3 = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"3", WS_CHILD | WS_VISIBLE | WS_BORDER,
	   40 + button_size * 1, 5 + margin + Floor_height * 3 + button_size * 0, button_size, button_size, hWnd, (HMENU)ID_BUTTON_F1_3, hInstance, NULL);

   HWND B_F1_4 = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"4", WS_CHILD | WS_VISIBLE | WS_BORDER,
	   40 + button_size * 0, 5 + margin + Floor_height * 3 + button_size * 0, button_size, button_size, hWnd, (HMENU)ID_BUTTON_F1_4, hInstance, NULL);


   Floor_0_Passengrs = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER,
	   40 + button_size * 1, 5 + margin + Floor_height * 4 + button_size * 2, button_size, button_size, hWnd, (HMENU)ID_EDIT_F0, hInstance, NULL);

   HWND B_F0_0 = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"-", WS_CHILD | WS_VISIBLE | WS_BORDER,
	   40 + button_size * 0, 5 + margin + Floor_height * 4 + button_size * 2, button_size, button_size, hWnd, (HMENU)ID_BUTTON_F0_0, hInstance, NULL);

   HWND B_F0_1 = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"1", WS_CHILD | WS_VISIBLE | WS_BORDER,
	   40 + button_size * 1, 5 + margin + Floor_height * 4 + button_size * 1, button_size, button_size, hWnd, (HMENU)ID_BUTTON_F0_1, hInstance, NULL);

   HWND B_F0_2 = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"2", WS_CHILD | WS_VISIBLE | WS_BORDER,
	   40 + button_size * 0, 5 + margin + Floor_height * 4 + button_size * 1, button_size, button_size, hWnd, (HMENU)ID_BUTTON_F0_2, hInstance, NULL);

   HWND B_F0_3 = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"3", WS_CHILD | WS_VISIBLE | WS_BORDER,
	   40 + button_size * 1, 5 + margin + Floor_height * 4 + button_size * 0, button_size, button_size, hWnd, (HMENU)ID_BUTTON_F0_3, hInstance, NULL);

   HWND B_F0_4 = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"4", WS_CHILD | WS_VISIBLE | WS_BORDER,
	   40 + button_size * 0, 5 + margin + Floor_height * 4 + button_size * 0, button_size, button_size, hWnd, (HMENU)ID_BUTTON_F0_4, hInstance, NULL);

#pragma endregion
   
#pragma region Timer   
   SetTimer(hWnd, 
			IDT_TIMER1, 
			100,		
			0);


#pragma endregion
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
	case WM_TIMER:
		{
			switch(wParam)
				case IDT_TIMER1:
					InvalidateRect(hWnd, &rect1, TRUE);
					HDC hdc = BeginPaint(hWnd, &ps);
					DrawElevator(hdc, hWnd);
					EndPaint(hWnd, &ps);
				//break;

		}
    case WM_PAINT:
        {
            //PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

#pragma region Frame
			Graphics graphics(hdc);
			//Pen Pen_rect(Color(255,252,23,3), 3);
			Pen Pen(Color(255, 0, 0, 0), 2);
			graphics.DrawLine(	&Pen,						//lewa sciana szybu
								Mainrect_x + Floor_width, 
								Mainrect_y + margin,
								Mainrect_x + Floor_width,
								Mainrect_y + ElevatorShaft_height);
								
			graphics.DrawLine(	&Pen,
								Mainrect_x + Floor_width + ElevatorShaft_width,
								Mainrect_y + margin, 
								Mainrect_x + Floor_width + ElevatorShaft_width, 
								Mainrect_y + ElevatorShaft_height);

			for (int i = 1; i <= 5; i++) 
			{
				graphics.DrawLine(	&Pen,
									Mainrect_x,
									Mainrect_y + Floor_height * i,
									Mainrect_x + Floor_width,
									Mainrect_y + Floor_height * i);
			}

			for (int i = 1; i <= 5; i++)
			{
				graphics.DrawLine(	&Pen,
									Mainrect_x + Floor_width + ElevatorShaft_width,
									Mainrect_y + Floor_height * i,
									Mainrect_x + Floor_width + ElevatorShaft_width + Exit_width,
									Mainrect_y + Floor_height * i);
			}

			graphics.DrawLine(	&Pen,
								Mainrect_x + Floor_width,
								Mainrect_y + margin,
								Mainrect_x + Floor_width + ElevatorShaft_width,
								Mainrect_y + margin);

			graphics.DrawLine(	&Pen,
								Mainrect_x + Floor_width,
								Mainrect_y + ElevatorShaft_height,
								Mainrect_x + Floor_width + ElevatorShaft_width,
								Mainrect_y + ElevatorShaft_height);
#pragma endregion

#pragma region Elevator

			//Graphics graphics(hdc);
			/*graphics.DrawRectangle(	&Pen_rect, 
								Mainrect_x + Floor_width+3,			//const.
								Mainrect_y + margin+3,				//variable
								ElevatorShaft_width - 7,			//const.
								Floor_height - 10);					//const.*/
			
#pragma endregion



			// TODO: Add any drawing code that uses hdc here...
			/*FillRect(hdc, &MAINRECT, (HBRUSH)(COLOR_WINDOW + 13));
			FillRect(hdc, &FLOOR_4, (HBRUSH)(COLOR_WINDOW + 9));
			FillRect(hdc, &FLOOR_3, (HBRUSH)(COLOR_WINDOW + 8));
			FillRect(hdc, &FLOOR_2, (HBRUSH)(COLOR_WINDOW + 7));
			FillRect(hdc, &FLOOR_1, (HBRUSH)(COLOR_WINDOW + 6));
			FillRect(hdc, &FLOOR_0, (HBRUSH)(COLOR_WINDOW + 5));
			FillRect(hdc, &ElevatorShaft, (HBRUSH)(COLOR_WINDOW + 14));
			FillRect(hdc, &EXIT_4, (HBRUSH)(COLOR_WINDOW + 9));
			FillRect(hdc, &EXIT_3, (HBRUSH)(COLOR_WINDOW + 8));
			FillRect(hdc, &EXIT_2, (HBRUSH)(COLOR_WINDOW + 7));
			FillRect(hdc, &EXIT_1, (HBRUSH)(COLOR_WINDOW + 6));
			FillRect(hdc, &EXIT_0, (HBRUSH)(COLOR_WINDOW + 5));*/
			/*MoveToEx(hdc, Mainrect_x + Floor_width, Mainrect_y, NULL);
			LineTo(hdc, Mainrect_x + Floor_width, Mainrect_y + ElevatorShaft_height);
			MoveToEx(hdc, Mainrect_x + Floor_width + ElevatorShaft_width, Mainrect_y, NULL);
			LineTo(hdc, Mainrect_x + Floor_width + ElevatorShaft_width, Mainrect_y + ElevatorShaft_height);*/
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
void DrawElevator(HDC hdc, HWND hWnd)
{
	
	i++;
	//PAINTSTRUCT ps;
	//HDC hdc = BeginPaint(hWnd, &ps);
	//hdc = GetDC(hWnd);
	Graphics graphics(hdc);
	Pen Pen_rect((120,32,42,123),3);
	graphics.DrawRectangle(&Pen_rect,
		Mainrect_x + Floor_width + 3,				//const.
		Mainrect_y + margin + 3 + i,				//variable, the move of the elevator
		ElevatorShaft_width - 7,					//const.
		Floor_height - 10);
	//EndPaint(hWnd, &ps);
	//graphics.ReleaseHDC(hdc);
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
