#pragma once
#include <string.h>

#include <array.hpp>
#include <dict.hpp>
#include <list.hpp>

void shell(Dict&);

void shell_main(int, std::string, Dict&, Node<std::string>*);