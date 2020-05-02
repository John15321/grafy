#include "../inc/lists.hh"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

void List_of_all_edges::add_edge(int b, int w, int e)
{
    Edge *N = new Edge;
    N->add_val(b, w, e);
    if (first == NULL)
    {
        first = N;
    }
    else
    {
        Edge *TMP = first;
        first = N;
        N->add_nextone(TMP);
    }
    list_size++;
}

void List_of_all_edges::show_list_content()
{
    Edge *t_m_p = first;
    while (t_m_p)
    {
        std::cout << t_m_p->get_beggining() << " " << t_m_p->get_weight() << " " << t_m_p->get_end() << std::endl;
        t_m_p = t_m_p->get_nextone();
    }
}

void List_of_graphs::clearing_graphes()
{
    delete[] TabV;
    TabV = new List_of_all_edges[size];
}

void List_of_graphs::randomize_graph()
{
    int e, b, w;
    // Operacja inicjalizacji poprzez zmienną jest możliwa dzięki odpowiedniemu standardowi C++
    int TabAc[size][size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            TabAc[i][j] = 0;
        }
    }

    // Funkcja do "czyszczenia" grafu
    List_of_graphs::clearing_graphes();
    for (int i = 0; i < size * (size - 1) * ro; i++)
    {
        do
        {
            b = rand() % size;
        } while (TabV[b].get_listy() == (size - 1));
        do
        {
            e = rand() % size;
        } while (e == b || TabAc[b][e] == 1);
        do
        {
            w = rand() % 30;
        } while (w == 0);
        TabAc[b][e] = 1;
        TabV[b].add_edge(b, w, e);
    }
}

// Wypisanie grafu
void List_of_graphs::show_graph()
{
    int v = List_of_graphs::GetV();
    for (int i = 0; i < v; i++)
    {
        std::cout << i << std::endl;
        TabV[i].show_list_content();
    }
}

// Zwraca liste grafow
int List_of_graphs::read_graph_from_file(std::string filename)
{
    int start, b, e, w;
    std::fstream file;
    file.open(filename, std::ios::in);
    if (file.good())
    {
        file >> edges >> size >> start;
        TabV = new List_of_all_edges[size];
        if (!file.fail())
        {
            file >> b >> e >> w;
            List_of_graphs::TabV[b].add_edge(b, w, e);
        }
    }
    file.close();
    return start;
}