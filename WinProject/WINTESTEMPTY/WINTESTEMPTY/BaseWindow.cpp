#include "BaseWindow.h"

BaseWindow::BaseWindow() 
{ 
	hWnd = NULL; 
	wd.hInstance = NULL;
	wd.lpfnWndProc = NULL;
	wd.lpszClassName = NULL;
	wd.hCursor = NULL;
	wd.hbrBackground = NULL;
	wd.lpszMenuName = NULL;
	wd.hIcon = NULL;
	wd.style = NULL;
	wd.cbClsExtra = 0;
	wd.cbWndExtra = 0;
	hWnd = NULL;
}

BaseWindow::BaseWindow(HINSTANCE instance,
	WNDPROC WndProc,
	HCURSOR cursor,
	HICON icon,
	HBRUSH background,
	LPCWSTR class_name,
	LPCWSTR menu_name,
	UINT style,
	int cbClsExtra,
	int cbWndExtra
) 
{
	wd.hInstance = instance;
	wd.lpfnWndProc = WndProc;
	wd.lpszClassName = class_name;
	wd.hCursor = cursor;
	wd.hbrBackground = background;
	wd.lpszMenuName = menu_name;
	wd.hIcon = icon;
	wd.style = style;
	wd.cbClsExtra = cbClsExtra;
	wd.cbWndExtra = cbWndExtra;
	hWnd = NULL;
}

void BaseWindow::configure(HINSTANCE instance,
	WNDPROC WndProc,
	HCURSOR cursor,
	HICON icon,
	HBRUSH background,
	LPCWSTR class_name,
	LPCWSTR menu_name,
	UINT style,
	int cbClsExtra,
	int cbWndExtra
)
{
	wd.hInstance = instance;
	wd.lpfnWndProc = WndProc;
	wd.lpszClassName = class_name;
	wd.hCursor = cursor;
	wd.hbrBackground = background;
	wd.lpszMenuName = menu_name;
	wd.hIcon = icon;
	wd.style = style;
	wd.cbClsExtra = cbClsExtra;
	wd.cbWndExtra = cbWndExtra;
}

bool BaseWindow::registerWindow() { return RegisterClass(&wd); }

HWND BaseWindow::create(LPCWSTR title,
	HINSTANCE app,
	int mode,
	DWORD style,
	int width,
	int height,
	int x,
	int y,
	HMENU menu,
	HWND parent,
	LPVOID param
)
{
	hWnd = CreateWindow(wd.lpszClassName,
		title,
		style,
		x, y,
		width, height,
		parent,
		menu,
		app,
		param);
	ShowWindow(hWnd, mode);
	UpdateWindow(hWnd);
	return hWnd;
}

void BaseWindow::setCursor(HCURSOR new_cursor) 
{ 
	wd.hCursor = new_cursor; 
	registerWindow();
}