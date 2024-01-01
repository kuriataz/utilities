#pragma once

#include <array.hpp>
#include <db_interface.hpp>
#include <list.hpp>

void shell(DB_Interface &);

void shell_main(std::string, DB_Interface &, Node<std::string> *);