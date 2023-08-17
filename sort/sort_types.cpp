#include <cstdio>
#include <iostream>
#include "sort_types.hpp"

// void bubbleSort(int* begin, int* end) {
//   int const n = end - begin;
//   for (int i = 0; i < n - 1; i++)
//   {
//     for (int j = 0; j < n - i - 1; j++)
//     {
//       if (begin[j] > begin[j + 1])
//       {
//         int temp = begin[j];
//         begin[j] = begin[j + 1];
//         begin[j + 1] = temp;
//       }
//     }
//   }
// }

void bubbleSort(int *begin, int *end)
{
  while (begin != end)
  {
    bool swapped = false;
    int *i = begin;
    int *j = begin + 1;
    for (; j != end; ++j, ++i)
    {
      if (*j < *i)
      {
        int temp = *j;
        *j = *i;
        *i = temp;
        swapped = true;
      }
    }

    end = i;
    if (!swapped)
    {
      break;
    }
  }
}

// void insertionSort(int* begin, int* end)
// {
//   int const size = end - begin;
//   for (int i = 1; i < size; i++)
//   {
//     for (int j = i; j > 0; j--)
//     {
//       if (begin[j] < begin[j - 1])
//       {
//         std::swap(begin[j], begin[j - 1]);
//       }
//       else
//       {
//         break;
//       }
//     }
//   }
// }

void insertionSort(int *begin, int *end)
{
  int *i = begin;
  for (; i != end; ++i)
  {
    int *j = i;
    for (; j != begin; j--)
    {
      if (*j < *(j - 1))
      {
        std::swap(*j, *(j - 1));
      }
      else
      {
        break;
      }
    }
  }
}

void quickSort(int *begin, int *end)
{
  if (begin >= end - 1)
  {
    return;
  }

  int* left = begin;
  int pivot = *(end - 1);
  int* i = begin;


  for (; i != end; ++i)
  {
    if (*i < pivot)
    {
      std::swap(*i, *left);
      left++;
    }
  }
  std::swap(*(end - 1), *left);

  // std::cout << "here" << std::endl;

  quickSort(begin, left);
  quickSort((left + 1), end);
}
