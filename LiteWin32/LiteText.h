#pragma once
#include "LiteBase.h"

class LiteText : public LiteBase
{
public:
	LiteText();
	~LiteText();
	
	void paint_engine(HWND,const char *,int,int,int);


	HDC hdc;
	PAINTSTRUCT ps;

};

