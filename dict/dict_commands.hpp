#pragma once

#include <cstdlib>
#include <string>
#include <iostream>
#include <array.hpp>
#include <vector>

struct Dict_Commands
{
    virtual ~Dict_Commands() = default;

    virtual void add(std::string&, std::string&) = 0;

    virtual void remove(int) = 0;

    virtual void list() = 0;

    virtual void select(std::string) = 0;

    virtual void update(int, std::string&, std::string&) = 0;

    virtual void show_history() = 0;

    virtual void connect(std::string&) = 0;

    virtual void disconnect() = 0;
};
