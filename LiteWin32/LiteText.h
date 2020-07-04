#pragma once
#include "LiteBase.h"

/*

	LiteText.h
	Text print function.

	Version 1.0.0 Copyright @ Studio TRI 2020



*/

class LiteText : public LiteBase
{
public:
	LiteText();
	~LiteText();
	
	void paint_engine(HWND,const char *,int,int,int);


	HDC hdc;
	PAINTSTRUCT ps;

};

