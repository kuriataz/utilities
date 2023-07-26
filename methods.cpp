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

void help() {
  std::cout << "you need help\n
          use-- reverse or
      -r to sort from the biggest to the smallest\n use-- output[FILE_NAME] or
      -o[FILE_NAME] to write output to the FILE_NAME " << std::endl;
}

void reverse(std::vector<int> &ints, bool is_sorted) {
  if (!is_sorted) {
    bubbleSort(ints, ints.size());
  }
  int temp = 0;
  for (int i = 0; i < (ints.size() / 2) + 1; i++) {
    std::swap(ints[i], ints[ints.size() - i - 1]);
  }
}

void output(std::vector<int> &ints, std::string value, bool is_sorted) {
  std::ofstream output_file;
  output_file.open(value);
  if (!output_file.is_open()) {
    std::cerr << "wrong file\n";
    std::cout << value << std::endl;
  } else {
    if (!is_sorted) {
      bubbleSort(ints, ints.size());
    }
    for (int i = 0; i < ints.size(); i++) {
      output_file << ints.at(i) << std::endl;
    }
  }
  output_file.close();
}

void stable(std::vector<int> &ints) { insertionSort(ints); }

void quick(std::vector<int> &ints) {
  int size = ints.size();
  quickSort(ints, 0, size - 1);
}