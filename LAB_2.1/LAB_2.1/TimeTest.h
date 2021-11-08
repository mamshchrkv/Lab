#pragma once
#include <iostream>
#include <fstream>
#include <ctime>  
#include "ISorter.h"
#include"ArraySequence.h"
#include"ListSequence.h"
#include"SequenceMake.h"
using namespace std;
ofstream file;

void time_array_int() {

    for (int i = 500; i < 20001; i = i + 500) {
        int* array = makeSequenceRand<int>(i);
        ArraySequence<int> a(array, i);
        ArraySequence<int> b(array, i);
        ArraySequence<int> ñ(array, i);
        ShakerSorter<int> shaker;
        InsertionSorter<int> ins;
        ShellSorter<int> shell;
        Sequence<int>* pointer;
        pointer = &a;
        cout << endl << "Amout of elements: " << i << endl;
        unsigned int start_time = clock();
        shaker.sort(pointer);
        unsigned int end_time = clock();
        //cout << "Time ShakerSort: " << (end_time - start_time) << endl;
        pointer = &b;
        double start_time1 = clock();
        ins.sort(pointer);
        double end_time1 = clock();
        //cout << "Time InsertionSort: " << (end_time1 - start_time1) << endl
        pointer = &ñ;
        double start_time2 = clock();
        shell.sort(pointer);
        unsigned int end_time2 = clock();
        file.open("TimeShakerSortArrInt.txt", ios::app);
        file << (end_time - start_time) * 1000 / CLOCKS_PER_SEC << endl;
        file.close();
        file.open("TimeInsertionSortArrInt.txt", ios::app);
        file << (end_time1 - start_time1) * 1000 / CLOCKS_PER_SEC << endl;
        file.close();
        file.open("TimeShellSortArrInt.txt", ios::app);
        file << (end_time2 - start_time2) * 1000 / CLOCKS_PER_SEC << endl;
        file.close();
    }
}

void time_array_float() {

    for (int i = 500; i < 20001; i = i + 500) {
        float* array = makeSequenceRand<float>(i);
        ArraySequence<float> a(array, i);
        ArraySequence<float> b(array, i);
        ArraySequence<float> ñ(array, i);
        ShakerSorter<float> shaker;
        InsertionSorter<float> ins;
        ShellSorter<float> shell;
        Sequence<float>* pointer;
        pointer = &a;
        cout << endl << "Amout of elements: " << i << endl;
        unsigned int start_time = clock();
        shaker.sort(pointer);
        unsigned int end_time = clock();
        //cout << "Time ShakerSort: " << (end_time - start_time) << endl;
        pointer = &b;
        unsigned int start_time1 = clock();
        ins.sort(pointer);
        unsigned int end_time1 = clock();
        //cout << "Time InsertionSort: " << (end_time1 - start_time1) << endl
        pointer = &ñ;
        unsigned int start_time2 = clock();
        shell.sort(pointer);
        unsigned int end_time2 = clock();
        file.open("TimeShakerSortArrfloat.txt", ios::app);
        file << (end_time - start_time) * 1000 / CLOCKS_PER_SEC << endl;
        file.close();
        file.open("TimeInsertionSortArrfloat.txt", ios::app);
        file << (end_time1 - start_time1) * 1000 / CLOCKS_PER_SEC << endl;
        file.close();
        file.open("TimeShellSortArrfloat.txt", ios::app);
        file << (end_time2 - start_time2) * 1000 / CLOCKS_PER_SEC << endl;
        file.close();
    }
}

void time_list_int() {

    for (int i = 50; i < 1001; i = i + 50) {
        int* array = makeSequenceRand<int>(i);
        ListSequence<int> a(array, i);
        ListSequence<int> b(array, i);
        ListSequence<int> ñ(array, i);
        ShakerSorter<int> shaker;
        InsertionSorter<int> ins;
        ShellSorter<int> shell;
        Sequence<int>* pointer;
        pointer = &a;
        cout << endl << "Amout of elements: " << i << endl;
        unsigned int start_time = clock();
        shaker.sort(pointer);
        unsigned int end_time = clock();
        //cout << "Time ShakerSort: " << (end_time - start_time) << endl;
        pointer = &b;
        unsigned int start_time1 = clock();
        ins.sort(pointer);
        unsigned int end_time1 = clock();
        //cout << "Time InsertionSort: " << (end_time1 - start_time1) << endl
        pointer = &ñ;
        unsigned int start_time2 = clock();
        shell.sort(pointer);
        unsigned int end_time2 = clock();
        file.open("TimeShakerSortListInt.txt", ios::app);
        file << (end_time - start_time) * 1000 / CLOCKS_PER_SEC << endl;
        file.close();
        file.open("TimeInsertionSortListInt.txt", ios::app);
        file << (end_time1 - start_time1) * 1000 / CLOCKS_PER_SEC << endl;
        file.close();
        file.open("TimeShellSortListInt.txt", ios::app);
        file << (end_time2 - start_time2) * 1000 / CLOCKS_PER_SEC << endl;
        file.close();
    }
}

void time_list_float() {

    for (int i = 500; i < 1001; i = i + 50) {
        float* array = makeSequenceRand<float>(i);
        ListSequence<float> a(array, i);
        ListSequence<float> b(array, i);
        ListSequence<float> ñ(array, i);
        ShakerSorter<float> shaker;
        InsertionSorter<float> ins;
        ShellSorter<float> shell;
        Sequence<float>* pointer;
        pointer = &a;
        cout << endl << "Amout of elements: " << i << endl;
        unsigned int start_time = clock();
        shaker.sort(pointer);
        unsigned int end_time = clock();
        //cout << "Time ShakerSort: " << (end_time - start_time) << endl;
        pointer = &b;
        unsigned int start_time1 = clock();
        ins.sort(pointer);
        unsigned int end_time1 = clock();
        //cout << "Time InsertionSort: " << (end_time1 - start_time1) << endl
        pointer = &ñ;
        unsigned int start_time2 = clock();
        shell.sort(pointer);
        unsigned int end_time2 = clock();
        file.open("TimeShakerSortListfloat.txt", ios::app);
        file << (end_time - start_time) * 1000 / CLOCKS_PER_SEC << endl;
        file.close();
        file.open("TimeInsertionSortListfloat.txt", ios::app);
        file << (end_time1 - start_time1) * 1000 / CLOCKS_PER_SEC << endl;
        file.close();
        file.open("TimeShellSortListfloat.txt", ios::app);
        file << (end_time2 - start_time2) * 1000 / CLOCKS_PER_SEC << endl;
        file.close();
    }
}
