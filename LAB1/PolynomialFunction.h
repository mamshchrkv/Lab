#ifndef Polynomial_H
#define Polynomial_H

#include <stdio.h>
#include "InitializeType.h"

vector* sumZ(vector* p1, vector* p2);
vector* subZ(vector* p1, vector* p2);
vector* scalarZ(vector* p1, int a);
int gornerZ(vector* p1, vector* t);

vector* sumR(vector* p1, vector* p2);
vector* subR(vector* p1, vector* p2);
vector* scalarR(vector* p1, double a);
double gornerR(vector* p1, vector* t);

char* printZ(vector*);
char* printR(vector* P);

#endif
