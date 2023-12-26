#pragma once

#include <cmath>
#include <cstdlib>
#include <dict.hpp>
#include <iostream>
#include <sstream>
#include <string>

struct Iters
{
  std::string::iterator begin;
  std::string::iterator end;

  bool finished = false;
};

std::string whitespaces(int length);

std::string::iterator find_ws(std::string::iterator current,
                              std::string::iterator end, int nth_ws);

int distance_to_ws(std::string::iterator current, std::string::iterator end);

void print(Iters &s, int size);

// void pretty_print(Record record, int max_id_length, int max_word_length);