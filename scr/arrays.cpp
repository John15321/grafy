#include "../inc/arrays.hh"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

// maksymalna wartosc inta
static int big_num = 2137483647;

Array_class::Array_class(int v, double ro) : Graphs_class_base(v, ro)
{
    array_pointer_ = new int *[v];
    for (int i = 0; i < v; i++)
    {
        array_pointer_[i] = new int[v];
    }
}

void Array_class::clearing_graphes()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            array_pointer_[i][j] = big_num;
        }
    }
}

void Array_class::randomize_graph()
{
    int b, w, e, t_m_p[size];
    for (int i = 0; i < size; i++)
    {
        t_m_p[i] = 0;
    }
    Array_class::clearing_graphes();
    for (int i = 0; i < size * (size - 1) * ro; i++)
    {
        do
        {
            b = rand() % size;
        } while (t_m_p[b] >= size - 1);
        do
        {
            e = rand() % size;
        } while (e == b || array_pointer_[b][e] != big_num);
        do
        {
            w = rand() % 30;
        } while (w == 0);
        array_pointer_[b][e] = w;
        t_m_p[b]++;
    }
}

void Array_class::show_graph()
{
    for (int i = 0; i < size; i++)
    {
        std::cout << i << std::endl;
        for (int j = 0; j < size; j++)
        {
            if (array_pointer_[i][j] != big_num)
                std::cout << i << " " << array_pointer_[i][j] << " " << j << std::endl;
        }
    }
}

int Array_class::read_graph_from_file(std::string filename)
{
    int start, b, w, e;
    std::fstream file;
    file.open(filename, std::ios::in);

    if (file.good())
    {
        file >> edges >> size >> start;
        array_pointer_ = new int *[size];
        for (int i = 0; i < size; i++)
        {
            array_pointer_[i] = new int[size];
        }
        Array_class::clearing_graphes();
        while (!file.fail())
        {
            file >> b >> e >> w;
            Array_class::array_pointer_[b][e] = w;
        }
    }
    file.close();
    return start;
}