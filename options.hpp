#pragma once

#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
#include <string_view>


struct Option_Definition
{
  std::string short_name;
  std::string long_name;
  int32_t id = 0;
  bool mandatory_argument = false;
};

struct Option
{
  int32_t id = 0;
  std::string value;

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
};


Parse_Result parse_arguments(int argc, char **argv, const Option_Definition defs[]);

