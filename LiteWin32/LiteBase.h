#pragma once
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <atlstr.h>


class LiteBase
{
public:
	LiteBase();
	virtual ~LiteBase();

	LPCWSTR translate_char(const char* data);

};

