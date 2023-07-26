#pragma once

#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
#include <string_view>
#include "options.hpp"

void normal(std::vector<int> ints);

void help();

void reverse(std::vector<int> &ints, bool is_sorted);

void output(std::vector<int> &ints, std::string value, bool is_sorted);

void stable(std::vector<int> &ints);

void quick(std::vector<int> &ints);