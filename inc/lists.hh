#pragma once
#include "../inc/graphs.hh"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

class Edge
{
protected:
    int begin, end, weight;
    Edge *next;

public:
    const int get_beggining() { return begin; }
    const int get_end() { return end; }
    const int get_weight() { return weight; }
    const void add_val(int b, int w, int e)
    {
        begin = b;
        weight = w;
        end = e;
    }
    Edge *get_nextone() { return next; }
    void add_nextone(Edge *N)
    {
        next = new Edge;
        next = N;
    }
};

class List_of_all_edges
{
protected:
    int list_size;
    Edge *first;

public:
    Edge *get_firstone() { return first; }
    int get_listy() { return list_size; }
    void add_edge(int b, int w, int e);
    void show_list_content();
    List_of_all_edges()
    {
        first = NULL;
        list_size = 0;
    }
};

class List_of_graphs : public Graphs_class_base
{
    List_of_all_edges *TabV;

public:
    List_of_graphs(int v, double d) : Graphs_class_base(v, d) { TabV = new List_of_all_edges[v]; }
    List_of_graphs() : Graphs_class_base(){};
    Edge *get_first_of_list(int v) { return TabV[v].get_firstone(); }
    void randomize_graph();
    void show_graph();
    int read_graph_from_file(std::string filename);
    int GetSizeOfList(int v) { return TabV[v].get_listy(); }
    void clearing_graphes();
};