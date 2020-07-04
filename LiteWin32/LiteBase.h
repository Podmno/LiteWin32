#pragma once
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <atlstr.h>


/*

	LiteBase.h
	Provided common-used function in Win32 API Development.

	Version 1.0.0 Copyright @ Studio TRI 2020



*/


class LiteBase
{
public:
	LiteBase();
	virtual ~LiteBase();

	LPCWSTR translate_char(const char* data);

	void translate_int();

};

