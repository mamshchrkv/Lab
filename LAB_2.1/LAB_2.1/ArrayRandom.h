#pragma once
#include "ISorter.h"
#include "makeSeqHelp.h"

void arrayrandom() {
    Sequence<int>* pointer;
    Sequence<float>* point;
    cout << endl << "Choose Type:" << endl;
    cout << "1.Integer\n2.Float\n3.Back" << endl;
    int t;
    cin >> t;
    switch (t) {

    case 1: {
        cout << endl << "Input dimension:" << endl;
        int dimension;
        cin >> dimension;
        int* array = makeSeq<int>(dimension);
        ArraySequence<int> a(array, dimension);
        cout << endl << "Choose Sort:" << endl;
        cout << "1.ShakerSort\n2.InsertionSort\n3.ShellSort\n4. Back" << endl;
        int sort;
        cin >> sort;
        switch (sort) {

        case 1: {
            ShakerSorter<int> q;
            cout << endl << "Tested Array:" << "\n";
            a.Print();
            pointer = &a;
            q.sort(pointer);
            cout << endl << "Result:\n";
            a.Print();
            break;
        }

        case 2: {
            InsertionSorter<int> q;
            cout << endl << "Tested Array:\n";
            a.Print();
            pointer = &a;
            q.sort(pointer);
            cout << endl << "Result:\n";
            a.Print();
            break;
        }

        case 3: {
            ShellSorter<int> q;
            cout << "Tested Array:" << "\n";
            a.Print();
            cout << "\n";
            pointer = &a;
            q.sort(pointer);
            cout << "Result:\n";
            a.Print();
            break;
        }
        case 4: {
            break;
        }
        }

        break;
    }

    case 2: {
        cout << "Input dimension:" << "\n";
        int dimension;
        cin >> dimension;
        cout << "\n";
        float* array = makeSeq<float>(dimension);
        ArraySequence<float> a(array, dimension);
        cout << endl << "Choose Sort:" << endl;
        cout << "1.ShakerSort\n2.InsertionSort\n3.ShellSort\n4.Back" << endl;
        int sort;
        cin >> sort;
        cout << "\n";
        switch (sort) {

        case 1: {
            ShakerSorter<float> q;
            cout << "Tested Array:" << "\n";
            a.Print();
            cout << "\n";
            point = &a;
            q.sort(point);
            cout << "Result:\n";
            a.Print();
            break;
        }

        case 2: {
            InsertionSorter<float> q;
            cout << "Tested Array:" << "\n";
            a.Print();
            cout << "\n";
            point = &a;
            q.sort(point);
            cout << "Result:\n";
            a.Print();
            break;
        }

        case 3: {
            ShellSorter<float> q;
            cout << "Tested Array:" << "\n";
            a.Print();
            cout << "\n";
            point = &a;
            q.sort(point);
            cout << "Result:\n";
            a.Print();
            break;
        }
        case 4: {
            break;
        }
        }

        break;
    }
    }
}