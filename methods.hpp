#pragma once

#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
#include <string_view>
#include "options.hpp"

void help();

// void reverse(std::vector<int> &ints);

void output(std::vector<int> &ints, std::string value);

void stable(std::vector<int> &ints);

void quick(std::vector<int> &ints);