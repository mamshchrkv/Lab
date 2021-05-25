#include "pch.h"
#include "CppUnitTest.h"
#include <stdlib.h>
#include <iostream>
#include <complex>
#include <cmath>

#include"../Lab2/Line.h"
#include"../Lab2/Polinom.h"
#include"../Lab2/Sequence.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:

		TEST_METHOD(SumLD)
		{
			Lineform<double> P1(4);
			Lineform<double> P2(5);
			double d[5] = { -1.8, 9.3, -4.6, -10.12, 16.88 };
			double t[4] = { 1.12, 5.7, 8, -16.25 };
			double s[5] = { -0.68, 15.0, 3.4, -26.37, 16.88 };
			for (int i = 0; i < P1.GetSize(); i++)
				P1.Set(i, t[i]);
			for (int i = 0; i < P2.GetSize(); i++)
				P2.Set(i, d[i]);
			Lineform<double> P3 = P1 + P2;
			bool res = true;
			for (int i = 0; i < 5; i++)
				if (abs(P3.Get(i) - s[i]) > 0.00000001){
					res = false;
					break;
				}
			Assert::IsTrue(res, L"SumLD not work");
		}

		TEST_METHOD(SumLC)
		{
			Lineform<std::complex<double>> P1(4);
			Lineform<std::complex<double>> P2(2);
			std::complex<double> d[4] = { (-1,5), (6,4),(2,-3),(-2.3,1) };
			std::complex<double> t[2] = { (1,12), (-5.7,8) };
			std::complex<double> s[4] = { (0,17), (0.3,12),(2,-3),(-2.3,1) };
			for (int i = 0; i < P1.GetSize(); i++)
				P1.Set(i, d[i]);
			for (int i = 0; i < P2.GetSize(); i++)
				P2.Set(i, t[i]);
			Lineform<std::complex<double>> P3 = P1 + P2;
			bool res = true;
			for (int i = 0; i < 4; i++)
				if (abs(P3.Get(i) - s[i]) > 0.00000001){
					res = false;
					break;
				}
			Assert::IsTrue(res, L"SumLD not work");
		}
		TEST_METHOD(SubLD)
		{
			Lineform<double> P1(6);
			Lineform<double> P2(5);
			double d[5] = { -1.8, 9.3, -4.6, -10.12, 16.88 };
			double t[6] = { 1.12, 5.7, 8, -16.25, 25.31, 2.19 };
			double s[6] = { 2.92, -3.6, 12.6, -6.13, 8.43, 2.19};
			for (int i = 0; i < P1.GetSize(); i++)
				P1.Set(i, t[i]);

			for (int i = 0; i < P2.GetSize(); i++)
				P2.Set(i, d[i]);

			Lineform<double> P3 = P1 - P2;
			bool res = true;

			for (int i = 0; i < 5; i++)
				if (abs(P3.Get(i) - s[i]) > 0.00000001)
				{
					res = false;
					break;
				}

			Assert::IsTrue(res, L"SubLD not work");
		}

		TEST_METHOD(SubLC)
		{
			// 1. Данные необходимые для теста
			Lineform<std::complex<double>> P1(4);
			Lineform<std::complex<double>> P2(2);
			std::complex<double> d[4] = { (-1,5), (6,4),(2,-3),(-2.3,1) };
			std::complex<double> t[2] = { (1,12), (-5.7,8) };
			std::complex<double> s[4] = { (-2,-7), (11.7,-4),(2,-3),(-2.3,1) };
			for (int i = 0; i < P1.GetSize(); i++)
				P1.Set(i, d[i]);

			for (int i = 0; i < P2.GetSize(); i++)
				P2.Set(i, t[i]);

			Lineform<std::complex<double>> P3 = P1 - P2;
			bool res = true;

			for (int i = 0; i < 4; i++)
				if (abs(P3.Get(i) - s[i]) > 0.00000001)
				{
					res = false;
					break;
				}

			Assert::IsTrue(res, L"SumLD not work");
		}

		TEST_METHOD(ScalarLD)
		{
			// 1. Данные необходимые для теста
			Lineform<double> P1(4);
			double h = 8;
			double t[4] = { 1.12, 5.7, 8, -16.25 };
			double s[4] = {8.96, 45.6, 64, -130 };
			for (int i = 0; i < 4; i++)
				P1.Set(i, t[i]);
			Lineform<double> P3 = (P1*=h);
			bool res = true;

			for (int i = 0; i < 4; i++)
				if (abs(P3.Get(i) - s[i]) > 0.00000001)
				{
					res = false;
					break;
				}

			Assert::IsTrue(res, L"ScalarLD not work");
		}


		TEST_METHOD(ValueLD)
		{
			Lineform<double> P1(6);
			Lineform<double> P2(5);
			double d[5] = { 3, -5, 9, 12, -1};
			double t[6] = { 1.12, 5.7, 8, -16.25, 25.31, 2.19 };
			double s = 133.5;
			for (int i = 0; i < P1.GetSize(); i++)
				P1.Set(i, t[i]);
			for (int i = 0; i < P2.GetSize(); i++)
				P2.Set(i, d[i]);
            double b = P1.value(P2);
			bool res = true;
			if (abs(b-s ) > 0.00000001)
			    res = false;

			Assert::IsTrue(res, L"ValuueLDL not work");
		}

		TEST_METHOD(SumPD)
		{
			// 1. Данные необходимые для теста
			Polinomial<double> P1(5);
			Polinomial<double> P2(4);
			double d[5] = { -1.8, 9.3, -4.6, -10.12, 16.88 };
			double t[4] = { 1.12, 5.7, 8, -16.25 };
			double s[5] = { -0.68, 15.0, 3.4, -26.37, 16.88 };
			for (int i = 0; i < P1.GetSize(); i++)
				P1.Set(i, d[i]);

			for (int i = 0; i < P2.GetSize(); i++)
				P2.Set(i, t[i]);

			Polinomial<double> P3 = P1 + P2;
			bool res = true;

			for (int i = 0; i < 5; i++)
				if (abs(P3.Get(i) - s[i]) > 0.00000001)
				{
					res = false;
					break;
				}

			Assert::IsTrue(res, L"SumLD not work");
		}

		TEST_METHOD(SumPC)
		{
			// 1. Данные необходимые для теста
			Polinomial<std::complex<double>> P1(4);
			Polinomial<std::complex<double>> P2(2);
			std::complex<double> d[4] = { (-1,5), (6,4),(2,-3),(-2.3,1) };
			std::complex<double> t[2] = { (1,12), (-5.7,8) };
			std::complex<double> s[4] = { (0,17), (0.3,12),(2,-3),(-2.3,1) };
			for (int i = 0; i < P1.GetSize(); i++)
				P1.Set(i, d[i]);

			for (int i = 0; i < P2.GetSize(); i++)
				P2.Set(i, t[i]);

			Polinomial<std::complex<double>> P3 = P1 + P2;
			bool res = true;

			for (int i = 0; i < 4; i++)
				if (abs(P3.Get(i) - s[i]) > 0.00000001)
				{
					res = false;
					break;
				}

			Assert::IsTrue(res, L"SumLD not work");
		}
		TEST_METHOD(multiplicationP)
		{
			// 1. Данные необходимые для теста
			Polinomial<double> P1(5);
			Polinomial<double> P2(4);
			double d[5] = { -1.8, 9.3, -4.6, -10.12, 16.88 };
			double t[4] = { 1.12, 5.7, 8, -16.25 };
			double s[8] = { -2.016, 0.156, 33.458, 66.0956, -226.7034, 90.006, 299.49, -274.3 };
			for (int i = 0; i < 5; i++)
				P1.Set(i, d[i]);

			for (int i = 0; i < 4; i++)
				P2.Set(i, t[i]);

			Polinomial<double> P3 = P1*P2;
			bool res = true;

			for (int i = 0; i < 8; i++)
				if (abs(P3.Get(i) - s[i]) > 0.00000001)
				{
					res = false;
					break;
				}

			Assert::IsTrue(res, L"SumLD not work");
		}

		TEST_METHOD(compositionP)
		{
			// 1. Данные необходимые для теста
			Polinomial<double> P1(3);
			Polinomial<double> P2(2);
			double d[3] = { -1.8, 9.3, -4.6};
			double t[2] = { 1.12, 5.7 };
			double s[3] = { 2.84576, -5.7228, -149.454};
			for (int i = 0; i < 3; i++)
				P1.Set(i, d[i]);

			for (int i = 0; i < 2; i++)
				P2.Set(i, t[i]);

			Polinomial<double> c = P1.composition(P2);
			bool res = true;

			for (int i = 0; i < 3; i++)
				if (abs(c.Get(i) - s[i]) > 0.00000001)
				{
					res = false;
					break;
				}

			Assert::IsTrue(res, L"compositionP not work");
		}

		TEST_METHOD(ScalarP)
		{
			// 1. Данные необходимые для теста
			Polinomial<double> P1(4);
			double h = 8;
			double t[4] = { 1.12, 5.7, 8, -16.25 };
			double s[4] = { 8.96, 45.6, 64, -130 };
			for (int i = 0; i < 4; i++)
				P1.Set(i, t[i]);
			Polinomial<double> P3 = (P1 *= h);
			bool res = true;

			for (int i = 0; i < 4; i++)
				if (abs(P3.Get(i) - s[i]) > 0.00000001)
				{
					res = false;
					break;
				}

			Assert::IsTrue(res, L"ScalarP not work");
		}

		TEST_METHOD(ValueP)
		{
			// 1. Данные необходимые для теста
			Polinomial<double> P1(4);
			double h = 2.4;
			double t[4] = { 1.12, 5.7, 8, -16.25 };
			double s=-163.76;
			for (int i = 0; i < 4; i++)
				P1.Set(i, t[i]);
			double c = P1.value(h);
			bool res = true;
			if (abs(c - s) > 0.00000001)
					res = false;

			Assert::IsTrue(res, L"ScalarP not work");
		}

		TEST_METHOD(Get)
		{
			// 1. Данные необходимые для теста
			Polinomial<double> P1(4);
			double t[4] = { 1.12, 5.7, 8, -16.25 };
			for (int i = 0; i < 4; i++)
				P1.Set(i, t[i]);
			bool res = true;
			for (int i = 0; i < 4; i++)
				if (abs(P1.Get(i) - t[i]) > 0.00000001)
				{
					res = false;
					break;
				}

			Assert::IsTrue(res, L"Get&Set not work");
		}
	};
}