#include "pch.h"
#include "PolynomialFunction.h"

vector* sumZ(vector* p1, vector* p2) 
{
    vector* p3 = NULL;

    if (p1->len > p2->len) 
    {
        p3 = create(p1->size);
        p3->head = (int*)calloc(p2->len, p2->size);
        p3->len = p2->len;
        
        for (int i = 0; i < p2->len; i++) 
            *((int*)(p3->head) + i) = *((int*)(p1->head) + i) + *((int*)(p2->head) + i);
        
        push(p3, (int*)p1->head + p2->len, p1->len - p2->len, sizeof(int));
    }

    if (p1->len < p2->len) 
    {
        p3 = create(p2->size);
        p3->head = (int*)calloc(p1->len, p1->size);
        p3->len = p1->len;
        
        for (int i = 0; i < p1->len; i++) 
            *((int*)(p3->head) + i) = *((int*)(p2->head) + i) + *((int*)(p1->head) + i);
        
        push(p3, (int*)p2->head + p1->len, p2->len - p1->len, sizeof(int));
    }

    if (p1->len == p2->len) 
    {
        p3 = create(p2->size);
        p3->head = (int*)calloc(p1->len, p1->size);
        p3->len = p2->len;

        for (int i = 0; i < p1->len; i++) 
            ((int*)(p3->head))[i] = *((int*)(p1->head) + i) + *((int*)((*p2).head) + i);
    }

    return p3;
}

vector* subZ(vector* p1, vector* p2)
{
    vector* p3 = NULL;

    if (p1->len > p2->len)
    {
        p3 = create(p1->size);
        p3->head = (int*)calloc(p2->len, p2->size);
        p3->len = p2->len;

        for (int i = 0; i < p2->len; i++)
            *((int*)(p3->head) + i) = *((int*)(p1->head) + i) - *((int*)(p2->head) + i);

        push(p3, (int*)p1->head + p2->len, p1->len - p2->len, sizeof(int));
    }

    if (p1->len < p2->len)
    {
        p3 = create(p2->size);
        p3->head = (int*)calloc(p2->len, p2->size);
        p3->len = p2->len;

        for (int i = 0; i < p2->len; i++)
        {
            if (i < p1->len)
                *((int*)(p3->head) + i) = *((int*)(p1->head) + i) - *((int*)(p2->head) + i);
            else
                *((int*)(p3->head) + i) = -*((int*)(p2->head) + i);
        }
    }

    if (p1->len == p2->len)
    {
        p3 = create(p2->size);
        p3->head = (int*)calloc(p1->len, p1->size);
        p3->len = p2->len;

        for (int i = 0; i < p1->len; i++)
            ((int*)(p3->head))[i] = *((int*)(p1->head) + i) - *((int*)(p2->head) + i);
    }

    return p3;
}

vector* scalarZ(vector* p1, int a)
{
    vector* p3 = NULL;
    p3 = create(p1->size);
    p3->len = p1->len;
    p3->head = (int*)calloc(p1->len, p1->size);
    for (int i = 0; i < p1->len; i++)
        *((int*)(p3->head) + i) = *((int*)(p1->head) + i) * a;

    return p3;
}

int gornerZ(vector* p1, vector* pointZ) 
{
    int sum= *((int*)p1->head);

    for (int i = 1 ; i < p1->len; i++)
        sum += (*((int*)p1->head+i) ) *( *((int*)pointZ->head + i - 1));

    return sum;
}

vector* sumR(vector* p1, vector* p2) 
{
    vector* p3 = NULL;

    if (p1->len > p2->len) 
    {
        p3 = create(p1->size);
        p3->len = p2->len;
        p3->head = (double*)calloc(p2->len, p2->size);

        for (int i = 0; i < p2->len; i++)
            ((double*)p3->head)[i] = ((double*)p1->head)[i] + ((double*)p2->head)[i];

        push(p3, (double*)p1->head + p2->len, p1->len - p2->len, sizeof(double));
    }

    if (p1->len < p2->len) 
    {
        p3 = create(p2->size);
        p3->len = p1->len;
        p3->head = (double*)calloc(p1->len, p1->size);
        
        for (int i = 0; i < p1->len; i++)
            *((double*)(p3->head) + i) = *((double*)(p2->head) + i) + *((double*)(p1->head) + i);

        push(p3, (double*)p2->head + p1->len, p2->len - p1->len, sizeof(double));
    }

    if (p1->len == p2->len) 
    {
        p3 = create(p2->size);
        p3->len = p2->len;
        p3->head = (double*)calloc(p1->len, p1->size);
        
        for (int i = 0; i < p1->len; i++)
            *((double*)(p3->head) + i) = *((double*)(p2->head) + i) + *((double*)(p1->head) + i);
    }

    return p3;
}

vector* subR(vector* p1, vector* p2)
{
    vector* p3 = NULL;

    if (p1->len > p2->len)
    {
        p3 = create(p1->size);
        p3->len = p2->len;
        p3->head = (double*)calloc(p2->len, p2->size);

        for (int i = 0; i < p2->len; i++)
            ((double*)p3->head)[i] = ((double*)p1->head)[i] - ((double*)p2->head)[i];

        push(p3, (double*)p1->head + p2->len, p1->len - p2->len, sizeof(double));
    }

    if (p1->len < p2->len)
    {
        p3 = create(p2->size);
        p3->len = p2->len;
        p3->head = (double*)calloc(p2->len, p2->size);

        for (int i = 0; i < p2->len; i++)
        {

            if (i < p1->len)
                *((double*)(p3->head) + i) = *((double*)(p1->head) + i) - *((double*)(p2->head) + i);
            else
                *((double*)(p3->head) + i) = -*((double*)(p2->head) + i);
        }
        //push(p3, (double*)p1->head + p2->len, p2->len - p2->len, sizeof(double));
    }

    if (p1->len == p2->len)
    {
        p3 = create(p2->size);
        p3->len = p2->len;
        p3->head = (double*)calloc(p1->len, p1->size);

        for (int i = 0; i < p1->len; i++)
            *((double*)(p3->head) + i) = *((double*)(p1->head) + i) - *((double*)(p2->head) + i);
    }

    return p3;
}

vector* scalarR(vector* p1, double a)
{
    vector* p3 = NULL;
    p3 = create(p1->size);
    p3->len = p1->len;
    p3->head = (double*)calloc(p1->len, p1->size);
    for (int i = 0; i < p1->len; i++) 
        *((double*)(p3->head) + i) = *((double*)(p1->head) + i)*a;

    return p3;
}

double gornerR(vector* p1, vector* pointR) 
{
    double sum = *((double*)p1->head);
    for (int i = 1; i < p1->len; i++)
    {   
        sum += *((double*)p1->head + i) * *((double*)pointR->head + (i - 1));
    }

    return sum;
}

char* printZ(vector* P) 
{
    char msg[500];
    int i;
    for (i = 0; i < P->len - 1; i++)
    {
        if(i==0)
            sprintf_s(msg, "%d + ", ((int*)P->head)[i]);
        else
            sprintf_s(msg, "%s%d*X%d + ", msg, ((int*)P->head)[i], i);
    }
   
    sprintf_s(msg, "%s%d*X%d\n", msg, ((int*)P->head)[i], i);
    
    printf("%s\n", msg);
    return msg;
}

char* printR(vector* P) 
{
    char msg[500];
    int i;
    for (i = 0; i < P->len - 1; i++)
    {
        if(i==0)
            sprintf_s(msg, "%lf + ", ((double*)P->head)[i]);
        else
            sprintf_s(msg, "%s%lf*X%d + ", msg, ((double*)P->head)[i], i);
    }

    sprintf_s(msg, "%s%lf*X%d\n", msg, ((double*)P->head)[i], i);

    printf("%s\n", msg);
    return msg;
}


