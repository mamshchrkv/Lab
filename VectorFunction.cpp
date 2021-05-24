
#include "pch.h"
#include "VectorFunction.h"

vector* create(int size) 
{
    vector* result = (vector*)malloc(sizeof(vector));
    result->size = size;
    return result;
}

void initialize(vector* vector)
{
    vector->len = 0;
    vector->head = (void*)malloc(sizeof(void*));
}

void del(vector* del) 
{
    if (del->head) 
        free(del->head);

    free(del);
}

void push(vector* pu, void* data, int count, size_t type) 
{
    pu->head = realloc(pu->head, (pu->len + count) * pu->size);

    void* tmp;
    if (type == sizeof(int))
        tmp = (int*)pu->head + pu->len;
    else if (type == sizeof(float))
        tmp = (float*)pu->head + pu->len;
    else if (type == sizeof(double))
        tmp = (double*)pu->head + pu->len;
    else
        tmp = NULL;

    memcpy(tmp, data, count * pu->size);
    pu->len += count;
}
