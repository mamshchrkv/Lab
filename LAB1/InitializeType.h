
#ifndef InitializeType_H
#define InitializeType_H

#include <stdlib.h>
#include <string.h>

typedef struct vector
{
    void* head;
    int len;
    int size; // ����� ���� ����� size_t - ����� ����� ����� ������� � ����� ����� ������ ��������
} vector;

#endif

