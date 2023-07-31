#include "expected.hpp"
#include "methods.hpp"
#include "options.hpp"
#include "sort_types.hpp"
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <string.h>
#include <string_view>
#include <vector>

using tl::expected;
using tl::unexpected;

expected<std::vector<int>, std::string> getNumberFromString(std::string s)
{
  std::vector<int> numbers;
  std::stringstream stream;
  stream << s;
  std::string temp_str;

  while (!stream.eof())
  {
    int temp_int;
    if (stream >> temp_int)
    {
      numbers.push_back(temp_int);
    }
    else
    {
      return unexpected("Wrong input");
    }
  }
  return numbers;
}

int main(int argc, char **argv)
{

  Option_Definition option_defs[] = {
      Option_Definition{"-h", "--help", 1, false},
      Option_Definition{"-r", "--reverse", 2, false},
      Option_Definition{"-o", "--output", 3, true},
      Option_Definition{"-s", "--stable", 4, false},
      Option_Definition{"-q", "--quick", 5, false}};

  Parse_Result result = parse_arguments(argc, argv, option_defs, 5);
  if (!(result.options.empty()))
  {
    for (Option const &option : result.options)
    {
      if (option.id == 1)
      {
        help();
      }
    }
  }

  std::string output_file_name;
  int32_t flags_counter = 0;
  std::string sort_type;

  std::ofstream output_file;
  std::istream *stream = &std::cin;
  std::ifstream file;

  // from file
  if (!(result.arguments.empty()))
  {
    std::string arg(result.arguments[0]);
    file.open(arg);
    if (!file.is_open())
    {
      std::cerr << "Couldn't open file\n";
      return 1;
    }
    stream = &file;
  }
  std::string input;
  std::string input_line;
  while (*stream)
  {
    if (!input.empty())
    {
      input.append(" ");
    }
    input.append(input_line);
    getline(*stream, input_line);
  }

  auto pre_ints = getNumberFromString(input);

  if (!pre_ints)
  {
    std::cerr << pre_ints.error() << std::endl;
    return -1;
  }

  std::vector<int> ints = pre_ints.value();

  // algorithm:
  // 0 - bubbleSort
  // 1 - insertionSort
  // 2 - quickSort
  int algorithm = 0;

  if (!(result.options.empty()))
  {
    for (Option const &option : result.options)
    {
      switch (option.id)
      {
      case 4:
        algorithm = 1; // insertion
        break;
      case 5:
        algorithm = 2; // quick
      }
    }
  }

  // sorting
  switch (algorithm)
  {
  case 0:
    bubbleSort(ints, ints.size());
    break;
  case 1:
    insertionSort(ints);
    break;
  case 2:
    int size = ints.size();
    quickSort(ints, 0, size - 1);
  }

  if (!(result.options.empty()))
  {
    for (Option const &option : result.options)
    {
      switch (option.id)
      {
      case 2:
        std::reverse(ints.begin(), ints.end());
        break;
      case 3:
        output(ints, option.value);
        return 0;
      }
    }
  }

  for (int i = 0; i < ints.size(); i++)
  {
    std::cout << ints.at(i) << std::endl;
  }
  return 0;
}