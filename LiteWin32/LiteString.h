#pragma once

/*

	LiteString.h
	Simple text operator. 

	Version 0.0.1 Copyright @ Studio TRI 2020




*/

#include <stdio.h>

struct string_node {

    char data;

    string_node* next;


};


class LiteString {

public:

    LiteString();
    LiteString(const char*);
    LiteString(LiteString&);

    bool equal(LiteString&);
    void parseInt(int&);
    void parseChar(char*&);

    void add(LiteString&);

    bool letterDecide(char);
    bool letterDecide(char, int);

    ~LiteString();

private:

    string_node* head;
    unsigned int length;


};