#pragma once

#include <iostream>
#include <string>
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

std::string wrap_desc(std::string description)
{
    int desc_length = description.length();
    int wrap0 = 0;
    int wrap1 = 60;
    std::string new_desc;
    if (desc_length <= wrap1)
    {
        new_desc = description;
    }
    while (desc_length > wrap1)
    {
        new_desc = description.substr(wrap0, wrap1);
        new_desc += whitespaces(16);
        new_desc += "\n";
        wrap0 += 60;
        wrap1 += 60;
        if (desc_length <= wrap1)
        {
            new_desc += whitespaces(17);
            new_desc += description.substr(wrap0);
        }
    }
    return new_desc;
}

std::string wrap_word(std::string word)
{
    int word_length = word.length();
    int wrap0 = 0;
    int wrap1 = 6;
    int spaces_left = 5 - (word_length % 6);
    std::string new_word;
    if (word_length <= wrap1)
    {
        new_word = word;
    }
    while (word_length > wrap1)
    {
        new_word += word.substr(wrap0, wrap1);
        new_word += "|";
        new_word += whitespaces(8);
        new_word += "\n";
        wrap0 += 6;
        wrap1 += 6;
        if (word_length <= wrap1)
        {
            new_word += whitespaces(5);
            new_word += "|  ";
            new_word += word.substr(wrap0);
        }
    }
    new_word += whitespaces(spaces_left);
    return new_word;
}

void pretty_print(Record record)
{
  std::cout << whitespaces(4 - record.id.length()) << record.id << " |  "
            << record.word << whitespaces(4 - record.word.length()) << " | "
            << wrap_desc(record.description) << "\n";
}
