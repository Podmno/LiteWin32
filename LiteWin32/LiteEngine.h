#pragma once
#include "LiteBase.h"

/*

	LiteEngine.h
	LiteWindow Widget provider.

	Version 1.1.0 Copyright @ Studio TRI 2020



*/



class LiteEngine : public LiteBase
{
public:
	LiteEngine();

	~LiteEngine();
	
	void paint_engine(HWND,const char *,int,int);
	void paint_engine(HWND, LPWSTR, int, int);

	void add_button(HWND,LPARAM,const char*,int,int,int,int,int);

	void open_file(LPWSTR&);


	LPWSTR location;

	HDC hdc;
	PAINTSTRUCT ps;

};

