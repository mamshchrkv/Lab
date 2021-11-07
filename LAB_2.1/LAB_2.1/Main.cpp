#pragma once

#include <iostream>
#include "ArrayUser.h"
#include "ArrayRandom.h"
#include "ListRandom.h"
#include "ListUser.h"
#include "ISorter.h"
#include "InsertionSort.h"
#include "ShellSort.h"

using namespace std;
int main() {
    int type = 0;
    while (type != 3) {
        cout << "Choose Type:" << endl;
        cout << "1.Array\n2.List\n3.Exit" << endl;
        cin >> type;
        switch (type) {
        case 1: {
            cout << "Generate random nums ? " << endl;
            cout << "1.Yes\n2.No\n3.Back" << endl;
            int answer;
            cin >> answer;
            switch (answer) {
            case 1: {
                arrayrandom();
                break;
            }
            case 2: {
                arrayuser();
                break;
            }
            case 3: {
                break;
            }
            }
            break;
        }

        case 2: {
            cout << "Generate random nums ? " << endl;
            cout << "1.Yes\n2.No\n3.Back" << endl;
            int answer;
            cin >> answer;
            switch (answer) {
            case 1: {
                listrandom();
                break;
            }
            case 2: {
                listuser();
                break;
            }
            case 3: {
                break;
            }
            }
            break;
        }

        case 3: {
            break;
        }
        }
    }
}