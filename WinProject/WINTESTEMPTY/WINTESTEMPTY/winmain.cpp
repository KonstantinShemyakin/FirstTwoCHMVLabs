#include "framework.h"
#include "targetver.h"
#include "BaseWindow.h"
#include <xstring>
#include <string.h>

typedef std::basic_string<TCHAR, std::char_traits<TCHAR>, std::allocator<TCHAR>> String;

LRESULT CALLBACK MainProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

BaseWindow main_win;

int APIENTRY wWinMain(_In_ HINSTANCE App,
	_In_opt_ HINSTANCE Prev,
	_In_ LPWSTR    Cmd,
	_In_ int       Mode)
{
	MSG msg;
	main_win.configure(App, MainProc, LoadCursor(NULL, IDC_HAND), LoadIcon(NULL, IDI_HAND));

	if(!main_win.registerWindow()) return 0;

	main_win.create(_T("My first created window"), App, Mode);

	while (GetMessage(&msg, NULL/*main_win.getDescriptor()*/, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

LRESULT CALLBACK MainProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static String str;

	switch (message)
	{
	case WM_CHAR:
		str += (TCHAR)wParam;
		InvalidateRect(hWnd, NULL, TRUE);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		TextOut(hdc, 20, 20, str.data(), str.size());
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		main_win.setCursor(LoadCursor(NULL, IDC_HELP));
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}