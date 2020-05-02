#pragma once
#include "../inc/graphs.hh"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

class Array_class : public Graphs_class_base
{
    int **array_pointer_;

public:
    int GetWeight(int b, int e) { return array_pointer_[b][e]; }
    void clearing_graphes();
    void randomize_graph();
    void show_graph();
    int read_graph_from_file(std::string filename);
    Array_class(int v, double ro);
    Array_class() : Graphs_class_base(){};
};