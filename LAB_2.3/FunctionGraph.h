#pragma once
#include <iostream>
#include <stdio.h>
#include "Graph.h"

template<typename TT, typename TW>
TT* find_min_way(Graph<TT, TW> graph, TT start_way, TT end_way) {
    TT** road = new TT*[graph.GetNumTops()* graph.GetNumTops()]; //номера узлов которые были слиты в один
    int num_united_tops = 0;//количество слитых вершин
    int* num_road = new int[graph.GetNumTops()]; //количество дорог
    int old_size= graph.GetSizeEdge();

    //сливаем два ребра в одно если конец первого ребра является началом второго
    //запоминаем количество дорог и прошедшие вершины в массивах
    for (int search_start = 0; search_start <  graph.GetSizeEdge(); search_start++) {
        if (graph[search_start]->start == start_way && graph[search_start]->end!=end_way) {
            for (int search_end = 0; search_end < graph.GetSizeEdge(); search_end++) {
                if (graph[search_start]->end == graph[search_end]->start && 
                    graph[search_end]->end!= graph[search_start]->start && search_end<old_size && search_start < old_size) {
                    graph.Add(graph[search_start]->start, graph[search_start]->weight + graph[search_end]->weight,
                        graph[search_end]->end);
                    road[num_united_tops] = new TT[100];
                    road[num_united_tops][0] = graph[search_start]->start;
                    road[num_united_tops][1] = graph[search_start]->end;
                    road[num_united_tops][2] = graph[search_end]->end;
                    num_road[num_united_tops] = 3;
                    num_united_tops = num_united_tops + 1;
                }
                else if (graph[search_start]->end == graph[search_end]->start && graph[search_end]->end != graph[search_start]->start && search_start >= old_size) {
                    graph[search_start]->end = graph[search_end]->end;
                    road[search_start - old_size][num_road[search_start - old_size]]= graph[search_end]->end;
                    graph[search_start]->weight = graph[search_start]->weight + graph[search_end]->weight;
                    num_road[search_start - old_size] = num_road[search_start - old_size] + 1;
                    num_united_tops = num_united_tops + 1;
                }
            }
        }
    }
    int num_index_ways = graph.GetNumTop(start_way, end_way);//количество элементов с нужными началом и концом
    if (num_index_ways == 0) {
        cout << "There is no road"<<endl;
        TT* min_way = new TT[1];
        min_way[0] = 0;
        return min_way;
    }
    int* index_ways = graph.GetIndexTopsHelp(start_way, end_way);//Список индексов с нужными началом и концом
    TW min_len = graph[index_ways[0]]->weight;//присваиваем минимальной длине вес первого нужного пути
    int index_min = index_ways[0];
    int index = 0;
    for (int count = 0; count < num_index_ways -1; count++) {
        index = index_ways[count + 1];
        if (graph[index]->weight < min_len) {
            index_min = index;
            min_len = graph[index]->weight;
        }
    }
   // graph.Print();
    //нашли минимальную длину и индекс который соответствует в графе этому пути
    TT* min_way = new TT[num_road[index_min - old_size]];
    if (index_min < old_size) {
        min_way[0] = graph[index_min]->start;
        min_way[1] = graph[index_min]->end;
        cout << "Way:" << graph[index_min]->start << "-" << graph[index_min]->end<<endl;
        cout << "Weight:" << graph[index_min]->weight << endl;
    }
    else if (index_min >= old_size) {
        cout << "Way:";
        for (int i = 0; i < num_road[index_min - old_size]; i++) {
            if (i == num_road[index_min - old_size] - 1) {
                min_way[i] = road[index_min - old_size][i];
                cout << road[index_min - old_size ][i] << endl;
            }
            else {
                min_way[i] = road[index_min - old_size][i];
                cout << road[index_min - old_size][i] << "-";
            }
        }
        cout << "Weight:" << graph[index_min]->weight << endl;
    }
    return min_way;
}