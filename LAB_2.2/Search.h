#pragma once

#include <iostream>
#include"DictionaryArray.h"
//#include"DictionarySequence.h"
#include <iostream>
#include <string>
using namespace std;
template<typename TK, typename TV>
DictionaryArray<TK, TV> Substring_search(DictionaryArray<TK, TV> dict, string a, int max, int min ) {
	string b;
	int h = 0;
	for (int i = 0; i < a.length(); i++) {
		for (int j = i; j <= max + i - 1; j++) {
			if (j < a.length()) {
				b += a[j];
				if (j - i + 1 >= min && !dict.ContainsKey(b)) {
					for (int t = 0; t < a.length() - (j - i); t++) {
						for (int y = 0; y <= (j - i); y++) {
							if (b[y] == a[t + y]) {
								h = h + 1;
								if (h == j - i + 1) {
									if (dict.ContainsKey(b))
										dict.AddKey(b, 1 + dict.Get(b));
									else
										dict.Add(b, 1);
									h = 0;
								}
							}
							else
								h = 0;
						}
						h = 0;
					}
				}
			}
		}
		b = "";
	}
	return dict;
}
void search() {
	string a, b;
	int min, max;
	cout << "Enter string:\n";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, a);
	cout << "Enter min length:\n";
	cin >> min;
	cout << "Enter max length:\n";
	cin >> max;
	int h = 0;
	DictionaryArray<string, int> dict;
	dict = Substring_search(dict, a, max, min);
	dict.PrintMaxVal();
	dict.Print();
}
