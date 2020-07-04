#include "LiteWindow.h"
#include "LiteEngine.h"




LRESULT CALLBACK WindowProc(

	HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam


)
{

	LiteEngine tx;
	

	switch (uMsg) 
	{

	case WM_CREATE:
		tx.add_button(hwnd,lParam,"����",390,10,50,50,100); 
		tx.add_button(hwnd, lParam, "�ļ�", 320, 10, 50, 50, 200);
		tx.add_button(hwnd, lParam, "���±�", 250, 10, 50, 50, 300);
		return 0;
	case WM_DESTROY:
		::PostQuitMessage(0);
		return 0;

	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case 100:
			MessageBox(hwnd,TEXT("����˷�����ť"),TEXT("Title1"),0);
			break;
		case 200:
			MessageBox(hwnd, TEXT("������ļ���ť"), TEXT("Title1"), 0);
			break;
		case 300:
			system("notepad");
			break;
		}
		

	case WM_PAINT:
		tx.paint_engine(hwnd,"EngHex Ӣ�����ķ�������",10,20);
		return 0;
	


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
	wnd.setTitle("EngHex");
	wnd.CreateLiteWindow(hInstance,"EngHex",WindowProc);
	
	wnd.showWindow();
	wnd.runMessage();
	return 0;


}