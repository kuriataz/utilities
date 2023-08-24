#pragma once

#include <cstdlib>
#include <string>
#include <iostream>
#include <array.hpp>
#include <vector>
#include <data.hpp>

struct Functions
{
    virtual void add(std::string, std::string) = 0;
    // void add(std::string, std::vector<std::string> description);

    virtual void remove(std::string) = 0;

    virtual void list() = 0;

    virtual void show(std::string) = 0;
};