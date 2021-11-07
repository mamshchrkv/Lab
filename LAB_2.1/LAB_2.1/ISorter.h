#pragma once
#include "sequence.h"
#include "ArraySequence.h"
#include "ListSequence.h"
#include "ShakerSort.h"
#include "ShellSort.h"
#include "InsertionSort.h"

template<typename T>
class ISorter {
public:
    virtual void sort(Sequence<T>* seq) = 0;
};

template<typename T>
class ShakerSorter : public ISorter<T> {
public:
    void sort(Sequence<T>* seq) override {
        ShakerSort(seq);
    }
};

template<typename T>
class InsertionSorter : public ISorter<T> {
public:
    void sort(Sequence<T>* seq) override {
        InsertionSort(seq);
    }
};

template<typename T>
class ShellSorter : public ISorter<T> {
public:
    void sort(Sequence<T>* seq) override {
        ShellSort(seq);
    }
};
