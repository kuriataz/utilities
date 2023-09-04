#include <cstdio>
#include <fstream>
#include <iostream>
#include <options.hpp>
#include <sstream>
#include <string.h>
// #include <vector>
#include <array.hpp>


Parse_Result parse_arguments(int argc, char **argv, Option_Definition defs[],
                             int size)
{
  Parse_Result result;
  if (argc < 2)
  {
    return result;
  }
  for (int i = 1; i < argc; i++)
  {
    int options_added = 0;
    for (int j = 0; j < size; j++)
    {
      if ((strcmp(argv[i], defs[j].long_name.c_str()) == 0) ||
          (strcmp(argv[i], defs[j].short_name.c_str()) == 0))
      {
        if (defs[j].mandatory_argument == true)
        {
          Option new_option = Option(defs[j].id, argv[i + 1]);
          result.options.push_back(new_option);
          i++;
          options_added++;
          break;
        }
        else
        {
          Option new_option = Option(defs[j].id);
          result.options.push_back(new_option);
          options_added++;
          break;
        }
      }
    }
    if (options_added == 0)
    {
      result.arguments.push_back(argv[i]);
    }
  }
  return result;
}

Parse_Result parse_arguments(int argc, char **argv, Option_Definition defs[], int opt_size,
                             Command_Definition com_defs[], int com_size)
{
  Parse_Result result;
  if (argc < 2)
  {
    return result;
  }
  for (int i = 1; i < argc; i++)
  {
    int options_added = 0;
    for (int j = 0; j != opt_size; j++)
    {
      if ((strcmp(argv[i], defs[j].long_name.c_str()) == 0) ||
          (strcmp(argv[i], defs[j].short_name.c_str()) == 0))
      {
        if (defs[j].mandatory_argument == true)
        {
          Option new_option = Option(defs[j].id, argv[i + 1]);
          result.options.push_back(new_option);
          i++;
          options_added++;
          break;
        }
        else
        {
          Option new_option = Option(defs[j].id);
          result.options.push_back(new_option);
          options_added++;
          break;
        }
      }
    }
    int commands_added = 0;
    for (int j = 0; j != com_size; j++)
    {
      if((strcmp(argv[i], com_defs[j].name.c_str()) == 0))
      {
        // if(com_defs[j].flag == true)
        // {
        //   Command new_command = Command(com_defs[j].id, argv[i + 1]);
        //   result.commands.push_back(new_command);
        //   i++;
        //   commands_added++;
        //   break;
        // }
        // else if(com_defs[j].number_of_args != 0)
        // {

        //   Command new_command = Command(com_defs[j].id, argv[i + 1]);
        //   result.commands.push_back(new_command);
        //   i++;
        //   commands_added++;
        //   break;
        // }
        // else
        {
          Command new_command = Command(com_defs[j].id);
          result.commands.push_back(new_command);
          commands_added++;
          break;
        }
      }
    }
    if (options_added == 0 && commands_added == 0)
    {
      result.arguments.push_back(argv[i]);
    }
  }
  return result;
}

std::string array_to_string(Array<std::string> array)
{
  std::string result;
  std::string *begin = array.begin();
  std::string *end = array.end();
  for ( ; begin != end; begin++)
  {
    result += *begin;
  }
  return result;
}
