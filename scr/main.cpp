#include "../inc/paths.hh"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

void Test_function()
{
    std::fstream saveA, saveL;
    Array_class *GA;
    List_of_graphs *GL;
    saveA.open("Macierz.txt", std::ios::out);
    saveL.open("Lista.txt", std::ios::out);

    float RO[] = {0.25, 0.5, 0.75, 1};
    int SIZE[] = {10, 30, 50, 70, 100};

    saveA << "Czas: \t ro: \t Wynik:" << std::endl;
    saveL << "Czas: \t ro: \t Wynik:" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            GA = new Array_class(SIZE[i], RO[j]);
            GL = new List_of_graphs(SIZE[i], RO[j]);
            for (int k = 0; k < 100; k++)
            {
                GA->randomize_graph();
                GL->randomize_graph();
                m_b_m(*GA, rand() % SIZE[i], saveA, RO[j]);
                l_b_m(*GL, rand() % SIZE[i], saveL, RO[j]);
            }
            delete GA;
            delete GL;
        }
    }
    saveA.close();
    saveL.close();
}
void GraphFromFile()
{
    int choice, start;
    std::string filename;
    std::cout << "Typ:" << std::endl;
    std::cout << "1. Macierz" << std::endl;
    std::cout << "2. Lista" << std::endl;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
    {
        std::fstream saveM;
        saveM.open("TimeM.txt", std::ios::out);
        Array_class *GM = new Array_class();
        std::cout << "Nazwa pliku:" << std::endl;
        std::cin >> filename;
        start = GM->read_graph_from_file(filename);
        m_b_m(*GM, start, saveM, 0);
        saveM.close();
        break;
    }
    case 2:
    {
        std::fstream saveL;
        saveL.open("TimeL.txt", std::ios::out);
        List_of_graphs *GL = new List_of_graphs();
        std::cout << "podaj nazwe pliku" << std::endl;
        std::cin >> filename;
        start = GL->read_graph_from_file(filename);
        l_b_m(*GL, start, saveL, 0);
        saveL.close();
        break;
    }

    default:
    {
        std::cout << "Blad polecenia" << std::endl;
        break;
    }
    }
}
int main()
{
    srand(time(NULL));
    int choice;
    while (true)
    {
        std::cout << "1. Pobierz" << std::endl;
        std::cout << "2. Testuj" << std::endl;
        std::cout << "3. Koniec" << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            GraphFromFile();
            break;
        case 2:
            Test_function();
            break;
        case 3:
            break;
        default:
            std::cout << "Blad polecenia" << std::endl;
            break;
        }
        if (choice == 3)
            break;
    }
    return 0;
}