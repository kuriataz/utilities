#pragma once

#include <cstdio>
#include <iostream>

// bubbleSort is a function that uses bubble sort algorithm
//it is default in sort/main.cpp
// begin is a pointer to the first element from the collection that is sorted
// end is a pointer to the one after the last element from the collection that is sorted
template <typename T>
void bubbleSort(T *begin, T *end)
{
  while (begin != end)
  {
    bool swapped = false;
    T *i = begin;
    T *j = begin + 1;
    for (; j != end; ++j, ++i)
    {
      if (*j < *i)
      {
        T temp = *j;
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

// insertionSort is a function that uses insertion sort algorithm
// it is used after "stable" flag
// begin is a pointer to the first element from the collection that is sorted
// end is a pointer to the one after the last element from the collection that is sorted
template <typename T>
void insertionSort(T *begin, T *end)
{
  T *i = begin;
  for (; i != end; ++i)
  {
    T *j = i;
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

// quickSort is a function that uses quick sort algorithm
// it is used after "quick" flag
// begin is a pointer to the first element from the collection that is sorted
// end is a pointer to the one after the last element from the collection that is sorted
template <typename T>
void quickSort(T *begin, T *end)
{
  if (begin >= end - 1)
  {
    return;
  }

  T *left = begin;
  T pivot = *(end - 1);
  T *i = begin;


  for (; i != end; ++i)
  {
    if (*i < pivot)
    {
      std::swap(*i, *left);
      left++;
    }
  }
  std::swap(*(end - 1), *left);

  quickSort(begin, left);
  quickSort((left + 1), end);
}
