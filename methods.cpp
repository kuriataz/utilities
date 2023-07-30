#include "methods.hpp"
#include "sort_types.hpp"
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>
#include <string_view>
#include <vector>

void help()
{
  std::cout << "--reverse or -r to sort from the biggest to the smallest\n"
               "--output[FILE_NAME] or -o[FILE_NAME] to write output to the FILE_NAME\n"
               "--stable or -s to use stable sorting algorithm (insertion sort)\n"
               "--quick or -q to use quick sorting algorithm (quick sort)\n\n\n\n"
               "To close the 'help' press 'q'\n"
            << std::endl;

  system("stty raw");

  char quit = getchar();

  system("stty cooked");

  if (quit == 'q')
  {
    exit(0);
  }
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