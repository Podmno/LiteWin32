#pragma once

/*

	LiteString.h
	Simple text operator. 

	Version 0.0.1 Copyright @ Studio TRI 2020




*/

struct lite_word {

	char letter;
	lite_word* next;


};

class LiteString
{

public:
	LiteString();
	LiteString(const char*);
	LiteString(LiteString&);
	
	virtual ~LiteString();
private:
	lite_word* head;
	int length;
public:
	void parseInt(int&);

};

