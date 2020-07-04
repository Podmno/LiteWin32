#include "LiteString.h"

LiteString::LiteString()
{

	head = new lite_word;
	head->next = nullptr;
	length  = 0;

}

LiteString::LiteString(const char* data)
{

	head = new lite_word;
	head->next = nullptr;
	length = 0;

	lite_word* cur = head;


	int i = 0;

	while (data[i]!=0)
	{
		cur->letter = data[i];
		cur->next = new lite_word;

		cur = cur->next;

	}





}

LiteString::~LiteString()
{

	lite_word* cur = head;
	lite_word* temp = cur;

	while (cur!=nullptr) {

		temp = cur->next;
		delete cur;
		cur = temp;


	}


}