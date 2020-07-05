	#include "LiteWindow.h"
	LRESULT CALLBACK WindowProc(
	HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam
)
{
	switch (uMsg)
	{

	case WM_DESTROY:
		::PostQuitMessage(0);
		break;

	default:
		return ::DefWindowProc(hwnd, uMsg, wParam, lParam);


	}
	return 0;

}

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow

)
{
	LiteWindow wnd;

	wnd.CreateLiteWindow(hInstance,"LiteWindow Test",WindowProc);

	wnd.showWindow();
	wnd.runMessage();
	return 0;

}