#ifndef VectorFunction_H
#define VectorFunction_H

#include <stdio.h>
#include "InitializeType.h"

vector* create(int);
void initialize(vector* vector);
void del(vector*);
void push(vector* pu, void* data, int count, size_t type);

#endif

