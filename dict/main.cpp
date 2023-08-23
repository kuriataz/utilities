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
#include <data.hpp>


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
  std::vector<std::string> record;

  if (!(result.arguments.empty()))
  {
    word = result.arguments[1];

    if (result.arguments.size() > 2)
    {
      record = result.arguments;
    }
  }

  std::string command = argv[1];
  std::fstream data_base_file;
  data_base_file.open("dict/data_base.txt", std::ios::out | std::ios::in);

  // Data data_base = get_data_from_base("dict/data_base.txt");
  Data data_base = get_data_from_base(data_base_file);


  if (command == "show")
  {
    show(word, data_base);
  }
  else if (command == "list")
  {
    list(data_base);
  }
  else if (command == "add")
  {
  std::cout << "here\n";
    add(record, data_base);
  }
  else if (command == "remove")
  {
    remove(word, data_base);
  }

  send_data_to_base(data_base, data_base_file);
  // send_data_to_base(data_base, "dict/data_base1.txt");
  data_base_file.close();
  return 0;
}