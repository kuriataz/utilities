#pragma once

#include <cstdio>
#include <fstream>
#include <iostream>
#include <options.hpp>
#include <sstream>
#include <string.h>
#include <vector>

void help();

// void reverse(std::vector<int> &ints);

void output(std::vector<int> &ints, std::string value);

void stable(std::vector<int> &ints);

void quick(std::vector<int> &ints);
