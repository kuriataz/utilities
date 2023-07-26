#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
#include <string_view>
#include "options.hpp"


/*struct Option_Definition
{
  std::string_view short_name;
  std::string_view long_name;
  int32_t id = 0;
  bool mandatory_argument = false;
};*/

/*struct Option
{
  int32_t id = 0;
  std::string_view value;

  public:
  Option(int32_t id)
  {
    this->id = id;
  }
  Option(int32_t id, std::string value)
  {
    this->id = id;
    this->value = value;
  }
};

struct Parse_Result
{
  std::vector<Option> options;
  std::vector<std::string_view> arguments;
};*/


Parse_Result parse_arguments(int argc, char **argv, Option_Definition defs[], int size)
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
      if ((strcmp(argv[i], defs[j].long_name.c_str()) == 0) || (strcmp(argv[i], defs[j].short_name.c_str()) == 0))
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
