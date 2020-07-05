#include "LiteString.h"
#include <math.h>

LiteString::LiteString()
{

    head = new string_node;
    head->next = NULL;
    head->data = 0;
    length = 0;


}


LiteString::LiteString(const char* data)
{

    head = new string_node;
    head->next = NULL;
    head->data = 0;
    length = 0;

    string_node* cur = head;
    int i = 0;

    while (data[i] != 0) {

        cur->data = data[i];


        cur->next = new string_node;
        cur = cur->next;

        i++;

    }

    cur->data = 0;
    cur->next = NULL;
    length = i;


}

LiteString::LiteString(LiteString& data)
{

    head = new string_node;
    head->next = NULL;
    head->data = 0;

    length = data.length;

    string_node* outdata = data.head;
    string_node* cur = head;

    for (int i = 0; i < data.length; i++) {

        cur->data = outdata->data;

        cur->next = new string_node;
        cur = cur->next;
        outdata = outdata->next;

    }

    cur->next = new string_node;
    cur = cur->next;
    cur->data = 0;
    cur->next = NULL;


}

LiteString::~LiteString()
{

    string_node* cur = head;
    string_node* temp = cur;

    while (cur != NULL) {

        temp = cur->next;

        delete cur;

        cur = temp;

    }


}

bool LiteString::equal(LiteString& data)
{

    string_node* out_cur = data.head;
    string_node* cur = head;

    if (data.length != length) {
        return false;
    }

    while (cur != NULL) {

        if (out_cur->data != cur->data) {
            return false;
        }

        out_cur = out_cur->next;
        cur = cur->next;

    }

    return true;


}

void LiteString::parseInt(int& num)
{

    // CheckFunction

    bool whether_convent = true;

    string_node* cur = head;
    int i = length;

    while (i > 0) {

        if (cur->data < 48 || cur->data>57) {
            whether_convent = false;
            break;
        }
        cur = cur->next;
        i--;

    }

    if (whether_convent == true) {

        cur = head;

        int output = 0;
        int lh = length - 1;
        while (lh >= 0) {

            int helper = pow(10, lh);
            output += helper * (cur->data - 48);

            cur = cur->next;
            lh--;

        }

        num = output;
    }


}

void LiteString::parseChar(char*& output)
{

    string_node* data = head;

    int i = 0;

    while (data != NULL) {

        output[i] = data->data;

        i++;
        data = data->next;

    }


}

void LiteString::add(LiteString& data)
{

    string_node* temp = data.head;

    string_node* cur = head;

    while (cur != NULL) {

        if (cur->data == 0) {
            break;
        }

        cur = cur->next;
    }


    while (temp != NULL) {
        cur->next = new string_node;
        cur = cur->next;
        cur->data = temp->data;

        temp = temp->next;

    }

    length += data.length;


}

bool LiteString::letterDecide(char data)
{

    string_node* temp = head;

    while (temp != NULL) {
        if (temp->data == data) {
            return true;
        }
        temp = temp->next;
    }

    return false;


}

bool LiteString::letterDecide(char data, int place)
{


    if (place + 1 > length) {
        return false;
    }

    string_node* temp = head;
    int i = 0;

    while (temp != NULL) {

        if (i == place) {
            break;
        }

        temp = temp->next;
        i++;

    }

    if (data == temp->data) {
        return true;
    }

    return false;

}