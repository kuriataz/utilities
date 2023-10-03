#pragma once

#include <cstdlib>
#include <string>
#include <iostream>
#include <array.hpp>
#include <vector>

struct DB_Interface
{
    virtual ~DB_Interface() = default;

    virtual void add(std::string&, std::string&) = 0;

    virtual void remove(int) = 0;

    virtual void list() = 0;

    virtual void select(std::string) = 0;

    virtual void update(int, std::string&, std::string&) = 0;
};
