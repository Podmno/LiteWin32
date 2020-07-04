#pragma once

/*

	LiteWindow.h
	Core Engine which provides GUI for users.

	Version 1.0.1 Copyright @ Studio TRI 2020

	Quick Guide:
	Using #include "litewindow.h" in main.cpp.
	The simplest template are provided.

	Update Log:
	
	| Version 1.0.0 | First Engine which can create HELLOWORLD application.
	| Version 1.0.1 | Add Textout support.


//////////////////////////////////////////////////////////  main.cpp  //////////////////////////////////////////////////////////
	
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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


*/

#include "LiteBase.h"

class LiteWindow : public LiteBase

{
public:

	LiteWindow();
	HWND CreateLiteWindow(HINSTANCE,const char*,WNDPROC);
	void setTitle(const char*);
	void setStyle(DWORD);
	void setCursor(HCURSOR);
	void setMenu(HMENU hmenu);
	void setFullScreen(bool b);
	void setBound(int x,int y,int width,int height);
	void setSize(int width, int hight);
	void setBackGroundColor(DWORD bgc);
	void showWindow();
	int runMessage();


	virtual ~LiteWindow();

	LPCWSTR translate_char(const char*);

protected:
	HWND hwnd;
	WNDCLASS wndclass;
	DWORD style;
	HICON hIcon;
	HMENU hMenu;
	HCURSOR hCursor;

	int whether_fullScreen;
	int width;
	int height;
	int location_X;
	int location_Y;
	bool whether_active;
	char* title;
	DWORD backGroundColor;


public:



};

