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

void reverse(bool is_rev);

void output(std::string &output_file_name, std::string value, bool is_output);

void stable(std::string &sort_type);

void quick(std::string &sort_type);