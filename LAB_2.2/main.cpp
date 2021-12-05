
#include <iostream>
//#include"DictionaryArray.h"
#include"indicator.h"
#include"Search.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
    int choice = 1;
    while (choice != 3) {
        cout << endl<<"Choose task\n" << "1. Pagination\n" << "2. Substring search\n" << "3. Exit\n";
        cin >> choice;
        switch (choice) {
        case 1: {
            symbol();
            break;
        }
        case 2: {
            search();
            break;
        }
        }
    }
    return 0;
 }