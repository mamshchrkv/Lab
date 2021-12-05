#pragma once

#include <iostream>
#include"IDictionary.h"
#include"DictionaryArray.h"
#include"DictionaryTree.h"
#include <iostream>
#include <string>
using namespace std;

template<typename TK, typename TV>
IDictionary<TK, TV>* page1(IDictionary<TK, TV>* dict, DictionaryArray<TK, TV> world, int number, int page, int index, int ost) {
    if (index == world.GetSize())
        return dict;
    else if (world[index]->val <= ost) {
        dict->Add(world[index]->key, page);
        return page1(dict, world, number, page, index + 1, ost - world[index]->val - 1);
    }
    else if (page % 10 != 9)
        return page1(dict, world, number, page + 1, index, number);
    else
        return page1(dict, world, number, page + 1, index, 3 * number / 4);
}


void symbol() {
	int num, choice;
    string a, b;
    DictionaryArray<string, int> world;
    cout << "Enter string:\n";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, a);
	cout << "Enter the number of characters:\n";
	cin >> num;
	a = a + ' ';
    int count = 0, index=0, n=1;
    for (int i = 0; i < a.length(); i++)
    {
        b += a[i];
        if (a[i]==' ')
        {
            b.pop_back();
            world.Add(b, b.length());
            count++;
            b = "";
        }
    }
    int ost = num / 2;
    cout << "Enter type:\n" << "1. Tree\n" << "2. Array\n";
    cin >> choice;
    switch (choice) {
    case 1: {
        DictionaryTree<string, int>* dict=new DictionaryTree<string, int>[1];
        dict=(DictionaryTree<string, int>*)page1(dict, world, num, n, index, ost);
        dict->Print();
        break;
    }
    case 2: {
        DictionaryArray<string, int>* dict= new DictionaryArray<string, int>[1];
        dict = (DictionaryArray<string, int>*)page1(dict, world, num, n, index, ost);
        dict->Print();
        break;
    }
    }
}

/*for (int y = 0; y < world.GetSize(); y++) {

        if (n == 1 && (world[y]->key <= ost)) {
            dict.Add(n, world[y]->val);
            ost = ost - world[y]->key - 1;
        }

        else if (n == 1 && world[y]->key <= ost) {
            dict.Add(n, world[y]->val);
            ost = ost - world[y]->key - 1;
        }

        else if (n == 1 && world[y]->key > ost) {
            n++;
            dict.Add(n, world[y]->val);
            ost = num - (world[y]->key + 1);
        }

        else if (n != 1 &&  n % 10 != 0 && world[y]->key <= ost) {
            dict.Add(n, world[y]->val);
            ost = ost - world[y]->key - 1;
        }

        else if (n != 1 && (n % 10!=0) && world[y]->key > ost) {
            n++;
            if (n % 10 != 0) {
                dict.Add(n, world[y]->val);
                ost = num - (world[y]->key + 1);
            }
            else if (n % 10 == 0 && world[y]->key <= 3 / 4 * num) {
                ost = 3 / 4 * num -(world[y]->key + 1);
                dict.Add(n, world[y]->val);
            }
            else if (n % 10 == 0 && world[y]->key > 3 / 4 * num) {
                n++;
                ost = num -(world[y]->key + 1);
                dict.Add(n, world[y]->val);
            }

        }

        else if (n / 10 ==0 && world[y]->key <= ost) {
            dict.Add(n, world[y]->val);
            ost = ost - world[y]->key - 1;
        }
    }
    dict.Print();*/