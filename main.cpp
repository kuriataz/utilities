#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
#include <string_view>
#include <optional>
#include "options.hpp" // wiem ze zle
#include "methods.hpp"
#include "sort_types.hpp"


//TO DO:
// --stable - insertion sort
//  --quick - quick sort


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



// std::optional<Parse_Result>
// return std::nullopt

int main(int argc, char **argv)
{
  bool is_reverse = false;
  bool is_output = false;
  std::string output_file_name;
  int32_t flags_counter = 0;
  std::string sort_type;

  Option_Definition const option_defs[] = {
    Option_Definition{"-h", "--help", 1, false},
    Option_Definition{"-r", "--reverse", 2, false},
    Option_Definition{"-o", "--output", 3, true},
    Option_Definition{"-s", "--stable", 4, false},
    Option_Definition{"-q", "--quick", 5, false}
  };


  std::optional<Parse_Result> result = parse_arguments(argc, argv, option_defs);

  if(result)
  {
    for(Option const& option: result->options)
    {
      switch(option.id)
      {
        case 1: // -h, --help
          flags_counter++;
          help();
          break;
        case 2:
          flags_counter++;
          reverse(&is_reverse); // why not *is_reverse??
          break;
        case 3:
          flags_counter++;
          output(output_file_name, option.value, &is_output);
        case 4:
          flags_counter++;
          stable(sort_type);
          break;
        case 5:
          flags_counter++;
          quick(sort_type);
          break;
      }
    }
  }
  // TODO: Add options:
  //        -h, --help
  //        -r, --reverse
  //        -o, --output  FILE

  // Option{"-h", "--help", 1};
  // Option{"-r", "--reverse", 2};
  // Option{"-o", "--output", 3};

  std::ofstream output_file;
  std::istream *stream = &std::cin;
  std::ifstream file;

  // input from file
  if (argc > 1)
  {
    if (argc > (flags_counter + 1))
    {
      std::cout << "from file" << std::endl;
      std::string arg(argv[flags_counter + 1]);
      file.open(arg);
      if (!file.is_open())
      {
        std::cerr << "Couldn't open file\n";
        return 1;
      }
      stream = &file;
  }
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

bubbleSort(ints, ints.size(), is_reverse);

if (!is_output)
{
  if (!is_reverse)
  {
    for (int i = 0; i < ints.size(); i++)
    {
      std::cout << ints.at(i) << std::endl;
    }
  }
  else
  {
    for (int i = 1; i <= ints.size(); i++)
    {
      std::cout << ints.at(ints.size() - i) << std::endl;
    }
  }
}
else
{
  output_file.open(output_file_name);
  // output_file.open("output.txt");
  if (!output_file.is_open())
  {
    std::cerr << "wrong file\n";
    std::cout << output_file_name << std::endl;
  }
  if (!is_reverse)
  {
    for (int i = 0; i < ints.size(); i++)
    {
      output_file << ints.at(i) << std::endl;
    }
  }
  else
  {
    for (int i = 1; i <= ints.size(); i++)
    {
      output_file << ints.at(ints.size() - i) << std::endl;
    }
  }
  output_file.close();
}
return 0;
}