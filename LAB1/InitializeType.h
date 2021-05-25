
#ifndef InitializeType_H
#define InitializeType_H

#include <stdlib.h>
#include <string.h>

typedef struct vector
{
    void* head;
    int len;
    int size; // может быть лучше size_t - тогда будет сразу понятно с каким типом данных работаем
} vector;

#endif

