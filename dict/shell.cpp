#include <cstdio>
#include <fstream>
#include <iostream>
#include <string.h>

#include <methods.hpp>
#include <options.hpp>
#include <array.hpp>
#include <dict.hpp>
#include <dict_commands.hpp>
#include <uniq.hpp>
#include <algorithm>
#include <list.hpp>

void shell_main(int argc, Array<std::string> argv, Dict &dict, Node<std::string> *head)
{
  if (argc < 1)
  {
    std::cout << "Dict requires at least one argument\n";
    return;
  }

  constexpr int OPTION_HELP = 1;
  constexpr int OPTION_DUPLICATE = 2;
  constexpr int OPTION_UNIQ = 3;

  Option_Definition option_defs[] = {
      Option_Definition{"h", "help", OPTION_HELP, false},
      Option_Definition{"-d", "--duplicate", OPTION_DUPLICATE, false},
      Option_Definition{"-u", "--uniq", OPTION_UNIQ, false}};

  constexpr int COMMAND_LIST = 1;
  constexpr int COMMAND_ADD = 2;
  constexpr int COMMAND_REMOVE = 3;
  constexpr int COMMAND_SELECT = 4;
  constexpr int COMMAND_SHELL = 5;
  constexpr int COMMAND_UPDATE = 6;
  constexpr int COMMAND_HISTORY = 7;

  Command_Definition command_defs[] = {
      Command_Definition{"list", COMMAND_LIST, true},
      Command_Definition{"add", COMMAND_ADD, false},
      Command_Definition{"remove", COMMAND_REMOVE, false},
      Command_Definition{"select", COMMAND_SELECT, false},
      Command_Definition{"shell", COMMAND_SHELL, false},
      Command_Definition{"update", COMMAND_UPDATE, false},
      Command_Definition{"history", COMMAND_HISTORY, false}};

  // int size = sizeof(option_defs); // = 360 don't know why

  Parse_Result result =
      parse_arguments(argc, argv, option_defs, 3, command_defs, 7);
    std::string base_name = "dict/data_base.txt";
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

  if (!(result.commands.empty()))
  {
    for (Command const &command : result.commands)
    {
      if (command.id == COMMAND_HISTORY)
      {
        print_list(head);
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

  //   Dict dict;
  // // std::fstream base;
  // dict.connect(base_name);

  // std::string command = argv[1];
  // // base.open(base_name, std::ios::in);
  // // dict.get_data_from_base(base);
  // // base.close();

  // Record *end = dict.data.end();

  if (!(result.options.empty()))
  {
    for (Option const &option : result.options)
    {
      switch (option.id)
      {
      case OPTION_DUPLICATE:
        find_duplicate(dict.data.begin(), dict.data.end());
        break;
      case OPTION_UNIQ:
        find_uniq(dict.data.begin(), dict.data.end());
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
        std::cout << "do not nest shell\n";
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
}

void shell(Dict &dict)
{
  std::string line;
  Node<std::string> *head = nullptr;
  while(getline(std::cin, line))
  {
    if (line == "q")
    {
        return;
    }
    Array<std::string> argv;
    argv = tokenize(line, " ");
    int argc = argv.size();
    std::string command = argv[0];
    Node<std::string> *new_command = new_node(command);
    insert_node(&head, new_command);
    shell_main(argc, argv, dict, head);
  }
}
