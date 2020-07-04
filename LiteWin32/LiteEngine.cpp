#include "LiteEngine.h"



LiteEngine::LiteEngine()
{




}

void LiteEngine::paint_engine(HWND hwnd,const char* data, int x, int y)
{

	LPCWSTR text = LiteBase::translate_char(data);

	int i = CString(text).GetLength();

	hdc = GetDC(hwnd);

	TextOut(hdc,x,y,text, i);

	ReleaseDC(hwnd,hdc);


}

void LiteEngine::add_button(HWND hwnd, 
	LPARAM lParam, 
	const char* title,
	int x, 
	int y,
	int length, 
	int height, 
	int id)

{

	CreateWindow(TEXT("button"), 
		LiteBase::translate_char(title),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 
		x, 
		y,
		length,
		height, 
		hwnd,
		(HMENU)id,
		((LPCREATESTRUCT)lParam)->hInstance, 
		NULL);


}

LPWSTR LiteEngine::open_file()
{


	TCHAR szFileName[MAX_PATH] = {};
	OPENFILENAMEW openFileName = {};


	openFileName.lStructSize = sizeof(OPENFILENAMEW);
	openFileName.nMaxFile = MAX_PATH;
	openFileName.lpstrFilter = TEXT("文本文件（*.txt*）\0*.txt\0任何文件（*.*）\0*.*\0");
	openFileName.lpstrFile = szFileName;
	openFileName.nFilterIndex = 1;
	openFileName.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;


	if (GetOpenFileName(&openFileName))
	{
		//MessageBox(nullptr, openFileName.lpstrFile, L"", MB_OK);
		return openFileName.lpstrFile;
		
	}

	return 0;

}

LiteEngine::~LiteEngine()
{




}