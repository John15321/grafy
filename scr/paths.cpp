#include "paths.hh"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

static int big_num = 10000;

bool save_to_file(int lenght_[], int path_name[], int tabSize, int starting)
{
    // Operacja inicjalizacji poprzez zmienną jest możliwa dzięki odpowiedniemu standardowi C++
    int FileTab[tabSize][tabSize], j, k;
    std::fstream file;
    for (int i = 0; i < tabSize; i++)
    {
        for (int z = 0; z < tabSize; z++)
            FileTab[i][z] = -1;
    }
    for (int i = 0; i < tabSize; i++)
    {
        k = 0;
        j = i;
        while (j != starting && j != -1)
        {
            FileTab[i][k] = path_name[j];
            k++;
            j = path_name[j];
        }
    }
    file.open("path_name.txt", std::ios::out);
    for (int i = tabSize - 1; i >= 0; i--)
    {

        file << "nr: " << i << " dlugosc: " << lenght_[i] << " sciezka: ";
        for (int z = tabSize - 1; z >= 0; z--)
        {
            if (FileTab[i][z] != -1)
                file << FileTab[i][z] << " ";
        }
        file << std::endl;
    }
    file.close();
    return true;
}

bool l_b_m(List_of_graphs graph_list, int Str, std::fstream &save, float ro)
{
    // Operacja inicjalizacji poprzez zmienną jest możliwa dzięki odpowiedniemu standardowi C++
    int tabSize = graph_list.GetV(), lenght_[tabSize], path_name[tabSize], v, u, k;
    Edge *TMP;
    std::chrono::time_point<std::chrono::system_clock> beg, fin;
    double time;
    for (int i = 0; i < tabSize; i++)
    {
        lenght_[i] = big_num;
        path_name[i] = -1;
    }
    lenght_[Str] = 0;
    beg = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < tabSize - 1; i++)
    {
        for (int j = 0; j < tabSize; j++)
        {
            TMP = graph_list.get_first_of_list(j);
            v = j;
            while (TMP)
            {
                u = TMP->get_end();
                k = TMP->get_weight();
                if (lenght_[v] + k < lenght_[u])
                {
                    lenght_[u] = lenght_[v] + k;
                    path_name[u] = v;
                }
                TMP = TMP->get_nextone();
            }
        }
    }

    for (int i = 0; i < tabSize - 1; i++)
    {
        for (int j = 0; j < tabSize; j++)
        {
            TMP = graph_list.get_first_of_list(j);
            v = j;
            while (TMP)
            {
                u = TMP->get_end();
                k = TMP->get_weight();
                if (lenght_[v] + k < lenght_[u])
                    return false;
                TMP = TMP->get_nextone();
            }
        }
    }
    fin = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration<double, std::milli>(fin - beg).count();
    save << time << "\t" << ro << "\t" << graph_list.GetV() << std::endl;
    //Save(lenght_,path_name,tabSize,Str);
    return true;
}

bool m_b_m(Array_class graph_list, int strr, std::fstream &save, float ro)
{
    // Operacja inicjalizacji poprzez zmienną jest możliwa dzięki odpowiedniemu standardowi C++
    int tabSize = graph_list.GetV(), lenght_[tabSize], path_name[tabSize], v, u, w;
    std::chrono::time_point<std::chrono::system_clock> beg, fin;
    double time;
    for (int i = 0; i < tabSize; i++)
    {
        lenght_[i] = big_num;
        path_name[i] = -1;
    }
    lenght_[Str] = 0;
    beg = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < tabSize - 1; i++)
    {
        for (int j = 0; j < tabSize; j++)
        {
            for (int k = 0; k < tabSize; k++)
            {
                w = graph_list.GetWeight(j, k);
                if (lenght_[j] + w < lenght_[k])
                {
                    lenght_[k] = lenght_[j] + w;
                    path_name[k] = j;
                }
            }
        }
    }
    for (int i = 0; i < tabSize - 1; i++)
    {
        for (int j = 0; j < tabSize; j++)
        {
            for (int k = 0; k < tabSize; k++)
            {
                if (lenght_[j] + graph_list.GetWeight(j, k) < lenght_[k])
                    return false;
            }
        }
    }
    // Zapis czasu
    fin = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration<double, std::milli>(fin - beg).count();
    save << time << "\t" << ro << "\t" << graph_list.GetV() << std::endl;
    return true;
}