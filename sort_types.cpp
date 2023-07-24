#include <iostream>
#include <cstdio>
#include "sort_types.hpp"


void bubbleSort(std::vector<int> vec, int n, bool is_rev)
{
  int i, j;

  if (is_rev)
  {
      for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (vec[j] < vec[j + 1])
            {
                int temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
  }
  else
  {
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
  }
}

void insertionSort(std::vector<int> &vec, bool is_rev)
{
    if (is_rev)
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
    }
    else
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
    }
}

void quickSort(std::vector<int> vec, int smaller, int greater, bool is_rev)
{
    int size = sizeof(vec);
    int pivot = vec[size];

    if (is_rev)
    {
        for (int i = 0; i < size; i++)
        {
            if (vec[i] <= pivot)
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
        quickSort(vec, smaller, greater, is_rev);
    }
    else
    {
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
        quickSort(vec, smaller, greater, is_rev);
    }
}