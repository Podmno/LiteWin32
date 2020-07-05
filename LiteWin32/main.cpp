#include "LiteWindow.h"
#include "LiteEngine.h"
#include "TextReader.h"

static LPWSTR out_listdata[2][300];
static int page = 1;

LRESULT CALLBACK WindowProc(

	HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam

)
{
	LiteBase bs;
	LiteEngine* tx = new LiteEngine;
	
	
	
	char* data = NULL;
	

	switch (uMsg)
	{

	case WM_CREATE:
	{

		tx->add_button(hwnd, lParam, "分析", 390, 10, 50, 50, 100);

		tx->add_button(hwnd, lParam, "记事本", 320, 10, 50, 50, 300);




		return 0;
	}
	

	case WM_DESTROY:
	{

		::PostQuitMessage(0);

		return 0;
	}

	case WM_COMMAND:
	{

		switch (LOWORD(wParam)) {

		case 100:
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
				LPWSTR str = openFileName.lpstrFile;
				tx->paint_engine(hwnd, "选择了文件：", 10, 65);
				tx->paint_engine(hwnd, str, 10, 80);

				TextReader* tr = new TextReader(str);

				tr->start();
				wordslist* current = tr->list_head->next;
				char* temp = new char[200];
				int i = 0;

				while (current != NULL) {
					for (int m = 0; m < 200; m++) {
						temp[m] = 0;
					}


					if (current->length > 0) {
						int k = 0;
						for (; k < current->length; k++) {
							temp[k] = current->letter[k];
						}
						temp[k + 1] = 0;
						USES_CONVERSION;
						LPWSTR string = A2W(temp);
						out_listdata[0][i] = string;

						int value = current->number;
						wchar_t* chardata = new wchar_t[10];
						_itow_s(value, chardata, 10, 10);

						out_listdata[1][i] = chardata;


						i++;

					}

					current = current->next;
				}

			}


			break;
		}



		case 300:
		{
			system("notepad");
			break;
		}

		

		}
	}


		case WM_PAINT:
		{

			tx->paint_engine(hwnd, "EngHex 英语作文分析工具", 10, 25);
			

			for (int k = 0; k < 70; k++) {


				tx->paint_engine(hwnd, out_listdata[0][4 * k], 5, 20 * (k + 5));
				tx->paint_engine(hwnd, out_listdata[1][4 * k], 105, 20 * (k + 5));
				tx->paint_engine(hwnd, out_listdata[0][4 * k+1], 150, 20 * (k + 5));
				tx->paint_engine(hwnd, out_listdata[1][4 * k+1], 250, 20 * (k + 5));
				tx->paint_engine(hwnd, out_listdata[0][4 * k+2], 295, 20 * (k + 5));
				tx->paint_engine(hwnd, out_listdata[1][4 * k+2], 395, 20 * (k + 5));
				tx->paint_engine(hwnd, out_listdata[0][4 * k+3], 440, 20 * (k + 5));
				tx->paint_engine(hwnd, out_listdata[1][4 * k+3], 540, 20 * (k + 5));

			}
			break;
		

		}





	
	}
	
	
	return ::DefWindowProc(hwnd, uMsg, wParam, lParam);


}



int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow

)
{
	LiteWindow wnd;
	
	wnd.setSize(500, 500);

	wnd.setTitle("EngHex");

	wnd.CreateLiteWindow(hInstance,"EngHex",WindowProc);
	
	wnd.showWindow();
	wnd.runMessage();
	return 0;


}