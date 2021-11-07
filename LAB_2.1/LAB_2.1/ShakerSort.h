#pragma once
#include "ArraySequence.h"

template<typename T>
void swapEl(Sequence<T>* c, int i)
{
    T buff;
    buff = (*c)[i];
    (*c)[i] = (*c)[i - 1];
    (*c)[i - 1] = buff;
}

//ф-ция "шейкер"-сортировки
template<typename T>
void ShakerSort(Sequence<T>* c)
{
    int leftMark = 1;
    int rightMark = c->GetSize() - 1;
    while (leftMark <= rightMark)
    {
        for (int i = rightMark; i >= leftMark; i--)
            if ((*c)[i - 1] > (*c)[i]) swapEl(c, i);
        leftMark++;


        for (int i = leftMark; i <= rightMark; i++)
            if ((*c)[i - 1] > (*c)[i]) swapEl(c, i);
        rightMark--;
    }
}