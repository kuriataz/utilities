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
      << "UNIQ - a program to remove duplicated elements\n"
         "The first argument is for [INPUT_FILE_NAME] if none: [-]\n"
         "The second argument is for [OUTPUT_FILE_NAME]\n\n"
         "OPTIONS:\n\n"
         " --help, -h                           Show an the information (that needs improvment) about the program and how to use it\n"
      << std::endl;

  exit(0);
}

void output(int *begin, int *end, std::string value)
{
  if (value == "cout")
  {
    for ( ; begin != end; begin++)
    {
      std::cout << *begin << std::endl;
    }
    return;
  }

  std::ofstream output_file;
  output_file.open(value);
  if (!output_file.is_open())
  {
    std::cerr << "wrong file\n";
    std::cout << value << std::endl;
  }
  else
  {
    for ( ; begin != end; begin++)
    {
      output_file << *begin << std::endl;
    }
  }
  output_file.close();
}
