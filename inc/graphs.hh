#pragma once

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <stdio.h>

class Graphs_class_base
{
protected:
    int size, edges;
    float ro;

public:
    const int GetV() const { return size; }
    const int GetE() const { return edges; }
    const float GetR() const { return ro; }
    virtual void randomize_graph() = 0;
    virtual void show_graph() = 0;
    virtual int read_graph_from_file(std::string filename) = 0;
    virtual void clearing_graphes() = 0;
    Graphs_class_base(int v, float r)
    {
        size = v;
        ro = r;
    }
    Graphs_class_base()
    {
        size = 0;
        ro = 0;
        edges = 0;
    }
};
