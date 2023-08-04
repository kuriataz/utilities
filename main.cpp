#include <algorithm>
#include <cstdio>
#include <expected.hpp>
#include <fstream>
#include <iostream>
#include <methods.hpp>
#include <optional>
#include <options.hpp>
#include <sort_types.hpp>
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
  constexpr int OPTION_HELP = 1;
  constexpr int OPTION_REVERSE = 2;
  constexpr int OPTION_OUTPUT = 3;
  constexpr int OPTION_STABLE = 4;
  constexpr int OPTION_QUICK = 5;

  Option_Definition option_defs[] = {
      Option_Definition{"-h", "--help", OPTION_HELP, false},
      Option_Definition{"-r", "--reverse", OPTION_REVERSE, false},
      Option_Definition{"-o", "--output", OPTION_OUTPUT, true},
      Option_Definition{"-s", "--stable", OPTION_STABLE, false},
      Option_Definition{"-q", "--quick", OPTION_QUICK, false}};

  // int size = sizeof(option_defs); // = 360 don't know why
  // std::cout << size << std::endl;

  Parse_Result result =
      parse_arguments(argc, argv, option_defs, 5);

  if (!(result.options.empty()))
  {
    for (Option const &option : result.options)
    {
      if (option.id == OPTION_HELP)
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
    return 1;
  }

  std::vector<int> ints = pre_ints.value();
  // typedef void(*Sort_Ptr)(std::vector<int>&);
  using It_Sort_Ptr = void (*)(int*, int*);
  It_Sort_Ptr it_sort_ptr = bubbleSort;

  if (!(result.options.empty()))
  {
    for (Option const &option : result.options)
    {
      switch (option.id)
      {
      case OPTION_STABLE:
        it_sort_ptr = insertionSort;
        break;
      case OPTION_QUICK:
        it_sort_ptr = quickSort;
        break;
      }
    }
  }

  it_sort_ptr(&ints[0], &ints[ints.size()]);

  std::string output_destination = "cout";

  if (!(result.options.empty()))
  {
    for (Option const &option : result.options)
    {
      switch (option.id)
      {
      case OPTION_REVERSE:
        std::reverse(ints.begin(), ints.end());
        break;
      case OPTION_OUTPUT:
        output_destination = option.value;
        break;
      }
    }
  }

  output(ints, output_destination);

  return 0;
}