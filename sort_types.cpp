#include <iostream>
#include <cstdio>
#include "sort_types.hpp"


void bubbleSort(std::vector<int> &vec, int n)
{
  int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
        if (vec[j] > vec[j + 1])
        {
            int temp = vec[j];
            vec[j] = vec[j + 1];
            vec[j + 1] = temp;
        }
        }
    }
    std::cout << "bubble" << std::endl;
}

void insertionSort(std::vector<int> &vec)
{
    for (int i = 1; i < vec.size(); i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (vec[j] < vec[j - 1])
            {
                std::swap(vec[j], vec[j - 1]);
            }
            else
            {
                break;
            }
        }
    }
    std::cout << "insertion" << std::endl;
}

void quickSort(std::vector<int> &vec, int smaller, int greater)
{
    int size = sizeof(vec);
    int pivot = vec[size];

    for (int i = 0; i < size; i++)
    {
        if (vec[i] >= pivot)
        {
            greater++;
        }
        else
        {
            std::swap(vec[i], vec[smaller + 1]);
            smaller++;
            greater++;
        }
    }
    std::cout << "quick" << std::endl;
    quickSort(vec, smaller, greater);
}