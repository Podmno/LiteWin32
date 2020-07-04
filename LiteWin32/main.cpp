#include "LiteWindow.h"
#include "LiteText.h"

/*

	LiteWindow �ṩ��Ĭ�� main ����ģ�壺
	�Ϸ�Ϊ�ص��������·�Ϊ���ڴ���/ע�ắ����

	��Ҫ�޶����ڵ���ϸ��Ϣ������ CreateWindow ����ǰʹ�� LiteWindow �ṩ�ĺ���
	���в����޸ġ�



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