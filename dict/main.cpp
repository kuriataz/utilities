#include <algorithm>
#include <cstdio>
#include <expected.hpp>
#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <string.h>
#include <string_view>

#include <options.hpp>
#include <methods.hpp>
#include <array.hpp>
#include <dict.hpp>


int main(int argc, char **argv)
{
  if (argc < 2)
  {
    return 1;
  }

  constexpr int OPTION_HELP = 1;

  Option_Definition option_defs[] = {
      Option_Definition{"-h", "--help", OPTION_HELP, false}};

  // int size = sizeof(option_defs); // = 360 don't know why
  // std::cout << size << std::endl;

  Parse_Result result =
      parse_arguments(argc, argv, option_defs, 1);

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

  std::string word;
  // Array<std::string> description;
  std::vector<std::string> description;

  if (!(result.arguments.empty()))
  {
    word = result.arguments[1];

    if (!(result.arguments.size() > 2))
    {
      std::cerr << "no description\n";
    }
    else
    {
      // Array<std::string> description(result.arguments);
      description = result.arguments;
    }
  }

  std::string command = argv[1];
  std::ofstream data_base;
  data_base.open("dict/data_base.txt", std::ios::app);
  // std::ostream *output_stream = &data_base;


  if (command == "add")
  {
    add(word, description, data_base);
  }

  // else if (command == "remove")
  // {
  //   remove
  // }

  return 0;
}