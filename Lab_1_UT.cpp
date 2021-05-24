#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab1UT
{
	TEST_CLASS(Lab1UT)
	{
	public:
		
		TEST_METHOD(PF_printZ)
		{
			// 1. Данные необходимые для теста
			vector* vec = create(sizeof(int));
			initialize(vec);

			int arr[3] = { 1, 2, 3 };
			push(vec, arr, 3, sizeof(int));

			char constMsg[500] = "1 + 2*X1 + 3*X2\n";

			// 2. Вызов тестового метода
			const char* msg = printZ(vec);

			// 3. Проверка результата
			bool res = true;
			for(int i = 0; i < strlen(constMsg) - 1; i++)
				if (constMsg[i] != msg[i])
				{
					res = false;
					break;
				}

			Assert::IsTrue(res, L"printZ not work");
		}
		TEST_METHOD(PF_printR)
		{
			// 1. Данные необходимые для теста
			vector* vec = create(sizeof(double));
			initialize(vec);

			double arr[3] = { 1.45, 2.56, 3.87 };
			push(vec, arr, 3, sizeof(double));

			char constMsg[500] = "1.450000 + 2.560000*X1 + 3.870000*X2\n";

			// 2. Вызов тестового метода
			const char* msg = printR(vec);

			// 3. Проверка результата
			bool res = true;
			for (int i = 0; i < strlen(constMsg) - 1; i++)
				if (constMsg[i] != msg[i])
				{
					res = false;
					break;
				}
			
			Assert::IsTrue(res, L"printR not work");
		}

		TEST_METHOD(PF_sumZ_eq)
		{
			// 1. Данные необходимые для теста
			vector* vec1 = create(sizeof(int));
			initialize(vec1);

			int arr1[3] = { 1, 2, 3 };
			push(vec1, arr1, 3, sizeof(int));

			vector* vec2 = create(sizeof(int));
			initialize(vec2);

			int arr2[3] = { -1, 2, 3 };
			push(vec2, arr2, 3, sizeof(int));

			vector* vec3 = create(sizeof(int));
			initialize(vec3);

			int arr3[3] = { 0, 4, 6 };
			push(vec3, arr3, 3, sizeof(int));

			// 2. Вызов тестового метода
			vector* resVec = sumZ(vec1, vec2);

			// 3. Проверка результата
			bool res = true;
			for (int i = 0; i < 3; i++)
				if (*((int*)(vec3->head) + i) != *((int*)(resVec->head) + i))
				{
					res = false;
					break;
				}

			Assert::IsTrue(res, L"sumZ_eq not work");
		}
		TEST_METHOD(PF_sumR_eq)
		{
			// 1. Данные необходимые для теста
			vector* vec1 = create(sizeof(double));
			initialize(vec1);

			double arr1[3] = { 1.6, 2.8, 3.9 };
			push(vec1, arr1, 3, sizeof(double));

			vector* vec2 = create(sizeof(double));
			initialize(vec2);

			double arr2[3] = { 1.5, 2.7, 3.8 };
			push(vec2, arr2, 3, sizeof(double));
			const double e = 0.000001;

			vector* vec3 = create(sizeof(double));
			initialize(vec3);

			double arr3[3] = { 3.100000, 5.500000, 7.700000 };
			push(vec3, arr3, 3, sizeof(double));

			// 2. Вызов тестового метода
			vector* resVec = sumR(vec1, vec2);

			// 3. Проверка результата
			bool res = true;
			for (int i = 0; i < 3; i++)
				if (abs(*((double*)(vec3->head) + i) - *((double*)(resVec->head) + i))>e)
				{
					res = false;
					break;
				}

			Assert::IsTrue(res, L"sumR_eq not work");
		}
		TEST_METHOD(PF_sumZ_2big)
		{
			// 1. Данные необходимые для теста
			vector* vec1 = create(sizeof(int));
			initialize(vec1);

			int arr1[3] = { 1, 2, 3 };
			push(vec1, arr1, 3, sizeof(int));

			vector* vec2 = create(sizeof(int));
			initialize(vec2);

			int arr2[4] = { 1, 2, 3, 4 };
			push(vec2, arr2, 4, sizeof(int));

			vector* vec3 = create(sizeof(int));
			initialize(vec3);

			int arr3[4] = { 2, 4, 6, 4 };
			push(vec3, arr3, 4, sizeof(int));

			// 2. Вызов тестового метода
			vector* resVec = sumZ(vec1, vec2);

			// 3. Проверка результата
			bool res = true;
			for (int i = 0; i < 4; i++)
				if (*((int*)(vec3->head) + i) != *((int*)(resVec->head) + i))
				{
					res = false;
					break;
				}

			Assert::IsTrue(res, L"sumZ_2big not work");
		}
		TEST_METHOD(PF_sumZ_1big)
		{
			// 1. Данные необходимые для теста
			vector* vec2 = create(sizeof(int));
			initialize(vec2);

			int arr2[3] = { 1, 2, 3 };
			push(vec2, arr2, 3, sizeof(int));

			vector* vec1 = create(sizeof(int));
			initialize(vec1);

			int arr1[4] = { 1, 2, 3, 4 };
			push(vec1, arr1, 4, sizeof(int));

			vector* vec3 = create(sizeof(int));
			initialize(vec3);

			int arr3[4] = { 2, 4, 6, 4 };
			push(vec3, arr3, 4, sizeof(int));

			// 2. Вызов тестового метода
			vector* resVec = sumZ(vec1, vec2);

			// 3. Проверка результата
			bool res = true;
			for (int i = 0; i < 4; i++)
				if (*((int*)(vec3->head) + i) != *((int*)(resVec->head) + i))
				{
					res = false;
					break;
				}

			Assert::IsTrue(res, L"sumZ_1big not work");
		}
		TEST_METHOD(PF_sumR_1big)
		{
			// 1. Данные необходимые для теста
			vector* vec1 = create(sizeof(double));
			initialize(vec1);

			double arr1[4] = { 1.6, 2.8, 3.9, 5.7 };
			push(vec1, arr1, 4, sizeof(double));

			vector* vec2 = create(sizeof(double));
			initialize(vec2);

			double arr2[3] = { 1.5, 2.7, 3.8 };
			push(vec2, arr2, 3, sizeof(double));
			const double e = 0.000001;

			vector* vec3 = create(sizeof(double));
			initialize(vec3);

			double arr3[4] = { 3.100000, 5.500000, 7.700000, 5.700000 };
			push(vec3, arr3, 4, sizeof(double));

			// 2. Вызов тестового метода
			vector* resVec = sumR(vec1, vec2);

			// 3. Проверка результата
			bool res = true;
			for (int i = 0; i < 4; i++)
				if (abs(*((double*)(vec3->head) + i) - *((double*)(resVec->head) + i))>e)
				{
					res = false;
					break;
				}

			Assert::IsTrue(res, L"sumR_1big not work");
		}
		TEST_METHOD(PF_sumR_2big)
		{
			// 1. Данные необходимые для теста
			vector* vec2 = create(sizeof(double));
			initialize(vec2);

			double arr2[4] = { 1.6, 2.8, 3.9, 5.7 };
			push(vec2, arr2, 4, sizeof(double));

			vector* vec1 = create(sizeof(double));
			initialize(vec1);

			double arr1[3] = { 1.5, 2.7, 3.8 };
			push(vec1, arr1, 3, sizeof(double));

			vector* vec3 = create(sizeof(double));
			initialize(vec3);
			const double e = 0.000001;

			double arr3[4] = { 3.100000, 5.500000, 7.700000, 5.700000 };
			push(vec3, arr3, 4, sizeof(double));

			// 2. Вызов тестового метода
			vector* resVec = sumR(vec1, vec2);

			// 3. Проверка результата
			bool res = true;
			for (int i = 0; i < 4; i++)
				if (abs((*((double*)(vec3->head) + i) - *((double*)(resVec->head) + i)))>e)
				{
					res = false;
					break;
				}

			Assert::IsTrue(res, L"sumR_2big not work");
		}
		TEST_METHOD(PF_subZ_2big)
		{
			// 1. Данные необходимые для теста
			vector* vec1 = create(sizeof(int));
			initialize(vec1);

			int arr1[3] = { 2, 4, 9 };
			push(vec1, arr1, 3, sizeof(int));

			vector* vec2 = create(sizeof(int));
			initialize(vec2);

			int arr2[4] = { 1, 2, 3, 4 };
			push(vec2, arr2, 4, sizeof(int));

			vector* vec3 = create(sizeof(int));
			initialize(vec3);

			int arr3[4] = { 1, 2, 6, -4 };
			push(vec3, arr3, 4, sizeof(int));

			// 2. Вызов тестового метода
			vector* resVec = subZ(vec1, vec2);

			// 3. Проверка результата
			bool res = true;
			for (int i = 0; i < 4; i++)
				if (*((int*)(vec3->head) + i) != *((int*)(resVec->head) + i))
				{
					res = false;
					break;
				}

			Assert::IsTrue(res, L"subZ_2big not work");
		}
		TEST_METHOD(PF_subZ_1big)
		{
			// 1. Данные необходимые для теста
			vector* vec2 = create(sizeof(int));
			initialize(vec2);

			int arr2[3] = { 2, 4, 9 };
			push(vec2, arr2, 3, sizeof(int));

			vector* vec1 = create(sizeof(int));
			initialize(vec1);

			int arr1[4] = { 1, 2, 3, 4 };
			push(vec1, arr1, 4, sizeof(int));

			vector* vec3 = create(sizeof(int));
			initialize(vec3);

			int arr3[4] = { -1, -2, -6, 4 };
			push(vec3, arr3, 4, sizeof(int));

			// 2. Вызов тестового метода
			vector* resVec = subZ(vec1, vec2);

			// 3. Проверка результата
			bool res = true;
			for (int i = 0; i < 4; i++)
				if (*((int*)(vec3->head) + i) != *((int*)(resVec->head) + i))
				{
					res = false;
					break;
				}

			Assert::IsTrue(res, L"subZ_1big not work");
		}
		TEST_METHOD(PF_subZ_eq)
		{
			// 1. Данные необходимые для теста
			vector* vec2 = create(sizeof(int));
			initialize(vec2);

			int arr2[3] = { 2, 4, 9 };
			push(vec2, arr2, 3, sizeof(int));

			vector* vec1 = create(sizeof(int));
			initialize(vec1);

			int arr1[3] = { 1, 2, 11};
			push(vec1, arr1, 3, sizeof(int));

			vector* vec3 = create(sizeof(int));
			initialize(vec3);

			int arr3[3] = { -1, -2, 2 };
			push(vec3, arr3, 3, sizeof(int));

			// 2. Вызов тестового метода
			vector* resVec = subZ(vec1, vec2);

			// 3. Проверка результата
			bool res = true;
			for (int i = 0; i < 3; i++)
				if (*((int*)(vec3->head) + i) != *((int*)(resVec->head) + i))
				{
					res = false;
					break;
				}

			Assert::IsTrue(res, L"subZ_eq not work");
		}
		TEST_METHOD(PF_ScalarZ)
		{
			// 1. Данные необходимые для теста
			vector* vec1 = create(sizeof(int));
			initialize(vec1);

			int arr1[3] = { 1, 2, 3 };
			push(vec1, arr1, 3, sizeof(int));
			const int t = 5;
			vector* vec3 = create(sizeof(int));
			initialize(vec3);

			int arr3[3] = { 5, 10, 15 };
			push(vec3, arr3, 3, sizeof(int));
			vector* resVec = scalarZ(vec1, t);

			bool res = true;
			for (int i = 0; i < 3; i++)
				if (*((int*)(vec3->head) + i) != *((int*)(resVec->head) + i))
				{
					res = false;
					break;
				}

			Assert::IsTrue(res, L"ScalarZ not work");
		}
		TEST_METHOD(PF_ScalarR)
		{
			// 1. Данные необходимые для теста
			vector* vec2 = create(sizeof(double));
			initialize(vec2);

			double arr2[3] = { 1.6, -2.8, 3.9};
			push(vec2, arr2, 3, sizeof(double));
			const double t = 5.1;
			const double e = 0.000001;

			vector* vec3 = create(sizeof(double));
			initialize(vec3);

			double arr3[3] = { 8.160000, -14.280000, 19.890000};
			push(vec3, arr3, 3, sizeof(double));
			vector* resVec = scalarR(vec2, t);

			bool res = true;
			for (int i = 0; i < 3; i++)
				if (abs(*((double*)(vec3->head) + i) - *((double*)(resVec->head) + i))>e)
				{
					res = false;
					break;
				}

			Assert::IsTrue(res, L"ScalarR not work");
		}
		TEST_METHOD(PF_GornerZ)
		{
			// 1. Данные необходимые для теста
			vector* vec1 = create(sizeof(int));
			initialize(vec1);

			int arr1[3] = { 1, -2, 3 };
			push(vec1, arr1, 3, sizeof(int));

			vector* vec2 = create(sizeof(int));
			initialize(vec2);

			int arr2[2] = { 2, 4};
			push(vec2, arr2, 2, sizeof(int));

			const int t = 9;
			int res = gornerZ(vec1, vec2);

			bool k = true;
			if (res != t)
				k = false;
			Assert::IsTrue(k, L"GornerZ not work");
		}
		TEST_METHOD(PF_GornerR)
		{
			// 1. Данные необходимые для теста
			vector* vec1 = create(sizeof(double));
			initialize(vec1);

			double arr1[3] = { 1.6, 2.8, 3.9 };
			push(vec1, arr1, 3, sizeof(double));

			vector* vec2 = create(sizeof(double));
			initialize(vec2);

			double arr2[2] = { 1.5, -2.7 };
			push(vec2, arr2, 2, sizeof(double));

			const double e = 0.000001;
			const double t = -4.73;
			double res = gornerR(vec1, vec2);

			bool k = true;
			if (abs(res - t) > e)
				k = false;
			Assert::IsTrue(k, L"GornerR not work");
		}
	};
}
