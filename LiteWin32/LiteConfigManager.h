#pragma once
#include "LiteString.h"

struct int_config {

    char* info;
    int content;

    int_config* left;
    int_config* right;


};

struct float_config {

    char* info;
    int content;

    float_config* left;
    float_config* right;

};

struct char_config {

    char* info;
    char content;

    char_config* left;
    char_config* right;

};

struct LiteString_config {

    char* info;
    LiteString content;

    LiteString_config* left;
    LiteString_config* right;

};

class LiteConfigManager {

public:

    LiteConfigManager();
    LiteConfigManager(const char*);

    ~LiteConfigManager();

    bool save(const char*);

    void getData(const char*, int&);
    void getData(const char*, char&);
    void getData(const char*, float&);
    //void getData(const char*,double&);
    void getData(const char*, LiteString&);

private:

    int_config* int_head;
    float_config* float_head;
    char_config* char_head;
    LiteString* LiteString_head;


};