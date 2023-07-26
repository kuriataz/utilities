#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
#include <string_view>
#include <optional>
#include "options.hpp"
#include "methods.hpp"
#include "sort_types.hpp"

std::vector<int> getNumberFromString(std::string s)
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
  }
  return numbers;
}


int main(int argc, char **argv)
{
  if (argc > 1 && ((strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0)))
  {
    help();
    return 0;
  }

  Option_Definition option_defs[] = {
    Option_Definition{"-h", "--help", 1, false},
    Option_Definition{"-r", "--reverse", 2, false},
    Option_Definition{"-o", "--output", 3, true},
    Option_Definition{"-s", "--stable", 4, false},
    Option_Definition{"-q", "--quick", 5, false}
  };

  Parse_Result result = parse_arguments(argc, argv, option_defs, 5);

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

  std::vector<int> ints = getNumberFromString(input);
  bool is_sorted = false;

  if(!(result.options.empty()))
  {
    for(Option const& option: result.options)
    {
      switch(option.id)
      {
        case 1:
          help();
          break;
        case 4:
          stable(ints);
          is_sorted = true;
          break;
        case 5:
          quick(ints);
          is_sorted = true;
          break;
        case 2:
          reverse(ints, is_sorted);
          is_sorted = true;
          break;
        case 3:
          output(ints, option.value, is_sorted);
          return 0;
      }
    }
  }
  if (!is_sorted)
  {
    bubbleSort(ints, ints.size());
  }
  for (int i = 0; i < ints.size(); i++)
  {
    std::cout << ints.at(i) << std::endl;
  }
return 0;
}