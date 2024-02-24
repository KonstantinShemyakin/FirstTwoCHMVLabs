#pragma once
#include "framework.h"

class BaseWindow
{
private:
	WNDCLASS wd; // Window class
	HWND hWnd; // Window descriptor
public:
	BaseWindow();

	BaseWindow(HINSTANCE instance, 
		WNDPROC WndProc, 
		HCURSOR cursor		= LoadCursor(NULL, IDC_ARROW),
		HICON icon			= LoadIcon(NULL, IDI_APPLICATION),
		HBRUSH background	= (HBRUSH)(COLOR_WINDOW + 1),
		LPCWSTR class_name	= _T("MainWindow"),
		LPCWSTR menu_name	= NULL,
		UINT style			= CS_HREDRAW | CS_VREDRAW,
		int cbClsExtra		= 0,
		int cbWndExtra		= 0
		);

	void configure(HINSTANCE instance,
		WNDPROC WndProc,
		HCURSOR cursor = LoadCursor(NULL, IDC_ARROW),
		HICON icon = LoadIcon(NULL, IDI_APPLICATION),
		HBRUSH background = (HBRUSH)(COLOR_WINDOW + 1),
		LPCWSTR class_name = _T("MainWindow"),
		LPCWSTR menu_name = NULL,
		UINT style = CS_HREDRAW | CS_VREDRAW,
		int cbClsExtra = 0,
		int cbWndExtra = 0
	);

	bool registerWindow();

	HWND create(LPCWSTR title,
		HINSTANCE app,
		int mode,
		DWORD style = WS_OVERLAPPEDWINDOW,
		int width = CW_USEDEFAULT,
		int height = CW_USEDEFAULT,
		int x = CW_USEDEFAULT,
		int y = CW_USEDEFAULT,
		HMENU menu = NULL,
		HWND parent = HWND_DESKTOP,
		LPVOID param = NULL
		);

	void setCursor(HCURSOR new_cursor);

	inline HWND getDescriptor() { return hWnd; }

	inline WNDCLASS getClass() { return wd; }
};

