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


void LiteBase::translate_int(int number,char * & data)
{





}