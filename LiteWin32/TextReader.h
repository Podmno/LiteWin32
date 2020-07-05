#pragma once
#include <windows.h>

/*

    EngFlex Core Engine
    Version 2.0


*/


#include <iostream>
#include <fstream>

struct words{

    char letter[100];
    int length;

    words* next;

};

struct wordslist{

    char letter[100];
    int length;
    unsigned int number;

    wordslist* next;

};

class TextReader{

public:

    TextReader();
    TextReader(LPWSTR);
    ~TextReader();

    void start();

    //void article_fix();

    LPWSTR getInfo(int);

    void read_function();
    void print_function();
    void read_all();
    void print_all();

    int list_length;

    LPWSTR location;

    std::ifstream* file;

    words* head;

    wordslist* list_head;

  

};