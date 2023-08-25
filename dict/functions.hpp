#pragma once

#include <cstdlib>
#include <string>
#include <iostream>
#include <array.hpp>
#include <vector>

struct Functions
{
    virtual void add(std::string, std::string) = 0;

    virtual void remove(std::string) = 0;

    virtual void list() = 0;

    virtual void show(std::string) = 0;
};