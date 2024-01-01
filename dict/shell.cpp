#include <cstdio>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string.h>
#include <string>


#include <array.hpp>
#include <db_interface.hpp>
#include <dict.hpp>
#include <list.hpp>
#include <methods.hpp>
#include <options.hpp>
#include <uniq.hpp>


void shell_main(std::string input, DB_Interface &dict, Node<std::string> *head)
{
  Array<std::string> argv;
  std::istringstream iss(input);
  std::string token;

  while (iss >> std::quoted(token))
  {
    argv.push_back(token);
  }

  int argc = argv.size();
  if (argc < 1)
  {
    std::cout << "Dict requires at least one argument\n";
    return;
  }

  constexpr int OPTION_HELP = 1;
  constexpr int OPTION_DUPLICATE = 2;
  constexpr int OPTION_UNIQ = 3;
  constexpr int OPTION_CONFIG = 4;
  constexpr int OPTION_NCOUNT = 5;
  constexpr int OPTION_REV = 6;

  Option_Definition option_defs[] = {
      Option_Definition{"h", "help", OPTION_HELP, false},
      Option_Definition{"-d", "--duplicate", OPTION_DUPLICATE, false},
      Option_Definition{"-u", "--uniq", OPTION_UNIQ, false},
      Option_Definition{"-c", "--config", OPTION_CONFIG, true},
      Option_Definition{"-n", "--n_count", OPTION_NCOUNT, true},
      Option_Definition{"-r", "--rev", OPTION_REV, false}};

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
      Command_Definition{"history", COMMAND_HISTORY, true}};

  size_t opt_size = sizeof(option_defs) / sizeof(option_defs[0]);
  size_t com_size = sizeof(command_defs) / sizeof(command_defs[0]);

  Parse_Result result = parse_arguments(argc, argv, option_defs, opt_size,
                                        command_defs, com_size);
  std::string db_name = "dict/data_base.txt";

  Array<std::string> history = list_to_array(head);
  int n_count = history.size();
  bool rev_history = false;
  if (!(result.options.empty()))
  {
    for (Option const &option : result.options)
    {
      switch (option.id)
      {
      case OPTION_HELP:
        dict_help();
        break;
      case OPTION_CONFIG:
        std::cout << db_name << "\n";
        db_name = option.value;
        std::cout << db_name << "\n";
        break;
      case OPTION_NCOUNT:
        n_count = stoi(option.value);
        break;
      case OPTION_REV:
        rev_history = true;
        break;
      }
    }
  }

  if (!(result.commands.empty()))
  {
    for (Command const &command : result.commands)
    {
      if (command.id == COMMAND_HISTORY)
      {
        print_count_list(head, n_count, rev_history);
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
  Node<std::string> *history_beg = nullptr;
  while (getline(std::cin, line))
  {
    if (line == "q")
    {
      return;
    }
    Node<std::string> *new_command = new_node(line);
    insert_node(&history_beg, new_command);
    shell_main(line, dict, history_beg);
  }
}
