#pragma once
#include "sequence.h"
using namespace std;
template<typename T>

void InsertionSort(Sequence<T>* c) 
{
    T temp; 
    int item; 
    for (int i = 1; i < c->GetSize(); i++)
    {
        temp = (*c)[i]; 
        item = i - 1; 
        while (item >= 0 && (*c)[item] > temp) 
        {
            (*c)[item + 1] = (*c)[item]; 
            (*c)[item] = temp;
            item--;
        }
    }
}
