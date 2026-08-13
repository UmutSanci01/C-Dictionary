#ifndef MY_TYPE_H
#define MY_TYPE_H


#include "Item.h"


enum {INT, STRING, STRING_S64, FLOAT, CHAR, BOOLEAN, LONG, INTU, INTAR, INTAR_S64};


typedef struct tagIteger {
    ItemData data;
    int value;
} Integer;

typedef struct tagFloat {
    ItemData data;
    float value;
} Float;

// FreeItem is not sufficient for this structure — requires a custom free function for 'arr'
typedef struct tagIntArray {
    ItemData data;
    size_t length;
    int *arr;
} IntAr;

typedef struct tagIntArrayStatic
{
    ItemData data;
    int arr[64];
} IntArray_S64;

// FreeItem is not sufficient for this structure — requires a custom free function for 'text'
typedef struct tagString {
    ItemData data;
    char *text;
} String;

typedef struct tagString64 {
    ItemData data;
    char text[64];
} String64;

// {enum data type, size of data type}
ItemData data_str = {STRING, sizeof(String)};
ItemData data_int = {INT, sizeof(Integer)};
ItemData data_intar = {INTAR, sizeof(IntAr)};


#endif