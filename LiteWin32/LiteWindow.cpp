#include "LiteWindow.h"

LiteWindow::LiteWindow()
{

	title = (char*)"LiteWindow Application";
	backGroundColor = WHITE_BRUSH;
	hCursor = ::LoadCursor(0,IDC_ARROW);
	hIcon = ::LoadIcon(0,IDI_APPLICATION);
	style = WS_OVERLAPPEDWINDOW;
	location_X = 0;
	location_Y = 0;
	width = 800;
	height = 600;


}

LiteWindow::~LiteWindow() 
{


}



HWND LiteWindow::CreateLiteWindow(HINSTANCE hInstance,const char* winName,WNDPROC winProc)
{

	wndclass.lpszClassName = LiteBase::translate_char(winName);
	wndclass.hInstance = hInstance;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hCursor = hCursor;
	wndclass.hIcon = hIcon;
	wndclass.lpfnWndProc = winProc;
	wndclass.lpszMenuName = 0;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.style = CS_VREDRAW | CS_HREDRAW;
	
	if (!::RegisterClass(&wndclass)) {
		MessageBox(0,TEXT("内部窗口创建时出现错误。"),TEXT("LiteWindow 内部错误 1"),0);
	}

	hwnd = ::CreateWindow(
			LiteBase::translate_char(winName),
			LiteBase::translate_char(title),
			WS_OVERLAPPEDWINDOW | WS_VSCROLL,
			location_X,
			location_Y,
			width,
			height,
			0,
			0,
			hInstance,
			0);


	return hwnd;

}

void LiteWindow::showWindow()
{

	if (!hwnd) {

		MessageBox(0,TEXT("LiteWindow 无法提供窗口以供显示。"),TEXT("LiteWindow 内部错误 2"),0);

	}

	::ShowWindow(hwnd,SW_SHOW);


}

int LiteWindow::runMessage()
{

	MSG msg;

	while (::GetMessage(&msg,0,0,0)) 
	{
		::TranslateMessage(&msg);
		::DispatchMessage(&msg);
	}

	return (int)msg.wParam;

}

void LiteWindow::setTitle(const char* data)
{

	title = (char*)data;


}

void LiteWindow::setStyle(DWORD input_style)
{

	style = input_style;


}

void LiteWindow::setCursor(HCURSOR input_hCursor)
{

	hCursor = input_hCursor;

}

void LiteWindow::setMenu(HMENU input_hMenu)
{

	hMenu = input_hMenu;

}

void LiteWindow::setFullScreen(bool b)
{



}

void LiteWindow::setBound(int input_x, int input_y, int input_width, int input_height)
{

	location_X = input_x;
	location_Y = input_y;


	width = input_width;
	height = input_height;

}

void LiteWindow::setSize(int input_width, int input_height)
{

	width = input_width;
	height = input_height;

}


void LiteWindow::setBackGroundColor(DWORD input_bgc)
{

	backGroundColor = input_bgc;

}

