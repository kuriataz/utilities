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
#include <uniq.hpp>
#include <shell.hpp>


int main(int argc, char **argv)
{
  if (argc < 2)
  {
    return 1;
  }

  constexpr int OPTION_HELP = 1;
  constexpr int OPTION_DUPLICATE = 2;
  constexpr int OPTION_UNIQ = 3;

  Option_Definition option_defs[] = {
      Option_Definition{"-h", "--help", OPTION_HELP, false},
      Option_Definition{"-d", "--duplicate", OPTION_DUPLICATE, false},
      Option_Definition{"-u", "--uniq", OPTION_UNIQ, false}};

  constexpr int COMMAND_LIST = 1;
  constexpr int COMMAND_ADD = 2;
  constexpr int COMMAND_REMOVE = 3;
  constexpr int COMMAND_SELECT = 4;
  constexpr int COMMAND_SHELL = 5;
  constexpr int COMMAND_UPDATE = 6;

  Command_Definition command_defs[] = {
      Command_Definition{"list", COMMAND_LIST, true},
      Command_Definition{"add", COMMAND_ADD, false},
      Command_Definition{"remove", COMMAND_REMOVE, false},
      Command_Definition{"select", COMMAND_SELECT, false},
      Command_Definition{"shell", COMMAND_SHELL, false},
      Command_Definition{"update", COMMAND_UPDATE, false}};

  // int size = sizeof(option_defs); // = 360 don't know why

  Parse_Result result =
      parse_arguments(argc, argv, option_defs, 1, command_defs, 6);

  if (!(result.options.empty()))
  {
    for (Option const &option : result.options)
    {
      if (option.id == OPTION_HELP)
      {
        dict_help();
      }
    }
  }

  std::string word;
  std::string description;
  std::string column;
  std::string new_value;

  if (result.arguments.size() > 0)
  {
    word = result.arguments[0];

    if (result.arguments.size() > 1)
    {
      result.arguments.erase(0);
      description = array_to_string(result.arguments);

      // for update
      column = result.arguments[0];
      result.arguments.erase(0);
      new_value = array_to_string(result.arguments);
    }
  }

  Dict dict;

  std::string command = argv[1];
  std::fstream base;
  base.open("dict/data_base.txt", std::ios::in);
  dict.get_data_from_base(base);
  base.close();

  Record *end = dict.data.end();
  if (!(result.options.empty()))
  {
    for (Option const &option : result.options)
    {
      switch (option.id)
      {
      case OPTION_DUPLICATE:
        end = find_duplicate(dict.data.begin(), dict.data.end());
        break;
      case OPTION_UNIQ:
        end = find_uniq(dict.data.begin(), dict.data.end());
        break;
      }
    }
  }

  if (!(result.commands.empty()))
  {
    for (Command const &command : result.commands)
    {
      switch (command.id)
      {
      case COMMAND_SHELL:
         shell(dict);
        break;
      case COMMAND_LIST:
        dict.list();
        break;
      case COMMAND_ADD:
        dict.add(word, description);
        break;
      case COMMAND_REMOVE:
        dict.remove(stoi(word));
        break;
      case COMMAND_SELECT:
        dict.select(word);
        break;
      case COMMAND_UPDATE:
        dict.update(word, column, new_value);
        break;
      }
    }
  }

  // if (command == "show")
  // {
  //   dict.show(word);
  // }
  // else if (command == "list")
  // {
  //   dict.list();
  // }
  // else if (command == "add")
  // {
  //   dict.add(word, description);
  // }
  // else if (command == "remove")
  // {
  //   dict.remove(word);
  // }

  base.open("dict/data_base.txt", std::ios::out);
  dict.send_data_to_base(base);
  base.close();

  return 0;
}