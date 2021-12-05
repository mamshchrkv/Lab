#pragma once
#include<iostream>
#include<stdexcept>
#include"IDictionary.h"
using namespace std;

template<typename TK, typename TV>
struct Element {
public:
	TK key;
	TV val;
};

template<typename TK, typename TV>
class DictionaryArray : public IDictionary<TK, TV> {
private:
	Element<TK,TV>** dict;
	int dict_size;
public:
	DictionaryArray() {
		dict=nullptr;
		dict_size = 0;
	}

	DictionaryArray(int size){
		dict_size = size;
		if (size != 0)
			dict = new Element<TK, TV>*[size];
		else
			dict = nullptr;
	}

	DictionaryArray(TK key1, TV val1) {
		dict = new Element<TK, TV>*[1];
		dict_size = 1;
		Element<TK, TV>* el = new Element<TK, TV>;
		el->key = key1;
		el->val = val1;
		dict[dict_size-1] = &*el;
	}

	[[nodiscard]] int GetSize() {
		return dict_size;
	}

	TV Get(TK key) {
		for (int i = 0; i < dict_size; i++) {
			if (dict[i]->key == key)
				return dict[i]->val;
		}
		throw out_of_range("index out of range");
	}

	int GetIndex(TK key) {
		for (int i = 0; i < dict_size; i++) {
			if (dict[i]->key == key)
				return i;
		}
		throw out_of_range("index out of range");
	}

	bool cmpk(int i) {
		return (dict[i]->key<dict[i+1]->key);
	}

	bool cmpv(int i) {
		return (dict[i]->val < dict[i + 1]->val);
	}

	bool ContainsKey(TK key) {
		for (int i = 0; i < dict_size; i++) {
			if (dict[i]->key == key)
				return true;
		}
		return false;
	}
	
	void ReSize(int size) {
		if (size < 0) {
			throw bad_array_new_length();
		}
		int old_size = GetSize();
		if (size < old_size) {
			while (old_size != size) {
				delete dict[old_size - 1];
				old_size--;
			}
		}
		else {
			Element<TK, TV>** dict_new = new Element<TK, TV>*[size];
			for (int i = 0; i < old_size; i++) {
				Element<TK, TV>* el = new Element<TK, TV>[2];
				el->key = dict[i]->key;
				el->val = dict[i]->val;
				dict_new[i] = &*el;
			}
			for (int i = old_size; i < size; i++) {
				Element<TK, TV>* el = new Element<TK, TV>[size];
				dict_new[i] = &*el;
			}
			delete dict;
			dict = dict_new;
		}
		dict_size = size;
	}

	void Add(TK key, TV val) {
		ReSize(dict_size+1);
		dict[dict_size-1]->key= key;
		dict[dict_size-1]->val = val;
	}

	void AddKey(TK key, TV val) {
		dict[GetIndex(key)]->val = val;
	}

	void PrintMaxVal() {
		int max = 0;
		for (int i = 0; i < dict_size; i++) {
			if (dict[i]->val > max)
				max = dict[i]->val;
		}
		cout << endl << "Max - " <<max<< endl;
		cout << "String: ";
		for (int i = 0; i < dict_size; i++) {
			if (dict[i]->val == max)
				cout<< dict[i]->key<<" ; ";
		}
	}

	void PrintMinVal() {
		int min=dict[0]->val;;
		for (int i = 0; i < dict_size; i++) {
			if (dict[i]->val < min)
				min = dict[i]->val;
		}
		cout << endl << "Min - " << min << endl;
		cout << "String: ";
		for (int i = 0; i < dict_size; i++) {
			if (dict[i]->val == min)
				cout << dict[i]->key << " ; ";
		}
	}

	void Remove(TK key) {
		int i = 0;
		while (dict[i]->key != key) {
			i++;
		}
		for (i; i < dict_size - 1; i++) {
			dict[i]->key = dict[i + 1]->key;
			dict[i]->val = dict[i + 1]->val;
		}
		dict.ReSize(dict_size - 1);
	}

	void SortKey() {
		for (int i = dict_size - 1; i >= 0; i--) {
			for (int j = 0; j < i; j++) {
				if (dict[j]->key > dict[j + 1]->key) {
					TK item = dict[j + 1]->key;
					TV it = dict[j + 1]->val;
					dict[j + 1]->key = dict[j]->key;
					dict[j + 1]->val = dict[j]->val;
					dict[j]->key = item;
					dict[j]->val = it;
				}
			}
		}
	}

	void Print() {
		cout << "[";
		for (int i = 0; i < dict_size; i++) {
			cout <<"(";
			cout << dict[i]->key << "; ";
			cout << dict[i]->val << ") ";
		}
		cout << "]";
	}

	TK* GetKeys() {
		TK* array = new TK[dict_size];
		for (int i = 0; i < dict_size; i++) {
			array[i] = dict[i]->key;
		}
		return array;
	}
	
	TV* GetValues() {
		TV* array= new TV[dict_size];
		for (int i = 0; i < dict_size; i++) {
			array[i] = dict[i]->val;
		}
		return array;
	}

	Element<TK, TV>* GetFirst() {
		return dict[0];
	}

	Element<TK, TV>* GetLast() {
		return dict[dict.GetSize-1];
	}

	Element<TK, TV>* operator[](int index) const {
		return dict[index];
	}

	virtual ~DictionaryArray<TK,TV>() = default;
};