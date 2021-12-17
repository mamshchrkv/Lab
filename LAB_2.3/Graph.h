#pragma once
#include<iostream>
#include<stdexcept>
using namespace std;

template<typename TT, typename TW>
struct Element {
public:
	TT start;
	TW weight;
	TT end;
};

template<typename TT, typename TW>
class Graph {
private:
	Element<TT, TW>** graph;
	int graph_size;
public:
	Graph() {
		graph = nullptr;
		graph_size = 0;
	}

	Graph(int size) {
		graph_size = size;
		if (size != 0)
			graph = new Element<TT, TW>*[size];
		else
			graph = nullptr;
	}

	Graph(TT* start1, TW* weight1, TT* end1, int size) {
		graph = new Element<TT, TW>*[size];
		graph_size = size;
		for (int i = 0; i < size; i++) {
			Element<TT, TW>* el = new Element<TT, TW>;
			el->start = start1[i];
			el->end = end1[i];
			el->weight = weight1[i];
			graph[i] = &*el;
			//delete el;
		}
	}

	[[nodiscard]] int GetSizeEdge() {
		return graph_size;
	}

	int GetIndexWeight(TW weight) {
		for (int i = 0; i < graph_size; i++) {
			if (graph[i]->weight == weight)
				return i;
		}
		throw out_of_range("index out of range");
	}

	int* GetIndexTopsHelp(TT start, TT end) {
		int num = 0;
		for (int i = 0; i < graph_size; i++) {
			if (graph[i]->start == start && graph[i]->end==end)
				num=num+1;
		}
		int* index = new int[num];
		num = 0;
		for (int i = 0; i < graph_size; i++) {
			if (graph[i]->start == start && graph[i]->end == end) {
				index[num] = i;
				num = num + 1;
			}
		}
		if (num != 0)
			return index;
			throw out_of_range("index out of range");
	}

	int GetNumTop(TT start, TT end) {
		int num = 0;
		for (int i = 0; i < graph_size; i++) {
			if (graph[i]->start == start && graph[i]->end == end)
				num = num + 1;
		}
		return num;
		throw out_of_range("index out of range");
	}


	int GetIndex(TT start, TT end) {
		for (int i = 0; i < graph_size; i++) 
			if (graph[i]->start == start && graph[i]->end == end)
				return i;
		throw out_of_range("index out of range");
	}

	bool ContainsEdge(TT start1, TT end1) {
		for (int i = 0; i < graph_size; i++) {
			if (graph[i]->start == start1 && graph[i]->end == end1)
				return true;
		}
		return false;
	}

	bool ContainsTop(TT top) {
		for (int i = 0; i < graph_size; i++) {
			if (graph[i]->start == top || graph[i]->end == top)
				return true;
		}
		return false;
	}

	int GetNumTops() {
		TT* tops = new TT[graph_size];
		int num = 0;
		bool flag_end = false;
		bool flag_start = false;
		for (int i = 0; i < graph_size; i++) {
			for (int start = 0; start < num; start++) {
				if (tops[start] != graph[i]->start)
					flag_start = false;
				else if (tops[start] == graph[i]->start) {
					flag_start = true;
					break;
				}
			}
			if (!flag_start) {
				tops[num] = graph[i]->start;
				num = num + 1;
			}
			for (int end = 0; end < num; end++) {
				if (tops[end] != graph[i]->end)
					flag_end = false;
				else if(tops[end] == graph[i]->end) {
					flag_end = true;
					break;
				}
			}
			if (!flag_end) {
				tops[num] = graph[i]->end;
				num = num + 1;
			}
		}
		//delete tops;
		return num;
	}

	TT* GetTops() {
		TT* tops = new TT[graph_size];
		int num = 0;
		bool flag_end = false;
		bool flag_start = false;
		for (int i = 0; i < graph_size; i++) {
			for (int start = 0; start < num; start++) {
				if (tops[start] != graph[i]->start)
					flag_start = false;
				else if (tops[start] == graph[i]->start) {
					flag_start = true;
					break;
				}
			}
			if (!flag_start) {
				tops[num] = graph[i]->start;
				num = num + 1;
			}
			for (int end = 0; end < num; end++) {
				if (tops[end] != graph[i]->end)
					flag_end = false;
				else if(tops[end] == graph[i]->end) {
					flag_end = true;
					break;
				}
			}
			if (!flag_end) {
				tops[num] = graph[i]->end;
				num = num + 1;
			}
		}
		return tops;
	}

	void ReSize(int size) {
		if (size < 0) {
			throw bad_array_new_length();
		}
		int old_size = GetSizeEdge();
		if (size < old_size) {
			while (old_size != size) {
				delete graph[old_size - 1];
				old_size--;
			}
		}
		else {
			Element<TT, TW>** graph_new = new Element<TT, TW>*[size];
			for (int i = 0; i < old_size; i++) {
				Element<TT, TW>* el = new Element<TT, TW>[1];
				el->start = graph[i]->start;
				el->end = graph[i]->end;
				el->weight = graph[i]->weight;
				graph_new[i] = &*el;
			}
			for (int i = old_size; i < size; i++) {
				Element<TT, TW>* el = new Element<TT, TW>[size];
				graph_new[i] = &*el;
			}
			delete graph;
			graph = graph_new;
		}
		graph_size = size;
	}

	void Add(TT start, TW weight, TT end) {
		ReSize(graph_size + 1);
		graph[graph_size - 1]->start = start;
		graph[graph_size - 1]->end = end;
		graph[graph_size - 1]->weight = weight;
	}

	void Print() {
		for (int i = 0; i < graph_size; i++) {
			cout << "Edge : (";
			cout << graph[i]->start << "; ";
			cout << graph[i]->end << ") ";
			cout << " Weight edge: " << graph[i]->weight << endl;
		}
	}

	TW find(TT start, TT end) { //вес пути из s в c или 0, если пути нет
		for (int i = 0; i < GetSizeEdge(); i++)
			if (graph[i]->start == start && graph[i]->end == end)
				return graph[i]->weight;
		return 0;
	}

	Element<TT, TW>* operator[](int index)  {
		return graph[index];
	}

	TW** Matrix() {
		int numtops = GetNumTops();
		TW** Matrix= new TW*[numtops];
		TT* tops =GetTops();
		for (int i = 0; i < GetNumTops(); i++) {
			Matrix[i] = new TW[numtops];
			for (int j = 0; j < GetNumTops(); j++) {
				for (int edge = 0; edge < graph_size; edge++) {
					if (graph[edge]->start == tops[i] && graph[edge]->end == tops[j]) {
						Matrix[i][j] = graph[edge]->weight;
						break;
					}
					else 
						Matrix[i][j] = 0;
				}
			}
		}
		return Matrix;
	}

	~Graph<TT, TW>() = default;
};