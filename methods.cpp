#include "methods.hpp"
#include "sort_types.hpp"
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string.h>
#include <string_view>
#include <vector>

void help()
{
  std::cout
      << "OPTIONS:\n\n"
         " --reverse, -r                        Sort from the biggest to the "
         "smallest\n"
         " --output[FILE_NAME], -o[FILE_NAME]   Write output to the FILE_NAME\n"
         " --stable, -s                         Stable sorting algorithm "
         "(insertion sort)\n"
         " --quick, -q                          Quick sorting algorithm (quick "
         "sort)\n"
      << std::endl;

  exit(0);
}

// void reverse(std::vector<int> &ints, bool is_sorted) {
//   if (!is_sorted) {
//     bubbleSort(ints, ints.size());
//   }
//   int temp = 0;
//   for (int i = 0; i < (ints.size() / 2) + 1; i++) {
//     std::swap(ints[i], ints[ints.size() - i - 1]);
//   }
// }

void output(std::vector<int> &ints, std::string value)
{
  std::ofstream output_file;
  output_file.open(value);
  if (!output_file.is_open())
  {
    std::cerr << "wrong file\n";
    std::cout << value << std::endl;
  }
  else
  {
    for (int i = 0; i < ints.size(); i++)
    {
      output_file << ints.at(i) << std::endl;
    }
  }
  output_file.close();
}

void stable(std::vector<int> &ints) { insertionSort(ints); }

void quick(std::vector<int> &ints)
{
  int size = ints.size();
  quickSort(ints, 0, size - 1);
}