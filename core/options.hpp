#pragma once

#include <cstdio>
#include <string>
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

struct Command_Definition
{
  std::string name;
  int32_t id = 0;
  bool flag = false;
};

struct Command
{
  int32_t id = 0;
  std::string value;

  Command(int32_t id): id(id){}

  Command(int32_t id, std::string value)
  {
    this->id = id;
    this->value = value;
  }
};

struct Parse_Result
{
  Array<Option> options;
  Array<Command> commands;
  Array<std::string> arguments;
};

// parse_arguments is a function that parses strings into Parse_Result
// parse_arguments takes also Option_Definition[] and optoinally Command_Definition[]
// to check if any of given strings is a command or an option
Parse_Result parse_arguments(int argc, char **argv, Option_Definition defs[], int size,
                            Command_Definition com_defs[], int com_size);

Parse_Result parse_arguments(int argc, Array<std::string> argv, Option_Definition defs[], int size,
                            Command_Definition com_defs[], int com_size);

Parse_Result parse_arguments(int argc, char **argv, Option_Definition defs[],
                             int size);

// array_to_string is a function that transforms given Array of strings to one string
std::string array_to_string(Array<std::string>);
