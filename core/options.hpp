#pragma once

#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>
#include <string_view>
#include <vector>
#include <array.hpp>

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
  Option(int32_t id) { this->id = id; }

  Option(int32_t id, std::string value)
  {
    this->id = id;
    this->value = value;
  }
};

struct Parse_Result
{
  Array<Option> options;
  Array<std::string> arguments;
  // std::vector<Option> options;
  // std::vector<std::string> arguments;
};

Parse_Result parse_arguments(int argc, char **argv, Option_Definition defs[],
                             int size);

std::string array_to_string(Array<std::string>);
