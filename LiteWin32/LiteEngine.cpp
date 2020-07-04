#include "LiteEngine.h"



LiteEngine::LiteEngine()
{




}

void LiteEngine::paint_engine(HWND hwnd,const char* data, int x, int y)
{

	LPCWSTR text = LiteBase::translate_char(data);
	int i = CString(text).GetLength();
	hdc = BeginPaint(hwnd,&ps);
	TextOut(hdc,x,y,text, i);
	EndPaint(hwnd,&ps);

}

void LiteEngine::add_button(HWND hwnd, LPARAM lParam, const char* title, int x, int y, int length, int height, int id)
{

	CreateWindow(TEXT("button"), LiteBase::translate_char(title), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, x, y, length, height, hwnd, (HMENU)id, ((LPCREATESTRUCT)lParam)->hInstance, NULL);


}

LiteEngine::~LiteEngine()
{




}