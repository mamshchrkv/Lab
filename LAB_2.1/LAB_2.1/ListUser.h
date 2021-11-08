#pragma once

#include "ISorter.h"
#include "makeSeqHelp.h"

void listuser() {
    int t = 0;
    while (t != 3) {
        Sequence<int>* pointer;
        Sequence<float>* point;
        cout << endl << "Choose Type:" << endl;
        cout << "1.Integer\n2.Float\n3.Back" << endl;
        cin >> t;
        if (t != 1 && t != 2 && t != 3)
            cout << "Incorrect choice! Try again" << endl;
        switch (t) {

        case 1: {
            cout << endl << "Input dimension:" << endl;
            int dimension;
            cin >> dimension;
            int* array = makeSequence<int>(dimension);
            ListSequence<int> a(array, dimension);
            cout << endl << "Choose Sort:" << endl;
            cout << "1.ShakerSort\n2.InsertionSort\n3.ShellSort\n4.Back" << endl;
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
                cout << endl << "Tested Array:" << "\n";
                a.Print();
                pointer = &a;
                q.sort(pointer);
                cout << endl << "Result:\n";
                a.Print();
                break;
            }

            case 3: {
                ShellSorter<int> q;
                cout << endl << "Tested Array:" << "\n";
                a.Print();
                pointer = &a;
                q.sort(pointer);
                cout << endl << "Result:\n";
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
            float* array = makeSequence<float>(dimension);
            ListSequence<float> a(array, dimension);
            cout << endl << "Choose Sort:" << endl;
            cout << "1.ShakerSort\n2.InsertionSort\n3.ShellSort\n4. Back" << endl;
            int sort;
            cin >> sort;
            switch (sort) {

            case 1: {
                ShakerSorter<float> q;
                cout << endl << "Tested Array:" << "\n";
                a.Print();
                point = &a;
                q.sort(point);
                cout << endl << "Result:\n";
                a.Print();
                break;
            }

            case 2: {
                InsertionSorter<float> q;
                cout << endl << "Tested Array:" << "\n";
                a.Print();
                point = &a;
                q.sort(point);
                cout << endl << "Result:\n";
                a.Print();
                break;
            }

            case 3: {
                ShellSorter<float> q;
                cout << endl << "Tested Array:" << "\n";
                a.Print();
                point = &a;
                q.sort(point);
                cout << endl << "Result:\n";
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
}
