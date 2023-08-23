#pragma once

#include <cstdlib>
#include <string>
#include <iostream>
#include <array.hpp>
#include <vector>
#include <data.hpp>

void add(std::vector<std::string>, Data&);
// void add(std::string, std::vector<std::string> description);

void remove(std::string, Data&);

void list(Data&);

void show(std::string, Data&);