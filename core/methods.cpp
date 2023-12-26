#include <cstdio>
#include <iostream>
#include <methods.hpp>
#include <iterator.hpp>


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

void output(int *begin, int *end, std::ostream &stream)
{
  for ( ; begin != end; begin++)
  {
    stream << *begin << '\n';
  }
}

void output(iterator<int> begin, iterator<int> end, std::ostream &stream)
{
  for ( ; begin != end; ++begin)
  {
    stream << *begin << '\n';
  }
}

Array<std::string> tokenize(std::string s, std::string del)
{
    Array<std::string> strings;
    int start, end = -1 * del.size();
    do {
        start = end + del.size();
        end = s.find(del, start);
        strings.push_back(s.substr(start, end - start));

    } while (end != -1);
    return strings;
}
