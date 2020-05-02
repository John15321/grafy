#pragma once
#include "../inc/arrays.hh"
#include "../inc/lists.hh"
#include <chrono>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

bool save_to_file(int lenght_[], int path_name[], int tabSize, int starting);
bool l_b_m(List_of_graphs graph_list, int strr, std::fstream &save, float ro);
bool m_b_m(Array_class graph_list, int strr, std::fstream &save, float ro);