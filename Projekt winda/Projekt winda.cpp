// Projekt winda.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Projekt winda.h"
#include <deque>

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

#define TM_1 30
#define TM_2 31

struct ORDER
{
	int to;
	int where;
	int direction;
	bool b_to;
	bool b_where;
};

std::deque <ORDER> Order;

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
HWND Floor_4_Passengrs;
HWND Floor_3_Passengrs;
HWND Floor_2_Passengrs;
HWND Floor_1_Passengrs;
HWND Floor_0_Passengrs;

int TIME_1 = 0;
int TIME_2 = 0;

const int margin = 6;

#pragma region MainWindowDivision

const int Mainrect_x = 200;
const int Mainrect_y = 0;
const int Mainrect_height = 700;
const int Mainrect_width = 700;

const int Floor_height = 130;
const int Floor_width = 300;

const int Elevator_height = 665;
const int Elevator_width = 200;

const int Exit_height = Floor_height;
const int Exit_width = 170;

RECT MAINRECT = { Mainrect_x, Mainrect_y, Mainrect_x + Mainrect_width, Mainrect_y + Mainrect_height };

RECT FLOOR_4 = { Mainrect_x, Mainrect_y + Floor_height *0, Mainrect_x + Floor_width, Mainrect_y + Floor_height *1 };
RECT FLOOR_3 = { Mainrect_x, Mainrect_y + Floor_height *1, Mainrect_x + Floor_width, Mainrect_y + Floor_height *2 };
RECT FLOOR_2 = { Mainrect_x, Mainrect_y + Floor_height *2, Mainrect_x + Floor_width, Mainrect_y + Floor_height *3 };
RECT FLOOR_1 = { Mainrect_x, Mainrect_y + Floor_height *3, Mainrect_x + Floor_width, Mainrect_y + Floor_height *4 };
RECT FLOOR_0 = { Mainrect_x, Mainrect_y + Floor_height *4, Mainrect_x + Floor_width, Mainrect_y + Floor_height *5 };

RECT ELEVATOR = {	Mainrect_x + Floor_width, 
					Mainrect_y + margin + 1, 
					Mainrect_x + Floor_width + Elevator_width,
					Mainrect_y + Elevator_height - 1};

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

void Load(int to, int where, int dir, bool b_to, bool b_where)
{
	ORDER buffor_load;
	buffor_load.to = to;
	buffor_load.where = where;
	buffor_load.direction = dir;
	buffor_load.b_to = b_to;
	buffor_load.b_where = b_where;
	Order.push_back(buffor_load);
}

//void Algorithm(int current_pos, int distance, int direction, int start, int element)
//{
//	ORDER buffor_check;
//	bool good_dir = false;
//	bool algorithm = false;
//	int up = -1;
//	int down = 1;
//	int size = Order.size();
//	std::deque<ORDER>::iterator it = Order.begin();					// iterator, to insert data in the middle of deque
//	it += element;
//
//	if (Order.empty())								// condition 1
//	{
//		Order.push_back(Load(current_pos, distance, start, direction));
//	}
//	// cond 1: check if it can be simply put in the back
//	// cond 2: check the opposit, obvious
//	// cond 3: check if directions of the orders are compatible
//	// cond 4: if so then check if elevator goes up
//	// cond 5: check which order is higher and which should be first
//	// cond 6: the opposite of cond 5
//	
//	else if(!Order.empty())														// condition 2
//	{
//		buffor_check = Order.at(element);
//		if (buffor_check.direction == direction)							// condition 3
//		{
//			if (direction == up)											// condition 4
//			{
//				if ((buffor_check.position > current_pos) && buffor_check.start - buffor_check.distance > start) // condition 5
//				{
//					if (element == 0)												// to avoid using insert when not necessary
//					{
//						Order.push_front(Load(current_pos, distance, start, direction));
//					}
//					else
//					{
//						Order.insert(it,Load(current_pos, distance, start, direction));
//					}
//				}
//				if ((buffor_check.position > current_pos) && buffor_check.start - buffor_check.distance < start) // condition 6
//				{
//					if (element == 0)												// to avoid using insert when not necessary
//					{
//						Order.push_front(Load(current_pos, distance, start, direction));
//					}
//					else
//					{
//						Order.insert(it, Load(current_pos, distance, start, direction));
//					}
//				}
//				if (buffor_check.position <= current_pos)					// condition 7
//				{
//					for (int i = element; i < size; i++)
//					{
//						buffor_check = Order.at(i);
//						if (buffor_check.direction == down)
//						{
//							good_dir = true;
//						}
//						if (buffor_check.direction == up && good_dir)
//						{
//							element = i;
//							algorithm = true;
//							break;
//						}
//					}
//					if (algorithm)
//					{
//						Algorithm(current_pos, distance, direction, start, element);  // condition 14
//					}
//					else
//					{
//						Order.push_back(Load(current_pos, distance, start, direction));
//					}
//				}
//			}
//			if (direction == down)
//			{
//				if ((buffor_check.position < current_pos) && buffor_check.start + buffor_check.distance < start);  // condition 9
//				{
//					if (element == 0)												// to avoid using insert when not necessary
//					{
//						Order.push_front(Load(current_pos, distance, start, direction));
//					}
//					else
//					{
//						Order.insert(it, Load(current_pos, distance, start, direction));
//					}
//				}
//				if ((buffor_check.position < current_pos) && buffor_check.start - buffor_check.distance > start) // condition 10
//				{
//					Order.insert(it, Load(current_pos, distance, start, direction));
//				}
//				if (buffor_check.position >= current_pos)					// condition 11
//				{
//					for (int i = element; i < size; i++)
//					{
//						buffor_check = Order.at(i);
//						if (buffor_check.direction == up)
//						{
//							good_dir = true;
//						}
//						if (buffor_check.direction == down && good_dir)
//						{
//							element = i;
//							algorithm = true;
//							break;
//						}
//					}
//					if (algorithm)
//					{
//						Algorithm(current_pos, distance, direction, start, element);  // condition 12
//					}
//					else
//					{
//						Order.push_back(Load(current_pos, distance, start, direction));
//					}
//				}
//			}
//		}
//		if (buffor_check.direction != direction)
//		{
//			for (int i = element; i < size; i++)
//			{
//				buffor_check = Order.at(i);
//				if (buffor_check.direction == direction)
//				{
//					element = i;
//					algorithm = true;
//					break;
//				}
//			}
//			if (algorithm)
//			{
//				Algorithm(current_pos, distance, direction, start, element);  // condition 13
//			}
//			else
//			{
//				Order.push_back(Load(current_pos, distance, start, direction));
//			}
//		}
//	}
//}


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
   int button_size = 30;

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      0, 0, Mainrect_width + 200, Mainrect_height+30, nullptr, nullptr, hInstance, nullptr);

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
static bool first_update = true;

Pen Red_Pen(Color(255, 0, 0), 3);
Pen Black_Pen(Color(255, 0, 0, 0), 2);
Pen Green_Pen(Color(0, 255, 0), 3);

int up = -1;
int down = 1;

static int to;
static int where;
static int direction;

static ORDER buffor;
static int size = 0;
static int target;
static int elev_direction = 0;
static int main_target;
static bool stop;
static bool done = true;
static bool waited = false;

static int current_position = Mainrect_y + Floor_height * 4 + 10;

//static bool next = true;
//static int distance = 0;
//static int direction = 0;
//static int start = Mainrect_y + Floor_height * 4 + 10;
//static int current_pos = Mainrect_y + Floor_height * 4 + 10;
//
//static int old_POSITION = current_pos;
//
//static ORDER buffor_check;
//static ORDER buffor_do;
//static bool up_or_down;
//static bool change = false;
//
//static int POSITION = current_pos;
//static int DISTANCE;
//static int DIRECTION;
//static int START;
//static ORDER BUFF;

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
#pragma region Idbuttons
			case ID_BUTTON_F0_1:
				to = Mainrect_y + Floor_height * 4 + 10;
				where = Mainrect_y + Floor_height * 3 + 10;
				direction = up;
				Load(to, where, direction,false,false);
				SetTimer(hWnd, TM_1, 25, NULL);
				break;
			case ID_BUTTON_F0_2:
				to = Mainrect_y + Floor_height * 4 + 10;
				where = Mainrect_y + Floor_height * 2 + 10;
				direction = up;
				Load(to, where, direction, false, false);
				SetTimer(hWnd, TM_1, 25, NULL);
				break;
			case ID_BUTTON_F0_3:
				to = Mainrect_y + Floor_height * 4 + 10;
				where = Mainrect_y + Floor_height * 1 + 10;
				direction = up;
				Load(to, where, direction, false, false);
				SetTimer(hWnd, TM_1, 25, NULL);
				break;
			case ID_BUTTON_F0_4:
				to = Mainrect_y + Floor_height * 4 + 10;
				where = Mainrect_y + Floor_height * 0 + 10;
				direction = up;
				Load(to, where, direction, false, false);
				SetTimer(hWnd, TM_1, 25, NULL);
				break;
			case ID_BUTTON_F1_0:
				to = Mainrect_y + Floor_height * 3 + 10;
				where = Mainrect_y + Floor_height * 4 + 10;
				direction = down;
				Load(to, where, direction, false, false);
				SetTimer(hWnd, TM_1, 25, NULL);
				break;
			case ID_BUTTON_F1_2:
				to = Mainrect_y + Floor_height * 3 + 10;
				where = Mainrect_y + Floor_height * 2 + 10;
				direction = up;
				Load(to, where, direction, false, false);
				SetTimer(hWnd, TM_1, 25, NULL);
				break;
			case ID_BUTTON_F1_3:
				to = Mainrect_y + Floor_height * 3 + 10;
				where = Mainrect_y + Floor_height * 1 + 10;
				direction = up;
				Load(to, where, direction, false, false);
				SetTimer(hWnd, TM_1, 25, NULL);
				break;
			case ID_BUTTON_F1_4:
				to = Mainrect_y + Floor_height * 3 + 10;
				where = Mainrect_y + Floor_height * 0 + 10;
				direction = up;
				Load(to, where, direction, false, false);
				SetTimer(hWnd, TM_1, 25, NULL);
				break;
			case ID_BUTTON_F2_0:
				to = Mainrect_y + Floor_height * 2 + 10;
				where = Mainrect_y + Floor_height * 4 + 10;
				direction = down;
				Load(to, where, direction, false, false);
				SetTimer(hWnd, TM_1, 25, NULL);
				break;
			case ID_BUTTON_F2_1:
				to = Mainrect_y + Floor_height * 2 + 10;
				where = Mainrect_y + Floor_height * 3 + 10;
				direction = down;
				Load(to, where, direction, false, false);
				SetTimer(hWnd, TM_1, 25, NULL);
				break;
			case ID_BUTTON_F2_3:
				to = Mainrect_y + Floor_height * 2 + 10;
				where = Mainrect_y + Floor_height * 1 + 10;
				direction = up;
				Load(to, where, direction, false, false);
				SetTimer(hWnd, TM_1, 25, NULL);
				break;
			case ID_BUTTON_F2_4:
				to = Mainrect_y + Floor_height * 2 + 10;
				where = Mainrect_y + Floor_height * 0 + 10;
				direction = up;
				Load(to, where, direction, false, false);
				SetTimer(hWnd, TM_1, 25, NULL);
				break;
			case ID_BUTTON_F3_0:
				to = Mainrect_y + Floor_height * 1 + 10;
				where = Mainrect_y + Floor_height * 4 + 10;
				direction = down;
				Load(to, where, direction, false, false);
				SetTimer(hWnd, TM_1, 25, NULL);
				break;
			case ID_BUTTON_F3_1:
				to = Mainrect_y + Floor_height * 1 + 10;
				where = Mainrect_y + Floor_height * 3 + 10;
				direction = down;
				Load(to, where, direction, false, false);
				SetTimer(hWnd, TM_1, 25, NULL);
				break;
			case ID_BUTTON_F3_2:
				to = Mainrect_y + Floor_height * 1 + 10;
				where = Mainrect_y + Floor_height * 2 + 10;
				direction = down;
				Load(to, where, direction, false, false);
				SetTimer(hWnd, TM_1, 25, NULL);
				break;
			case ID_BUTTON_F3_4:
				to = Mainrect_y + Floor_height * 1 + 10;
				where = Mainrect_y + Floor_height * 0 + 10;
				direction = up;
				Load(to, where, direction, false, false);
				SetTimer(hWnd, TM_1, 25, NULL);
				break;
			case ID_BUTTON_F4_0:
				to = Mainrect_y + Floor_height * 0 + 10;
				where = Mainrect_y + Floor_height * 4 + 10;
				direction = down;
				Load(to, where, direction, false, false);
				SetTimer(hWnd, TM_1, 25, NULL);
				break;
			case ID_BUTTON_F4_1:
				to = Mainrect_y + Floor_height * 0 + 10;
				where = Mainrect_y + Floor_height * 3 + 10;
				direction = down;
				Load(to, where, direction, false, false);
				SetTimer(hWnd, TM_1, 25, NULL);
				break;
			case ID_BUTTON_F4_2:
				to = Mainrect_y + Floor_height * 0 + 10;
				where = Mainrect_y + Floor_height * 2 + 10;
				direction = down;
				Load(to, where, direction, false, false);
				SetTimer(hWnd, TM_1, 25, NULL);
				break;
			case ID_BUTTON_F4_3:
				to = Mainrect_y + Floor_height * 0 + 10;
				where = Mainrect_y + Floor_height * 1 + 10;
				direction = down;
				Load(to, where, direction, false, false);
				SetTimer(hWnd, TM_1, 25, NULL);
				break;
#pragma endregion
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {		
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
			Graphics graphics(hdc);
#pragma region Frame 
			
			// left wall of a shaft
			graphics.DrawLine(	&Black_Pen,
								Mainrect_x + Floor_width, 
								Mainrect_y + margin,
								Mainrect_x + Floor_width,
								Mainrect_y + Elevator_height);

			// right wall of a shaft
			graphics.DrawLine(	&Black_Pen,
								Mainrect_x + Floor_width + Elevator_width,
								Mainrect_y + margin, 
								Mainrect_x + Floor_width + Elevator_width, 
								Mainrect_y + Elevator_height);

			// floors
			for (int i = 1; i <= 5; i++) 
			{
				graphics.DrawLine(	&Black_Pen,
									Mainrect_x,
									Mainrect_y + Floor_height * i,
									Mainrect_x + Floor_width,
									Mainrect_y + Floor_height * i);
			}

			// exits
			for (int i = 1; i <= 5; i++)
			{
				graphics.DrawLine(	&Black_Pen,
									Mainrect_x + Floor_width + Elevator_width,
									Mainrect_y + Floor_height * i,
									Mainrect_x + Floor_width + Elevator_width + Exit_width,
									Mainrect_y + Floor_height * i);
			}

			// roof of a shaft
			graphics.DrawLine(	&Black_Pen,
								Mainrect_x + Floor_width,
								Mainrect_y + margin,
								Mainrect_x + Floor_width + Elevator_width,
								Mainrect_y + margin);

			// bottom of a shaft
			graphics.DrawLine(	&Black_Pen,
								Mainrect_x + Floor_width,
								Mainrect_y + Elevator_height,
								Mainrect_x + Floor_width + Elevator_width,
								Mainrect_y + Elevator_height);
#pragma endregion
			if (!Order.empty())
			{
				if (size < Order.size() && done || waited)
				{
					if (waited && current_position == main_target || Order.size() == 1)
					{
						size = Order.size();
						if (elev_direction != 0)
						{
							for (int i = 0; i < size; i++)
							{
								buffor = Order.at(i);
								buffor.b_to ? target = buffor.where : target = buffor.to;
								elev_direction == up
									?
								(target < current_position ? main_target = target : target = target)
									:
								(target > current_position ? main_target = target : target = target);
							}
						}
						else
						{
							buffor = Order.front();
							main_target = buffor.to;
							main_target < current_position ? elev_direction = up : elev_direction = down;
						}
					}
				}

				if (current_position != main_target && !stop)
				{
					waited = false;

						graphics.DrawRectangle(&Red_Pen,
							Mainrect_x + Floor_width + 10,
							current_position,
							Elevator_width - 4 * 5,
							Floor_height - 11);

						current_position += 2 * elev_direction;

					if (current_position % Floor_height == Mainrect_y + 10 && current_position != main_target)
					{
						for (int i = 0; i < size; i++)
						{
							buffor = Order.at(i);
							if (buffor.to == current_position && buffor.b_to == false && buffor.direction == elev_direction)
							{
								stop = true;
								buffor.b_to = true;
								Order.at(i) = buffor;
							}
							if (buffor.where == current_position && buffor.b_to == true)
							{
								stop = true;
								buffor.b_where = true;
								Order.at(i) = buffor;
							}
						}
					}
				}
				if (current_position == main_target && !stop && !waited)
				{
					elev_direction == up ? elev_direction = down : elev_direction = up;
					stop = true;
				}
				if (stop)
				{
					KillTimer(hWnd, TM_1);
					TIME_1 = 0;
					SetTimer(hWnd, TM_2, 25, NULL);

					graphics.DrawRectangle(&Green_Pen,
						Mainrect_x + Floor_width + 10,
						current_position,
						Elevator_width - 4 * 5,
						Floor_height - 11);

					if (TIME_2 > 10)
					{
						if (current_position == main_target)
						{
							buffor = Order.front();
							buffor.b_to ? buffor.b_where = true : buffor.b_to = true;
							Order.front() = buffor;
							for (int i = 0; i < size; i++)
							{
								buffor = Order.at(i);
								if (buffor.b_to && buffor.b_where)
								{
									Order.erase(Order.begin() + i);
									i--;
									size--;
								}
							}
							size = Order.size();
						//	if (!Order.size())
						//	{
						//		for (int i = 0; i < size; i++)
						//		{
						//			buffor = Order.at(i);
						//			buffor.b_to ? target = buffor.where : target = buffor.to;
						//			elev_direction == up													// wow
						//				?																	//
						//			(target < main_target ? main_target = target : target = target)			//
						//				:																	//
						//			(target > main_target ? main_target = target : target = target);		//
						//		}
						//	}
						//	else if(current_position != Mainrect_y + Floor_height * 4 + 10)
						//	{
						//		done = false;

						//		graphics.DrawRectangle(&Red_Pen,
						//			Mainrect_x + Floor_width + 10,
						//			current_position,
						//			Elevator_width - 4 * 5,
						//			Floor_height - 11);

						//		if (TIME_2 > 10)
						//		{
						//			done = false;
						//			Order.empty();
						//			Load(current_position, Mainrect_y + Floor_height * 4 + 10, down, true, false);
						//		}
						//	}							
						}
						if (done)
						{
							KillTimer(hWnd, TM_2);
							TIME_2 = 0;
							waited = true;
							SetTimer(hWnd, TM_1, 25, NULL);
							stop = false;
						}
					}
				}
			}
			else
			{
				graphics.DrawRectangle(&Red_Pen,
					Mainrect_x + Floor_width + 10,
					current_position,
					Elevator_width - 4 * 5,
					Floor_height - 11);

				elev_direction = 0;
			}
			//if (!Order.empty() && next)
			//{
			//	BUFF = Order.front();
			//	DIRECTION = BUFF.direction;
			//	START = BUFF.start;
			//	DISTANCE = BUFF.distance;
			//	POSITION = BUFF.position;

			//	if (old_POSITION < START)
			//	{
			//		up_or_down = false;
			//		graphics.DrawRectangle(&Red_Pen,
			//			Mainrect_x + Floor_width + 10,
			//			old_POSITION,
			//			Elevator_width - 4 * 5,
			//			Floor_height - 11);

			//		old_POSITION = old_POSITION + 2;
			//	}
			//	else if (old_POSITION > START)
			//	{
			//		up_or_down = true;
			//		graphics.DrawRectangle(&Red_Pen,
			//			Mainrect_x + Floor_width + 10,
			//			old_POSITION,
			//			Elevator_width - 4 * 5,
			//			Floor_height - 11);

			//		old_POSITION = old_POSITION - 2;
			//	}

			//	if (old_POSITION == START)
			//	{
			//		if (Order.size() >= 2)
			//		{
			//			buffor_check = Order.at(1);
			//			if (up_or_down)
			//			{
			//				if (buffor_check.start < START)
			//				{
			//					Order.push_front(buffor_check);
			//					Order.erase(Order.begin() + 2);
			//					change = true;
			//				}
			//			}
			//			else
			//			{
			//				if (buffor_check.start > START)
			//				{
			//					Order.push_front(buffor_check);
			//					Order.erase(Order.begin() + 2);
			//					change = true;
			//				}
			//			}
			//		}
			//		if (change)
			//		{
			//			change = false;
			//		}
			//		else
			//		{
			//			next = false;
			//			old_POSITION = POSITION + DISTANCE*DIRECTION;
			//		}
			//		Sleep(3000);
			//	}
			//}
			//else if (!(POSITION == START + DISTANCE*DIRECTION))
			//{
			//	//KillTimer(hWnd, TM_2);
			//	//TIME_2 = 0;
			//	graphics.DrawRectangle(&Red_Pen,
			//		Mainrect_x + Floor_width + 10,
			//		POSITION,
			//		Elevator_width - 4 * 5,
			//		Floor_height - 11);
			//		POSITION = POSITION + (2*DIRECTION);
			//		BUFF.position = POSITION;
			//		if (!Order.empty()) Order.front() = BUFF;
			//}
			//else if(POSITION == START + DISTANCE*DIRECTION /*&& TIME_2 < 5*/)
			//{
			//	//KillTimer(hWnd, TM_1);
			//	//SetTimer(hWnd, TM_2, 1000, NULL);
			//	graphics.DrawRectangle(&Green_Pen,
			//		Mainrect_x + Floor_width + 10,
			//		POSITION,
			//		Elevator_width - 4 * 5,
			//		Floor_height - 11);
			//	if (!Order.empty())
			//	{
			//		Sleep(3000);
			//		Order.pop_front();
			//		next = true;
			//	}
			//}

			

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
			/*MoveToEx(hdc, Mainrect_x + Floor_width, Mainrect_y, NULL);
			LineTo(hdc, Mainrect_x + Floor_width, Mainrect_y + Elevator_height);
			MoveToEx(hdc, Mainrect_x + Floor_width + Elevator_width, Mainrect_y, NULL);
			LineTo(hdc, Mainrect_x + Floor_width + Elevator_width, Mainrect_y + Elevator_height);*/
			//FillRect(hdc, &ELEVATOR, (HBRUSH)(COLOR_WINDOW + 14));

			if (first_update)
			{
				InvalidateRect(hWnd, &MAINRECT, TRUE);
				//SetTimer(hWnd,TM_1, 25, NULL);
				first_update = false;
			}

            EndPaint(hWnd, &ps);
        }
        break;
	case WM_TIMER:
		switch(wParam)
			{
			case TM_1:
				InvalidateRect(hWnd, &ELEVATOR, TRUE);
				TIME_1++;
				break;
			case TM_2:
				InvalidateRect(hWnd, &ELEVATOR, TRUE);
				TIME_2++;
				break;
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
