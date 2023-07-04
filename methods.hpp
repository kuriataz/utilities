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

bool reverse(bool);

void output(std::string, std::string, bool);

void stable(std::string);

void quick(std::string);