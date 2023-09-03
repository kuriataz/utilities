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
#include <functions.hpp>


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
  std::string description;

  if (result.arguments.size() > 1)
  {
    word = result.arguments[1];

    if (result.arguments.size() > 2)
    {
      result.arguments.erase(0);
      result.arguments.erase(1);
      description = array_to_string(result.arguments);
    }
  }

  Dict dict;

  std::string command = argv[1];
  std::fstream base;
  base.open("dict/data_base.txt", std::ios::in | std::ios::out);

  dict.get_data_from_base(base);

  if (command == "show")
  {
    dict.show(word);
  }
  else if (command == "list")
  {
    dict.list();
  }
  else if (command == "add")
  {
    dict.add(word, description);
  }
  else if (command == "remove")
  {
    dict.remove(word);
  }

  base.open("dict/data_base.txt", std::ios::out);
  dict.send_data_to_base(base);

  return 0;
}