#include "LiteBase.h"

LiteBase::LiteBase()
{



}


LiteBase::~LiteBase()
{



}

LPCWSTR LiteBase::translate_char(const char* data) {

	CString temp = data;
	LPCWSTR result = (LPCWSTR)(temp.AllocSysString());

	return result;


}