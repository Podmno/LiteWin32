#include "LiteText.h"



LiteText::LiteText()
{




}

void LiteText::paint_engine(HWND hwnd,const char* data, int x, int y, int size)
{

	hdc = GetDC(hwnd);
	TextOut(hdc,x,y,LiteBase::translate_char(data), size);
	ReleaseDC(hwnd,hdc);


}

LiteText::~LiteText()
{




}