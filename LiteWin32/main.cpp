#include "LiteWindow.h"
#include "LiteText.h"

/*

	LiteWindow 提供的默认 main 函数模板：
	上方为回调函数，下方为窗口创建/注册函数。

	若要修订窗口的详细信息，请在 CreateWindow 函数前使用 LiteWindow 提供的函数
	进行参数修改。



*/


LRESULT CALLBACK WindowProc(

	HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam


)
{

	LiteText tx;

	switch (uMsg) 
	{

	case WM_DESTROY:
		::PostQuitMessage(0);
		return 0;

	case WM_PAINT:
		tx.paint_engine(hwnd,"HELLO WORLD",0,0,11);
		


	}
	return ::DefWindowProc(hwnd, uMsg, wParam, lParam);
	


}

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow

)
{
	LiteWindow wnd;
	wnd.setSize(500, 500);
	
	wnd.CreateLiteWindow(hInstance,"LiteWindow Test",WindowProc);
	
	wnd.showWindow();
	wnd.runMessage();
	return 0;


}