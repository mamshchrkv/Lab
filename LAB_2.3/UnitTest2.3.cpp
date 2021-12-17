#include "pch.h"
#include "CppUnitTest.h"
#include <stdlib.h>
#include <iostream>
#include"C:\Users\я\source\repos\LAB_2.3\LAB_2.3\Graph.h"
#include"C:\Users\я\source\repos\LAB_2.3\LAB_2.3\FunctionGraph.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest3
{
	TEST_CLASS(UnitTest3)
	{
	public:

		TEST_METHOD(GetIndexWeight)
		{
			int start[10] = { 1,1,2,3,3,4,5,5,6,6 };
			int end[10] = { 2,3,3,4,5,2,6,2,5,1 };
			int weight[10] = { 10,2,1,1,2,3,1,1,6,4 };
			Graph<int, int> graph;
			for (int i = 0; i < 10; i++) {
				graph.Add(start[i], weight[i], end[i]);
			}
			bool res = true;
			int index = graph.GetIndexWeight(10);
			if (index != 0)
				res = false;
			Assert::IsTrue(res, L"Method GetIndexWeight works no correct");
		}

		TEST_METHOD(GetIndexTopsHelp)
		{
			int start[10] = { 1,1,2,3,3,4,5,5,6,6 };
			int end[10] = { 2,3,3,4,5,2,6,2,5,1 };
			int weight[10] = { 10,2,1,1,2,3,1,1,6,4 };
			Graph<int, int> graph;
			for (int i = 0; i < 10; i++) {
				graph.Add(start[i], weight[i], end[i]);
			}
			bool res = true;
			int* index = graph.GetIndexTopsHelp(2, 3);
			if (index[0] != 2)
				res = false;
			Assert::IsTrue(res, L"Method GetIndexTopsHelp works no correct");
		}

		TEST_METHOD(GetNumTop)
		{
			int start[10] = { 1,1,2,3,3,4,5,5,6,6 };
			int end[10] = { 2,3,3,4,5,2,6,2,5,1 };
			int weight[10] = { 10,2,1,1,2,3,1,1,6,4 };
			Graph<int, int> graph;
			for (int i = 0; i < 10; i++) {
				graph.Add(start[i], weight[i], end[i]);
			}
			bool res = true;
			int num = graph.GetNumTop(6, 1);
			if (num != 1)
				res = false;
			Assert::IsTrue(res, L"Method GetNumTop works no correct");
		}

		TEST_METHOD(GetIndex)
		{
			int start[10] = { 1,1,2,3,3,4,5,5,6,6 };
			int end[10] = { 2,3,3,4,5,2,6,2,5,1 };
			int weight[10] = { 10,2,1,1,2,3,1,1,6,4 };
			Graph<int, int> graph;
			for (int i = 0; i < 10; i++) {
				graph.Add(start[i], weight[i], end[i]);
			}
			bool res = true;
			int num = graph.GetIndex(4, 2);
			if (num != 5)
				res = false;
			Assert::IsTrue(res, L"Method GetIndex works no correct");
		}

		TEST_METHOD(ContainsEdge)
		{
			int start[10] = { 1,1,2,3,3,4,5,5,6,6 };
			int end[10] = { 2,3,3,4,5,2,6,2,5,1 };
			int weight[10] = { 10,2,1,1,2,3,1,1,6,4 };
			Graph<int, int> graph;
			for (int i = 0; i < 10; i++) {
				graph.Add(start[i], weight[i], end[i]);
			}
			bool res = true;
			bool edge = graph.ContainsEdge(1, 4);
			if (edge)
				res = false;
			Assert::IsTrue(res, L"Method ContainsEdge works no correct");
		}

		TEST_METHOD(ContainsTop)
		{
			int start[10] = { 1,1,2,3,3,4,5,5,6,6 };
			int end[10] = { 2,3,3,4,5,2,6,2,5,1 };
			int weight[10] = { 10,2,1,1,2,3,1,1,6,4 };
			Graph<int, int> graph;
			for (int i = 0; i < 10; i++) {
				graph.Add(start[i], weight[i], end[i]);
			}
			bool res = true;
			bool edge = graph.ContainsTop(3);
			if (!edge)
				res = false;
			Assert::IsTrue(res, L"Method ContainsTop works no correct");
		}

		TEST_METHOD(GetNumTops)
		{
			int start[10] = { 1,1,2,3,3,4,5,5,6,6 };
			int end[10] = { 2,3,3,4,5,2,6,2,5,1 };
			int weight[10] = { 10,2,1,1,2,3,1,1,6,4 };
			Graph<int, int> graph;
			for (int i = 0; i < 10; i++) {
				graph.Add(start[i], weight[i], end[i]);
			}
			bool res = true;
			int num = graph.GetNumTops();
			if (num != 6)
				res = false;
			Assert::IsTrue(res, L"Method GetNumTops works no correct");
		}

		TEST_METHOD(GetTops)
		{
			int start[10] = { 1,1,2,3,3,4,5,5,6,6 };
			int end[10] = { 2,3,3,4,5,2,6,2,5,1 };
			int weight[10] = { 10,2,1,1,2,3,1,1,6,4 };
			int tops[6] = { 1,2,3,4,5,6 };
			Graph<int, int> graph;
			for (int i = 0; i < 10; i++) {
				graph.Add(start[i], weight[i], end[i]);
			}
			bool res = true;
			int* num = graph.GetTops();
			for (int i = 0; i < 6; i++) {
				if (num[i] != tops[i]) {
					res = false;
					break;
				}
			}
			Assert::IsTrue(res, L"Method GetTops works no correct");
		}

		TEST_METHOD(find)
		{
			int start[10] = { 1,1,2,3,3,4,5,5,6,6 };
			int end[10] = { 2,3,3,4,5,2,6,2,5,1 };
			int weight[10] = { 10,2,1,1,2,3,1,1,6,4 };
			Graph<int, int> graph;
			for (int i = 0; i < 10; i++) {
				graph.Add(start[i], weight[i], end[i]);
			}
			bool res = true;
			int num = graph.find(6, 5);
			if (num != 6)
				res = false;
			Assert::IsTrue(res, L"Method find works no correct");
		}

		TEST_METHOD(Matrix)
		{
			int start[10] = { 1,1,2,3,3,4,5,5,6,6 };
			int end[10] = { 2,3,3,4,5,2,6,2,5,1 };
			int weight[10] = { 10,2,1,1,2,3,1,1,6,4 };
			int mat[6][6] = { {0,10,2,0,0,0}, {0,0,1,0,0,0}, {0,0,0,1,2,0},{0,3,0,0,0,0},{0,1,0,0,0,1}, {4, 0, 0, 0, 6, 0} };
			Graph<int, int> graph;
			for (int i = 0; i < 10; i++) {
				graph.Add(start[i], weight[i], end[i]);
			}
			bool res = true;
			int** matrix = graph.Matrix();
			for (int i = 0; i < graph.GetNumTops(); i++) {
				for (int j = 0; j < graph.GetNumTops(); j++) {
					if (matrix[i][j] != mat[i][j])
						res = false;
				}
			}

			Assert::IsTrue(res, L"Method Matrix works no correct");
		}

		TEST_METHOD(Min_way)
		{
			int start[10] = { 1,1,2,3,3,4,5,5,6,6 };
			int end[10] = { 2,3,3,4,5,2,6,2,5,1 };
			int weight[10] = { 10,2,1,1,2,3,1,1,6,4 };
			Graph<int, int> graph;
			for (int i = 0; i < 10; i++) {
				graph.Add(start[i], weight[i], end[i]);
			}
			bool res = true;
			int* min_way = find_min_way(graph, 1, 2);
			int result[4] = { 1,3,4,2 };
			for (int i = 0; i < 4; i++) {
				if (min_way[i] != result[i])
					res = false;
			}
			Assert::IsTrue(res, L"Method GetNumTops works no correct");
		}
	};
}

