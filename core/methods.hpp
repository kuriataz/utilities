#pragma once

#include <cstdio>
#include <fstream>
#include <iostream>
#include <options.hpp>
#include <sstream>
#include <string.h>
#include <vector>
#include <iterator.hpp>

void help();

void output(int*, int*, std::ostream&);
void output(iterator<int>, iterator<int>, std::ostream&);

std::string pretty_print(int);

Array<std::string> tokenize(std::string, std::string);

