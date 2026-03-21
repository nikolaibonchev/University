// Win32APIwindows.cpp : Defines the entry point for the application.
//


#include "stdafx.h"

#include "Win32APIwindows.h"


// Global Variables

HINSTANCE			hInst ;										// current instance
TCHAR				szTitle[] = _T("Win32APIwindows") ;			// The title bar text
TCHAR				szWindowClass[] = _T("WIN32APIWINDOWS") ;	// the main window class name
TCHAR				szChildWindowClass[] = _T("CHILDWINDOW");


// Forward declarations of functions included in this code module

ATOM				MyRegisterClass ( HINSTANCE ) ;
BOOL				InitInstance ( HINSTANCE , int ) ;
LRESULT	CALLBACK	WndProc ( HWND , UINT , WPARAM , LPARAM ) ;
INT_PTR	CALLBACK	About ( HWND , UINT , WPARAM , LPARAM ) ;
LRESULT CALLBACK	ChildWndProc(HWND, UINT, WPARAM, LPARAM);

//
//  FUNCTION: _tWinMain
//
//  PURPOSE: Program entry point.
//

int	APIENTRY		_tWinMain
(
_In_     HINSTANCE			hInstance ,
_In_opt_ HINSTANCE			hPrevInstance ,
_In_     LPTSTR				lpCmdLine ,
_In_     int				nCmdShow
)
{
MSG					msg ;

	// Initialize global strings

	MyRegisterClass(hInstance) ;

	// Perform application initialization

	if ( ! InitInstance(hInstance,nCmdShow) )
		return FALSE ;

	// Main message loop

	while ( GetMessage(&msg,NULL,0,0) )
	{
		TranslateMessage(&msg) ;
		DispatchMessage(&msg) ;
	}

	// The End

	return ( int ) msg.wParam ;
}


//
//  FUNCTION: MyRegisterClass
//
//  PURPOSE: Registers the window class.
//

ATOM				MyRegisterClass
(
HINSTANCE			hInstance
)
{
WNDCLASSEX			wcex ;

	wcex.cbSize = sizeof(WNDCLASSEX) ;

	wcex.style			= CS_HREDRAW | CS_VREDRAW ;
	wcex.lpfnWndProc	= WndProc ;
	wcex.cbClsExtra		= 0 ;
	wcex.cbWndExtra		= 0 ;
	wcex.hInstance		= hInstance ;
	wcex.hIcon			= LoadIcon(hInstance,MAKEINTRESOURCE(IDI_WIN32APIWINDOWS)) ;
	wcex.hCursor		= LoadCursor(NULL,IDC_ARROW) ;
	wcex.hbrBackground	= ( HBRUSH ) ( COLOR_WINDOW + 1 ) ;
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_WIN32APIWINDOWS) ;
	wcex.lpszClassName	= szWindowClass ;
	wcex.hIconSm		= LoadIcon(wcex.hInstance,MAKEINTRESOURCE(IDI_SMALL)) ;

	RegisterClassEx(&wcex);

	wcex.lpfnWndProc = ChildWndProc;
	wcex.lpszClassName = szChildWindowClass;


	return RegisterClassEx(&wcex) ;
}


//
//   FUNCTION: InitInstance
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS: In this function, we save the instance handle in a global variable and
//             create and display the main program window.
//

BOOL				InitInstance
(
HINSTANCE			hInstance ,
int					nCmdShow
)
{
HWND				hWnd ;
HWND				hWndChild;

	hInst = hInstance ; // Store instance handle in our global variable

	hWnd = CreateWindow(szWindowClass,szTitle,WS_OVERLAPPEDWINDOW,
						CW_USEDEFAULT,0,CW_USEDEFAULT,0,NULL,NULL,hInstance,NULL) ;


	if ( hWnd == NULL )
		return FALSE ;

	ShowWindow(hWnd,nCmdShow) ;
	UpdateWindow(hWnd) ;

	/*if (hWndChild == NULL)
		return FALSE;

	ShowWindow(hWndChild, nCmdShow);
	UpdateWindow(hWndChild);*/

	return TRUE ;
}


//
//  FUNCTION: WndProc
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//

LRESULT	CALLBACK	WndProc
(
HWND				hWnd ,
UINT				message ,
WPARAM				wParam ,
LPARAM				lParam
)
{
int					wmId , wmEvent ;
PAINTSTRUCT			ps ;
HDC					hdc ;
HDC					hdc2;

	TCHAR debugOutput[256];
	static int totalMsgCount = 0;
    static int mouseMoveCount = 0;
    static int leftMouseBtnClickCount = 0;
    static int rightMouseBtnClickCount = 0;
    static int middleMouseBtnClickCount = 0;
	static HWND hWndChild;

	totalMsgCount++;

	switch ( message )
	{
	case WM_CREATE:
		hWndChild = CreateWindow(
			szChildWindowClass,
			NULL,
			WS_CHILD | WS_VISIBLE | WS_BORDER,
			50, 50, 300, 200,
			hWnd,
			NULL,
			hInst,
			NULL
		);

		ShowWindow(hWndChild, SW_HIDE);

	case WM_MOUSEMOVE:
		mouseMoveCount++;
		break;
	case WM_LBUTTONDOWN:
		leftMouseBtnClickCount++;
		OutputDebugString(TEXT("Left mouse button was clicked!\n"));
		ShowWindow(hWndChild, SW_SHOW);
		break;
	case WM_RBUTTONDOWN:
		rightMouseBtnClickCount++;
		OutputDebugString(TEXT("Right mouse button was clicked!\n"));
		ShowWindow(hWndChild, SW_HIDE);
		break;
	case WM_MBUTTONDOWN:
		middleMouseBtnClickCount++;
		OutputDebugString(TEXT("Middle mouse button was clicked!\n"));
		break;
	case WM_COMMAND :
		wmId    = LOWORD(wParam) ;
		wmEvent = HIWORD(wParam) ;
		// Parse the menu selections
		switch ( wmId )
		{
		case IDM_ABOUT :
			DialogBox(hInst,MAKEINTRESOURCE(IDD_ABOUTBOX),hWnd,About) ;
			break ;
		case IDM_EXIT :
			DestroyWindow(hWnd) ;
			break ;
		default :
			return DefWindowProc(hWnd,message,wParam,lParam) ;
		}
		break ;

	case WM_PAINT :
		hdc = BeginPaint(hWnd,&ps) ;
		// Add any drawing code here
		EndPaint(hWnd,&ps) ;

		hdc2 = BeginPaint(hWndChild, &ps);
		EndPaint(hWndChild, &ps);

		break ;

	case WM_DESTROY :
		_stprintf_s(debugOutput, 256,
			TEXT("Total count: %d\n"),
			TEXT("Total Mouse movement count: %d\n"),
			TEXT("Total Left Mouse button clicks count: %d\n"),
			TEXT("Total Right Mouse button clicks count: %d\n"),
			TEXT("Total Middle Mouse button clicks count: %d\n"),
			totalMsgCount,
			mouseMoveCount,
			leftMouseBtnClickCount,
			rightMouseBtnClickCount,
			middleMouseBtnClickCount
		);
		PostQuitMessage(0) ;
		break ;

	default :
		return DefWindowProc(hWnd,message,wParam,lParam) ;
	}

	return 0 ;
}

LRESULT	CALLBACK	ChildWndProc
(
	HWND				hWnd,
	UINT				message,
	WPARAM				wParam,
	LPARAM				lParam
)
{
	int					wmId, wmEvent;
	PAINTSTRUCT			ps;
	HDC					hdc2;

	TCHAR debugOutput[256];
	static int totalMsgCount = 0;
	static int mouseMoveCount = 0;
	static int leftMouseBtnClickCount = 0;
	static int rightMouseBtnClickCount = 0;
	static int middleMouseBtnClickCount = 0;
	static HWND hWndChild;

	totalMsgCount++;

	switch (message)
	{
	case WM_MOUSEMOVE:
		mouseMoveCount++;
		break;
	case WM_LBUTTONDOWN:
		leftMouseBtnClickCount++;
		OutputDebugString(TEXT("Child's Left mouse button was clicked!\n"));
		break;
	case WM_RBUTTONDOWN:
		rightMouseBtnClickCount++;
		OutputDebugString(TEXT("Child's Right mouse button was clicked!\n"));
		break;
	case WM_MBUTTONDOWN:
		middleMouseBtnClickCount++;
		OutputDebugString(TEXT("Child's Middle mouse button was clicked!\n"));
		break;
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections
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
		break;

	case WM_PAINT:
		hdc2 = BeginPaint(hWndChild, &ps);
		EndPaint(hWndChild, &ps);

		break;

	case WM_DESTROY:
		_stprintf_s(debugOutput, 256,
			TEXT("Total count: %d\n"),
			TEXT("Total Mouse movement count: %d\n"),
			TEXT("Total Left Mouse button clicks count: %d\n"),
			TEXT("Total Right Mouse button clicks count: %d\n"),
			TEXT("Total Middle Mouse button clicks count: %d\n"),
			totalMsgCount,
			mouseMoveCount,
			leftMouseBtnClickCount,
			rightMouseBtnClickCount,
			middleMouseBtnClickCount
		);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}



//
//  FUNCTION: About
//
//  PURPOSE: Message handler for about box.
//

INT_PTR	CALLBACK	About
(
HWND				hDlg ,
UINT				message ,
WPARAM				wParam ,
LPARAM				lParam
)
{
	switch ( message )
	{
	case WM_INITDIALOG :
		return ( INT_PTR ) TRUE ;

	case WM_COMMAND :
		if ( LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL )
		{
			EndDialog(hDlg,LOWORD(wParam)) ;
			return ( INT_PTR ) TRUE ;
		}
		break ;
	}

	return ( INT_PTR ) FALSE ;
}


