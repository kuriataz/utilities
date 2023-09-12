#include <algorithm>
#include <cstdio>
#include <expected.hpp>
#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <string.h>
#include <string_view>

#include <uniq.hpp>
#include <options.hpp>
#include <methods.hpp>
#include <array.hpp>
#include <iterator.hpp>

using tl::expected;
using tl::unexpected;

expected<Array<int>, std::string> getNumberFromString(std::string s)
{
  Array<int> numbers;
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
  constexpr int OPTION_DUPLICATE = 2;

  Option_Definition option_defs[] = {
      Option_Definition{"-h", "--help", OPTION_HELP, false},
      Option_Definition{"-d", "--duplicate", OPTION_DUPLICATE, false}};

  Parse_Result result =
      parse_arguments(argc, argv, option_defs, 2);

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

  std::ostream *output_stream = &std::cout;
  std::ofstream output_file;
  std::istream *input_stream = &std::cin;
  std::ifstream file;

  if (!(result.arguments.empty()))
  {
    std::string input(result.arguments[0]);
    if (!(input == "-"))
    {
      file.open(input);
      if (!file.is_open())
      {
        std::cerr << "Couldn't open file\n";
        return 1;
      }
      input_stream = &file;
    }
    if (result.arguments.size() > 1)
    {
      std::string output(result.arguments[1]);
      output_file.open(output);
      if (!output_file.is_open())
      {
        std::cerr << "Wrong output file\n";
        return 1;
      }
      output_stream = &output_file;
    }
  }

  std::string input;
  std::string input_line;
  while (*input_stream)
  {
    if (!input.empty())
    {
      input.append(" ");
    }
    input.append(input_line);
    getline(*input_stream, input_line);
  }

  auto pre_ints = getNumberFromString(input);
  if (!pre_ints)
  {
    std::cerr << pre_ints.error() << std::endl;
    return 1;
  }

  Array<int> ints = pre_ints.value();
  int *begin = ints.data();
  int size = ints.size();
  int *end = nullptr;
  bool d_flag = false;

  if (!(result.options.empty()))
  {
    for (Option const &option : result.options)
    {
      if (option.id == OPTION_DUPLICATE)
      {
        end = find_duplicate<int>(&ints[0], &ints[size]);
        d_flag = true;
      }
    }
  }

  if (!d_flag)
  {
    end = find_uniq<int>(&ints[0], &ints[size]);
  }

  output(begin, end, *output_stream);

  return 0;
}