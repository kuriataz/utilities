#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <dict.hpp>

std::string whitespaces(int length)
{
    std::string whitespaces;
    if (length > 0)
    {
        for (int i = 0; i != length; i++)
        {
            whitespaces += " ";
        }
    }
    return whitespaces;
}

struct Iters
{
    std::string::iterator begin;
    std::string::iterator end;

    bool finished = false;
};

void print(Iters &s, int size)
{
    int printed = 0;
    while (s.begin != s.end)
    {
        std::cout << *s.begin;
        ++printed;
        ++s.begin;
        if (printed == size)
        {
            break;
        }
    }
    if (s.begin == s.end)
    {
        s.finished = true;
    }
    std::cout << whitespaces(size - printed);
}

void pretty_print(Record record, int max_id_length, int max_word_length)
{
    std::string id_as_string = std::to_string(record.id);
    Iters id{id_as_string.begin(), id_as_string.end()};
    Iters word{record.word.begin(), record.word.end()};
    Iters desc{record.description.begin(), record.description.end()};

    while (!(id.finished && word.finished && desc.finished))
    {
        print(id, max_id_length + 1);
        std::cout << "|";
        print(word, max_word_length + 1);
        std::cout << "|";
        print(desc, 60);
        std::cout << "\n";
    }
}
