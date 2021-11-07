#include "pch.h"
#include "CppUnitTest.h"
#include <stdlib.h>
#include <iostream>
#include <complex>
#include <cmath>
#include"C:\Users\я\source\repos\LAB_2.1\LAB_2.1\ListSequence.h"
#include"C:\Users\я\source\repos\LAB_2.1\LAB_2.1\ArraySequence.h"
#include"C:\Users\я\source\repos\LAB_2.1\LAB_2.1\ISorter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(SSArrayInt)
		{
			Sequence<int>* seq;
			ShakerSorter<int> q;
			int test_arr[15] = { -15, -98, 0, 325, 628, 9, -7, 35, 16, -54, 1, 42, -1, 900, 2 };
			int result_arr[15] = { -98, -54, -15, -7, -1, 0, 1, 2, 9, 16, 35, 42, 325, 628, 900 };
			ArraySequence<int> a(test_arr, 15);
			seq = &a;
			q.sort(seq);
			bool res = true;
			for (int i = 0; i < 15; i++)
				if (abs(a.Get(i) - result_arr[i]) > 0.00000001) {
					res = false;
					break;
				}
			Assert::IsTrue(res, L"Shakersort Array Integer not work");
		}

		TEST_METHOD(ISArrayInt)
		{
			Sequence<int>* seq;
			InsertionSorter<int> q;
			int test_arr[15] = { -15, -98, 0, 325, 628, 9, -7, 35, 16, -54, 1, 42, -1, 900, 2 };
			int result_arr[15] = { -98, -54, -15, -7, -1, 0, 1, 2, 9, 16, 35, 42, 325, 628, 900 };
			ArraySequence<int> a(test_arr, 15);
			seq = &a;
			q.sort(seq);
			bool res = true;
			for (int i = 0; i < 15; i++)
				if (abs(a.Get(i) - result_arr[i]) > 0.00000001) {
					res = false;
					break;
				}
			Assert::IsTrue(res, L"insertionSort Array Integer not work");
		}

		TEST_METHOD(ShellSArrayInt)
		{
			Sequence<int>* seq;
			ShellSorter<int> q;
			int test_arr[15] = { -15, -98, 0, 325, 628, 9, -7, 35, 16, -54, 1, 42, -1, 900, 2 };
			int result_arr[15] = { -98, -54, -15, -7, -1, 0, 1, 2, 9, 16, 35, 42, 325, 628, 900 };
			ArraySequence<int> a(test_arr, 15);
			seq = &a;
			q.sort(seq);
			bool res = true;
			for (int i = 0; i < 15; i++)
				if (abs(a.Get(i) - result_arr[i]) > 0.00000001) {
					res = false;
					break;
				}
			Assert::IsTrue(res, L"ShellSort Array Integer not work");
		}

		TEST_METHOD(SSListInt)
		{
			Sequence<int>* seq;
			ShakerSorter<int> q;
			int test_arr[15] = { -15, -98, 0, 325, 628, 9, -7, 35, 16, -54, 1, 42, -1, 900, 2 };
			int result_arr[15] = { -98, -54, -15, -7, -1, 0, 1, 2, 9, 16, 35, 42, 325, 628, 900 };
			ListSequence<int> a(test_arr, 15);
			seq = &a;
			q.sort(seq);
			bool res = true;
			for (int i = 0; i < 15; i++)
				if (abs(a.Get(i) - result_arr[i]) > 0.00000001) {
					res = false;
					break;
				}
			Assert::IsTrue(res, L"Shakersort List Integer not work");
		}

		TEST_METHOD(ISListInt)
		{
			Sequence<int>* seq;
			InsertionSorter<int> q;
			int test_arr[15] = { -15, -98, 0, 325, 628, 9, -7, 35, 16, -54, 1, 42, -1, 900, 2 };
			int result_arr[15] = { -98, -54, -15, -7, -1, 0, 1, 2, 9, 16, 35, 42, 325, 628, 900 };
			ListSequence<int> a(test_arr, 15);
			seq = &a;
			q.sort(seq);
			bool res = true;
			for (int i = 0; i < 15; i++)
				if (abs(a.Get(i) - result_arr[i]) > 0.00000001) {
					res = false;
					break;
				}
			Assert::IsTrue(res, L"insertionSort List Integer not work");
		}

		TEST_METHOD(ShellSListInt)
		{
			Sequence<int>* seq;
			ShellSorter<int> q;
			int test_arr[15] = { -15, -98, 0, 325, 628, 9, -7, 35, 16, -54, 1, 42, -1, 900, 2 };
			int result_arr[15] = { -98, -54, -15, -7, -1, 0, 1, 2, 9, 16, 35, 42, 325, 628, 900 };
			ListSequence<int> a(test_arr, 15);
			seq = &a;
			q.sort(seq);
			bool res = true;
			for (int i = 0; i < 15; i++)
				if (abs(a.Get(i) - result_arr[i]) > 0.00000001) {
					res = false;
					break;
				}
			Assert::IsTrue(res, L"ShellSort List Integer not work");
		}

		TEST_METHOD(SSArrayFloat)
		{
			Sequence<float>* seq;
			ShakerSorter<float> q;
			float test_arr[15] = { -61.4, -98.25, 0.12, 32.38, 628, 8.7, -7.89, 35, 16.54, -54.3, 1.002, 42.7, -1, 900.99999, 2.0981 };
			float result_arr[15] = { -98.25, -61.4, -54.3, -7.89, -1,  0.12, 1.002, 2.0981, 8.7, 16.54, 32.38, 35, 42.7, 628, 900.99999 };
			ArraySequence<float> a(test_arr, 15);
			seq = &a;
			q.sort(seq);
			bool res = true;
			for (int i = 0; i < 15; i++)
				if (abs(a.Get(i) - result_arr[i]) > 0.00000001) {
					res = false;
					break;
				}
			Assert::IsTrue(res, L"Shakersort Array Float not work");
		}

		TEST_METHOD(SSListFloat)
		{
			Sequence<float>* seq;
			ShakerSorter<float> q;
			float test_arr[15] = { -61.4, -98.25, 0.12, 32.38, 628, 8.7, -7.89, 35, 16.54, -54.3, 1.002, 42.7, -1, 900.99999, 2.0981 };
			float result_arr[15] = { -98.25, -61.4, -54.3, -7.89, -1,  0.12, 1.002, 2.0981, 8.7, 16.54, 32.38, 35, 42.7, 628, 900.99999 };
			ListSequence<float> a(test_arr, 15);
			seq = &a;
			q.sort(seq);
			bool res = true;
			for (int i = 0; i < 15; i++)
				if (abs(a.Get(i) - result_arr[i]) > 0.00000001) {
					res = false;
					break;
				}
			Assert::IsTrue(res, L"Shakersort List Float not work");
		}
		TEST_METHOD(ISArrayFloat)
		{
			Sequence<float>* seq;
			InsertionSorter<float> q;
			float test_arr[15] = { -61.4, -98.25, 0.12, 32.38, 628, 8.7, -7.89, 35, 16.54, -54.3, 1.002, 42.7, -1, 900.99999, 2.0981 };
			float result_arr[15] = { -98.25, -61.4, -54.3, -7.89, -1,  0.12, 1.002, 2.0981, 8.7, 16.54, 32.38, 35, 42.7, 628, 900.99999 };
			ArraySequence<float> a(test_arr, 15);
			seq = &a;
			q.sort(seq);
			bool res = true;
			for (int i = 0; i < 15; i++)
				if (abs(a.Get(i) - result_arr[i]) > 0.00000001) {
					res = false;
					break;
				}
			Assert::IsTrue(res, L"Insertionsort Array Float not work");
		}

		TEST_METHOD(ShellSArrayFloat)
		{
			Sequence<float>* seq;
			ShellSorter<float> q;
			float test_arr[15] = { -61.4, -98.25, 0.12, 32.38, 628, 8.7, -7.89, 35, 16.54, -54.3, 1.002, 42.7, -1, 900.99999, 2.0981 };
			float result_arr[15] = { -98.25, -61.4, -54.3, -7.89, -1,  0.12, 1.002, 2.0981, 8.7, 16.54, 32.38, 35, 42.7, 628, 900.99999 };
			ArraySequence<float> a(test_arr, 15);
			seq = &a;
			q.sort(seq);
			bool res = true;
			for (int i = 0; i < 15; i++)
				if (abs(a.Get(i) - result_arr[i]) > 0.00000001) {
					res = false;
					break;
				}
			Assert::IsTrue(res, L"Shellsort Array Float not work");
		}

		TEST_METHOD(ISListFloat)
		{
			Sequence<float>* seq;
			InsertionSorter<float> q;
			float test_arr[15] = { -61.4, -98.25, 0.12, 32.38, 628, 8.7, -7.89, 35, 16.54, -54.3, 1.002, 42.7, -1, 900.99999, 2.0981 };
			float result_arr[15] = { -98.25, -61.4, -54.3, -7.89, -1,  0.12, 1.002, 2.0981, 8.7, 16.54, 32.38, 35, 42.7, 628, 900.99999 };
			ListSequence<float> a(test_arr, 15);
			seq = &a;
			q.sort(seq);
			bool res = true;
			for (int i = 0; i < 15; i++)
				if (abs(a.Get(i) - result_arr[i]) > 0.00000001) {
					res = false;
					break;
				}
			Assert::IsTrue(res, L"Insertionsort List Float not work");
		}

		TEST_METHOD(ShellSListFloat)
		{
			Sequence<float>* seq;
			ShellSorter<float> q;
			float test_arr[15] = { -61.4, -98.25, 0.12, 32.38, 628, 8.7, -7.89, 35, 16.54, -54.3, 1.002, 42.7, -1, 900.99999, 2.0981 };
			float result_arr[15] = { -98.25, -61.4, -54.3, -7.89, -1,  0.12, 1.002, 2.0981, 8.7, 16.54, 32.38, 35, 42.7, 628, 900.99999 };
			ListSequence<float> a(test_arr, 15);
			seq = &a;
			q.sort(seq);
			bool res = true;
			for (int i = 0; i < 15; i++)
				if (abs(a.Get(i) - result_arr[i]) > 0.00000001) {
					res = false;
					break;
				}
			Assert::IsTrue(res, L"Shellsort List Float not work");
		}
	};
}
