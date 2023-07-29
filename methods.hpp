#pragma once

#include "options.hpp"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>
#include <string_view>
#include <vector>

void help();

// void reverse(std::vector<int> &ints);

void output(std::vector<int> &ints, std::string value);

void stable(std::vector<int> &ints);

void quick(std::vector<int> &ints);