// LAB_2.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include "Graph.h"
#include "FunctionGraph.h"
#include "MakeGraph.h"
int main(){

    int type = 0;
    while (type != 3) {
        cout << "Choice type:\n" << "1. Oriented graph\n" << "2. Undirected graph\n"<<"3. Exit\n";
        cin >> type;
        if (type != 1 && type != 2 && type != 3)
            cout << "Incorrect choice! Try again" << endl;
        switch (type) {
        case 1: {
            cout << "Generate random graph?\n" << "1. Yes\n" << "2. No\n" << endl;
            int choice;
            cin >> choice;
            switch (choice) {
            case 1: {
                Graph<int, int> oriented_graph = make_oriented_graph_random();
                cout << "Choice task:\n" << "1. Adjacency matrix\n" << "2. Finding the shortest path\n" << "3. Print edges\n";
                cin >> type;
                switch (type) {
                case 1: {
                    int** matrix = oriented_graph.Matrix();
                    int* tops = oriented_graph.GetTops();
                    for (int i = 0; i < oriented_graph.GetNumTops(); i++) {
                        if (i != oriented_graph.GetNumTops() - 1)
                            cout << tops[i] << "   ";
                        else
                            cout << tops[i] << endl;
                    }
                    cout << "-----------------------------------" << endl;
                    for (int i = 0; i < oriented_graph.GetNumTops(); i++) {
                        for (int j = 0; j < oriented_graph.GetNumTops(); j++) {
                            if (j == oriented_graph.GetNumTops() - 1)
                                cout << matrix[i][j] << endl;
                            else
                                cout << matrix[i][j] << "   ";
                        }
                    }
                    break;
                }
                case 2: {
                    int start, end;
                    cout << "Enter the beginning of the path:\n";
                    cin >> start;
                    cout << "Enter the end of the path:\n";
                    cin >> end;
                    int* min_way = find_min_way(oriented_graph, start, end);
                    break;
                }
                case 3: {
                    oriented_graph.Print();
                    break;
                }
                      break;
                }
            }
            case 2: {
                Graph<int, int> oriented_graph = make_oriented_graph();
                cout << "Choice task:\n" << "1. Adjacency matrix\n" << "2. Finding the shortest path\n" << "3. Print edges\n";
                cin >> type;
                switch (type) {

                case 1: {
                    int** matrix = oriented_graph.Matrix();
                    int* tops = oriented_graph.GetTops();
                    for (int i = 0; i < oriented_graph.GetNumTops(); i++) {
                        if (i != oriented_graph.GetNumTops() - 1)
                            cout << tops[i] << "   ";
                        else
                            cout << tops[i] << endl;
                    }
                    cout << "-----------------------------------" << endl;
                    for (int i = 0; i < oriented_graph.GetNumTops(); i++) {
                        for (int j = 0; j < oriented_graph.GetNumTops(); j++) {
                            if (j == oriented_graph.GetNumTops() - 1)
                                cout << matrix[i][j] << endl;
                            else
                                cout << matrix[i][j] << "   ";
                        }
                    }
                    break;
                }

                case 2: {
                    int start, end;
                    cout << "Enter the beginning of the path:\n";
                    cin >> start;
                    cout << "Enter the end of the path:\n";
                    cin >> end;
                    int* min_way = find_min_way(oriented_graph, start, end);
                    break;
                }

                case 3: {
                    oriented_graph.Print();
                    break;
                }
                      break;
                }
            }
                  break;
            }
        }

        case 2: {
            cout << "Generate random graph?\n" << "1. Yes\n" << "2. No\n" << endl;
            int choice;
            cin >> choice;
            switch (choice) {
            case 1: {
                Graph<int, int> undirected_graph = make_undirected_graph_random();
                cout << "Choice task:\n" << "1. Adjacency matrix\n" << "2. Finding the shortest path\n" << "3. Print edges\n";
                cin >> type;
                switch (type) {
                case 1: {
                    int** matrix = undirected_graph.Matrix();
                    int* tops = undirected_graph.GetTops();
                    for (int i = 0; i < undirected_graph.GetNumTops(); i++) {
                        if (i != undirected_graph.GetNumTops() - 1)
                            cout << tops[i] << "   ";
                        else
                            cout << tops[i] << endl;
                    }
                    cout << "-----------------------------------" << endl;
                    for (int i = 0; i < undirected_graph.GetNumTops(); i++) {
                        for (int j = 0; j < undirected_graph.GetNumTops(); j++) {
                            if (j == undirected_graph.GetNumTops() - 1)
                                cout << matrix[i][j] << endl;
                            else
                                cout << matrix[i][j] << "   ";
                        }
                    }
                    break;
                }
                case 2: {
                    int start, end;
                    cout << "Enter the beginning of the path:\n";
                    cin >> start;
                    cout << "Enter the end of the path:\n";
                    cin >> end;
                    int* min_way = find_min_way(undirected_graph, start, end);
                    break;
                }
                case 3: {
                    undirected_graph.Print();
                    break;
                }
                      break;
                }
            }
            case 2: {
                Graph<int, int> undirected_graph = make_undirected_graph();
                cout << "Choice task:\n" << "1. Adjacency matrix\n" << "2. Finding the shortest path\n" << "3. Print edges\n";
                cin >> type;
                switch (type) {

                case 1: {
                    int** matrix = undirected_graph.Matrix();
                    int* tops = undirected_graph.GetTops();
                    for (int i = 0; i < undirected_graph.GetNumTops(); i++) {
                        if (i != undirected_graph.GetNumTops() - 1)
                            cout << tops[i] << "   ";
                        else
                            cout << tops[i] << endl;
                    }
                    cout << "-----------------------------------" << endl;
                    for (int i = 0; i < undirected_graph.GetNumTops(); i++) {
                        for (int j = 0; j < undirected_graph.GetNumTops(); j++) {
                            if (j == undirected_graph.GetNumTops() - 1)
                                cout << matrix[i][j] << endl;
                            else
                                cout << matrix[i][j] << "   ";
                        }
                    }
                    break;
                }

                case 2: {
                    int start, end;
                    cout << "Enter the beginning of the path:\n";
                    cin >> start;
                    cout << "Enter the end of the path:\n";
                    cin >> end;
                    int* min_way = find_min_way(undirected_graph, start, end);
                    break;
                }

                case 3: {
                    undirected_graph.Print();
                    break;
                }
                      break;
                }
            }
                  break;
            }
        }
    }
    }
} 