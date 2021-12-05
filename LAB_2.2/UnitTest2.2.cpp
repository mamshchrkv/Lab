#include "pch.h"
#include "CppUnitTest.h"
#include <stdlib.h>
#include <iostream>
#include <complex>
#include <cmath>
#include"C:\Users\я\source\repos\LAB_2.2\LAB_2.2\DictionaryArray.h"
#include"C:\Users\я\source\repos\LAB_2.2\LAB_2.2\DictionaryTree.h"
#include"C:\Users\я\source\repos\LAB_2.2\LAB_2.2\indicator.h"
#include"C:\Users\я\source\repos\LAB_2.2\LAB_2.2\Search.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		TEST_METHOD(DictionaryTreeSize)
		{
			int key[10] = { 1,2,3,4,5,6,7,8,9,10 };
			int val[10] = { 11,12,13,14,15,16,17,18,19,20};
			DictionaryTree<int, int> tree;
			for (int i = 0; i < 10; i++) {
				tree.Add(key[i], val[i]);
			}
			bool res = true;
			int size=tree.GetSize();
			if (size!=10)
				res = false;
			Assert::IsTrue(res, L"Method Size works no correct");
		}
		TEST_METHOD(DictionaryTreeContainsKey)
		{
			int key[10] = { 1,2,3,4,5,6,7,8,9,10 };
			int val[10] = { 11,12,13,14,15,16,17,18,19,20 };
			DictionaryTree<int, int> tree;
			for (int i = 0; i < 10; i++) {
				tree.Add(key[i], val[i]);
			}
			bool res = true, boolkey;
			for (int i = 0; i < 10; i++) {
				boolkey=tree.ContainsKey(key[i]);
				if (!boolkey) {
					res = false;
					break;
				}
			}
			Assert::IsTrue(res, L"Method ContainsKey works no correct");
		}
		TEST_METHOD(DictionaryTreeGetKeys)
		{
			int key[10] = { 1,2,3,4,5,6,7,8,9,10 };
			int val[10] = { 11,12,13,14,15,16,17,18,19,20 };
			DictionaryTree<int, int> tree;
			for (int i = 0; i < 10; i++) {
				tree.Add(key[i], val[i]);
			}
			bool res = true;
			int* keytree = tree.GetKeys();
			for (int i = 0; i < 10; i++) {
				for (int j=0; j<10; j++){
					if (keytree[j] = key[i])
						break;
					else
						res = false;
				}
			}
			Assert::IsTrue(res, L"Method GetKeys works no correct");
		}
		TEST_METHOD(DictionaryTreeGetValues)
		{
			int key[10] = { 1,2,3,4,5,6,7,8,9,10 };
			int val[10] = { 11,12,13,14,15,16,17,18,19,20 };
			DictionaryTree<int, int> tree;
			for (int i = 0; i < 10; i++) {
				tree.Add(key[i], val[i]);
			}
			bool res = true;
			int* valtree = tree.GetValues();
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (valtree[j] = val[i])
						break;
					else
						res = false;
				}
			}
			Assert::IsTrue(res, L"Method GetValues works no correct");
		}
		TEST_METHOD(DictionaryTreeGet)
		{
			int key[10] = { 1,2,3,4,5,6,7,8,9,10 };
			int val[10] = { 11,12,13,14,15,16,17,18,19,20 };
			DictionaryTree<int, int> tree;
			for (int i = 0; i < 10; i++) {
				tree.Add(key[i], val[i]);
			}
			bool res = true;
			for (int i = 0; i < 10; i++) {
				if (val[i]!=tree.Get(key[i]))
					res = false;
				}
			Assert::IsTrue(res, L"Method Get works no correct");
		}
		TEST_METHOD(DictionaryArraySize)
		{
			int key[10] = { 1,2,3,4,5,6,7,8,9,10 };
			int val[10] = { 11,12,13,14,15,16,17,18,19,20 };
			DictionaryArray<int, int> array;
			for (int i = 0; i < 10; i++) {
				array.Add(key[i], val[i]);
			}
			bool res = true;
			int size = array.GetSize();
			if (size != 10)
				res = false;
			Assert::IsTrue(res, L"Method Size works no correct");
		}
		TEST_METHOD(DictionaryArrayContainsKey)
		{
			int key[10] = { 1,2,3,4,5,6,7,8,9,10 };
			int val[10] = { 11,12,13,14,15,16,17,18,19,20 };
			DictionaryArray<int, int> array;
			for (int i = 0; i < 10; i++) {
				array.Add(key[i], val[i]);
			}
			bool res = true, boolkey;
			for (int i = 0; i < 10; i++) {
				boolkey = array.ContainsKey(key[i]);
				if (!boolkey) {
					res = false;
					break;
				}
			}
			Assert::IsTrue(res, L"Method ContainsKey works no correct");
		}
		TEST_METHOD(DictionaryArrayGetKeys)
		{
			int key[10] = { 1,2,3,4,5,6,7,8,9,10 };
			int val[10] = { 11,12,13,14,15,16,17,18,19,20 };
			DictionaryArray<int, int> array;
			for (int i = 0; i < 10; i++) {
				array.Add(key[i], val[i]);
			}
			bool res = true;
			int* keyarray = array.GetKeys();
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (keyarray[j] = key[i])
						break;
					else
						res = false;
				}
			}
			Assert::IsTrue(res, L"Method GetKeys works no correct");
		}
		TEST_METHOD(DictionarykeyArrayGetValues)
		{
			int key[10] = { 1,2,3,4,5,6,7,8,9,10 };
			int val[10] = { 11,12,13,14,15,16,17,18,19,20 };
			DictionaryArray<int, int> array;
			for (int i = 0; i < 10; i++) {
				array.Add(key[i], val[i]);
			}
			bool res = true;
			int* valarray = array.GetValues();
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (valarray[j] = val[i])
						break;
					else
						res = false;
				}
			}
			Assert::IsTrue(res, L"Method GetValues works no correct");
		}
		TEST_METHOD(DictionaryArrayGet)
		{
			int key[10] = { 1,2,3,4,5,6,7,8,9,10 };
			int val[10] = { 11,12,13,14,15,16,17,18,19,20 };
			DictionaryArray<int, int> array;
			for (int i = 0; i < 10; i++) {
				array.Add(key[i], val[i]);
			}
			bool res = true;
			for (int i = 0; i < 10; i++) {
				if (val[i] != array.Get(key[i]))
					res = false;
			}
			Assert::IsTrue(res, L"Method Get works no correct");
		}
		TEST_METHOD(indicator)
		{
			int val[11] = { 4,2,4,7,5,3,3,4,6,5,5};
			int page_val[11] = { 1, 2, 2, 3, 4, 4, 5, 5, 6, 7, 8 };
			string key[11] = { "Life","is",  "what",  "happens", "while", "you", "are",  
				"busy",  "making",  "other",  "plans" };
			DictionaryArray<string, int> world;
			for (int i = 0; i < 11; i++) {
				world.Add(key[i], val[i]);
			}
			bool res = true;
			DictionaryArray<string, int>* dict= new DictionaryArray<string, int>[1];
			dict = (DictionaryArray<string, int>*)page1(dict, world, 10, 1, 0, 5);
			int* getval = dict->GetValues();
			for (int i = 0; i < 11; i++) {
				if (page_val[i] != getval[i]) {
					res = false;
					break;
				}
			}
			Assert::IsTrue(res, L"Function indicator works no correct");
		}
		TEST_METHOD(search)
		{
			int val[24] = {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
			string a = "abcdefghklmna";
			DictionaryArray<string, int> world;
			bool res = true;
			world = Substring_search(world, a, 2, 1);
			int* getval = world.GetValues();
			for (int i = 0; i < 24; i++) {
				if (val[i] != getval[i]) {
					res = false;
					break;
				}
			}
			Assert::IsTrue(res, L"Function search works no correct");
		}
	};
}
