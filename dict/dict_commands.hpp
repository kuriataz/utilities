#pragma once

#include <cstdlib>
#include <string>
#include <iostream>
#include <array.hpp>
#include <vector>

struct Dict_Commands
{
    virtual ~Dict_Commands() = default;

    virtual void add(std::string, std::string) = 0;

    virtual void remove(int) = 0;

    virtual void list() = 0;

    virtual void select(std::string) = 0;

    virtual void update(std::string, std::string, std::string) = 0;

    virtual void connect(std::string&) = 0;

    virtual void disconnect() = 0;
};
