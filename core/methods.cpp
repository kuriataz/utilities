#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <methods.hpp>
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

void output(int *begin, int *end, std::ostream &stream)
{
  for ( ; begin != end; begin++)
  {
    stream << *begin << '\n';
  }
}

std::string pretty_print(int length)
{
    std::string pretty;
    for (int i = 0; i != 10 - length; i++)
    {
        pretty += " ";
    }
    return pretty;
}

Array<std::string> tokenize(std::string s, std::string del)
{
    Array<std::string> strings;
    // if (s.find(del) != std::string::npos)
    // {
    //   return strings;
    // }
    int start, end = -1*del.size();
    do {
        start = end + del.size();
        end = s.find(del, start);
        // std::cout << s.substr(start, end - start) << std::endl;
        strings.push_back(s.substr(start, end - start));

    } while (end != -1);

      // while(end != -1)
      // {
      //   start = end + del.size();
      //   end = s.find(del, start);
      //   // std::cout << s.substr(start, end - start) << std::endl;
      //   strings.push_back(s.substr(start, end - start));
      // }

    return strings;
}
