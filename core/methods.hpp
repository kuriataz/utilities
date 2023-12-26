#pragma once

#include <cstdio>
#include <iostream>
#include <options.hpp>
#include <iterator.hpp>

void help();

void output(int*, int*, std::ostream&);
void output(iterator<int>, iterator<int>, std::ostream&);

Array<std::string> tokenize(std::string, std::string);

