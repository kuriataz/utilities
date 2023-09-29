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
#include <dict_commands.hpp>
#include <uniq.hpp>
#include <shell.hpp>


int main(int argc, char **argv)
{
  if (argc < 2)
  {
    std::cout << "Dict requires at least one argument\n";
    return 1;
  }

  constexpr int OPTION_HELP = 1;
  constexpr int OPTION_DUPLICATE = 2;
  constexpr int OPTION_UNIQ = 3;
  constexpr int OPTION_CONFIG = 4;


  Option_Definition option_defs[] = {
      Option_Definition{"-h", "--help", OPTION_HELP, false},
      Option_Definition{"-d", "--duplicate", OPTION_DUPLICATE, false},
      Option_Definition{"-u", "--uniq", OPTION_UNIQ, false},
      Option_Definition{"-c", "--config", OPTION_CONFIG, true}};

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

  size_t opt_size = sizeof(option_defs) / sizeof(option_defs[0]);
  size_t com_size = sizeof(command_defs) / sizeof(command_defs[0]);

  Parse_Result result =
      parse_arguments(argc, argv, option_defs, opt_size, command_defs, com_size);


  Dict dict;
  if (!(result.options.empty()))
  {
    for (Option const &option : result.options)
    {
      if (option.id == OPTION_HELP)
      {
        dict_help();
      }
      else if (option.id == OPTION_CONFIG)
      {
        dict.base_name = option.value;
      }
    }
  }

  std::string first_arg;
  std::string description;
  std::string column;
  std::string new_value;

  if (result.arguments.size() > 0)
  {
    first_arg = result.arguments[0];

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

  dict.connect(dict.base_name);

  std::string command = argv[1];

  iterator<Record> begin = dict.data.begin();
  iterator<Record> end = dict.data.end();
  if (!(result.options.empty()))
  {
    for (Option const &option : result.options)
    {
      switch (option.id)
      {
      case OPTION_DUPLICATE:
        dict.end_of_data = find_duplicate(begin, end);
        break;
      case OPTION_UNIQ:
        dict.end_of_data = find_uniq(begin, end);
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
        dict.add(first_arg, description);
        break;
      case COMMAND_REMOVE:
        dict.remove(stoi(first_arg));
        break;
      case COMMAND_SELECT:
        dict.select(first_arg);
        break;
      case COMMAND_UPDATE:
        dict.update(std::stoi(first_arg), column, new_value);
        break;
      }
    }
  }
  dict.disconnect();

  return 0;
}