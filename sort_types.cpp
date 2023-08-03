#include <cstdio>
#include <iostream>
#include "sort_types.hpp"

void bubbleSort(std::vector<int> &vec)
{
  int const n = vec.size();
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
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

void insertionSort(std::vector<int> &vec)
{
  for (int i = 1; i < vec.size(); i++)
  {
    for (int j = i; j != 0; j--)
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

static void internal_quickSort(std::vector<int> &vec, int begin, int end)
{
  if (begin >= end)
  {
    return;
  }

  int left = begin + 1;
  int pivot = vec[end];

  for (int i = begin; i != end + 1; i++)
  {
    if (vec[i] < pivot)
    {
      std::swap(vec[i], vec[left]);
      left++;
    }
  }
  std::swap(vec[end], vec[left]);

  internal_quickSort(vec, 0, left - 1);
  internal_quickSort(vec, left + 1, end);
}

static void internal_quickSort(int *begin, int *end)
{
  if (begin >= (end - 1))
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

  internal_quickSort(begin, left);
  internal_quickSort((left + 1), (end));
}

// void quickSort(std::vector<int> &vec)
// {
//   int const size = vec.size();
//   internal_quickSort(vec, 0, size - 1);
// }

// void quickSort(std::vector<int> &vec)
// {
//   int const size = vec.size();
//   int* begin = &vec[0];
//   int* end = &vec[size];
//   internal_quickSort(begin, end);
// }

void quickSort(int *begin, int *end)
{
  internal_quickSort(begin, end);
}
