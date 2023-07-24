#pragma once

#include <iostream>
#include <cstdio>
#include <vector>


void bubbleSort(std::vector<int> vec, int n, bool is_rev);

void insertionSort(std::vector<int> vec, bool is_rev);

void quickSort(std::vector<int> vec, int s, int g, bool is_rev);