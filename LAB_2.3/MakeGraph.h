#pragma once
#include"Graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

Graph<int,int> make_oriented_graph() {
	cout << "Enter the number of edges:\n";
	int size;
	cin >> size;
	int* tops_start = new int[size];
	int* tops_end = new int[size];
	int* weight = new int[size];
	for (int i = 0; i < size; i++) {
		cout << "Enter the starting top:\n";
		cin >> tops_start[i];
		cout << "Enter the ending top:\n";
		cin >> tops_end[i];
		cout << "Enter the weight:\n";
		cin >> weight[i];
	}
	return Graph<int, int>(tops_start, weight, tops_end, size);
}

Graph<int, int> make_oriented_graph_random() {
	cout << "Enter the number of tops:\n";
	int tops;
	srand(time(NULL));
	int num_edge=0;
	cin >> tops;
	int* tops_start = new int[tops*tops-tops];
	int* tops_end = new int[tops*tops-tops];
	int* weight = new int[tops*tops-tops];
	int weight_edge;
	for (int i = 0; i < tops; i++) {
		for (int j = 0; j < tops; j++) {
			if (i != j&&(j+i)%3!=0) {
				weight_edge = rand()%10;
				if (weight_edge!= 0) {
					weight[num_edge] = weight_edge;
					tops_start[num_edge] = i+1;
					tops_end[num_edge] = j+1;
					num_edge++; 
				}
			}
		}
	}
	cout << "Program create graph:" << endl;
	Graph<int, int>(tops_start, weight, tops_end, num_edge).Print();
	return Graph<int, int>(tops_start, weight, tops_end, num_edge);
}

Graph<int, int> make_undirected_graph() {
	cout << "Enter the number of edges:\n";
	int size;
	cin >> size;
	int* tops_start = new int[2*size];
	int* tops_end = new int[2*size];
	int* weight = new int[2*size];
	for (int i = 0; i < 2*size; i=i+2){
		cout << "Enter the starting top:\n";
		cin >> tops_start[i];
		cout << "Enter the ending top:\n";
		cin >> tops_end[i];
		cout << "Enter the weight:\n";
		cin >> weight[i];
		tops_start[i+1]= tops_end[i];
		tops_end[i + 1] = tops_start[i];
		weight[i + 1] = weight[i];
	}
	return Graph<int, int>(tops_start, weight, tops_end, 2*size);
}

Graph<int, int> make_undirected_graph_random() {
	cout << "Enter the number of tops:\n";
	int tops;
	srand(time(NULL));
	int num_edge = 0;
	cin >> tops;
	int* tops_start = new int[tops * tops - tops];
	int* tops_end = new int[tops * tops - tops];
	int* weight = new int[tops * tops - tops];
	int weight_edge;
	for (int i = 0; i < tops; i++) {
		for (int j = 0; j < tops; j++) {
			if (i != j && (j + i) % 3 != 0) {
				weight_edge = rand() % 10;
				if (weight_edge != 0) {
					weight[num_edge] = weight_edge;
					tops_start[num_edge] = i + 1;
					tops_end[num_edge] = j + 1;
					weight[num_edge+1] = weight_edge;
					tops_start[num_edge+1] = j + 1;
					tops_end[num_edge+1] = i + 1;
					num_edge= num_edge+2;
				}
			}
		}
	}
	cout << "Program create graph:" << endl;
	Graph<int, int>(tops_start, weight, tops_end, num_edge).Print();
	return Graph<int, int>(tops_start, weight, tops_end, num_edge);
}