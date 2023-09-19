#pragma once

#include <iostream>
#include <sstream>
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

Array<std::string> wrap(std::string const &input, size_t width, size_t indent = 0)
{
    std::istringstream in(input);
    Array<std::string> output;

    output.push_back(whitespaces(indent));
    size_t curr = indent;
    std::string word_to_output;
    std::string word;
    while (in >> word)
    {
        if (curr + word.size() > width)
        {
            output.push_back(word_to_output);
            word_to_output = "";
            curr = indent;
        }
        word_to_output += word;
        word_to_output += " ";
        curr = curr + word.size() + 1;
    }
    if (!(word_to_output == ""))
    {
        output.push_back(word_to_output);
    }
    return output;
}

void pretty_print(Record record)
{
    int id_length = 1;
    if (record.id > 9)
    {
        id_length++;
    }
    if (record.id > 99)
    {
        id_length++;
    }
    constexpr int white_before_word = 4;
    constexpr int white_after_word = 7;
    Array<std::string> words = wrap(record.word, 6);
    Array<std::string> descriptions = wrap(record.description, 60);
    std::cout << whitespaces(white_before_word - id_length) << record.id << " |  "
              << words[1] << whitespaces(white_after_word - words[1].length()) << "| "
              << descriptions[1] << "\n";
    int i = 2;
    int j = 2;
    while (i != words.size() || j != descriptions.size())
    {
        if (i != words.size())
        {
            std::cout << whitespaces(white_before_word) << " |  "
            << words[i] << whitespaces(white_after_word - words[i].length()) << "| ";
            i++;
        }
        else
        {
            std::cout << whitespaces(white_before_word) << " |  " << whitespaces(white_after_word) << "| ";
        }

        if (j != descriptions.size())
        {
            std::cout << descriptions[j] << "\n";
            ++j;
        }
        else
        {
            std::cout << "\n";
        }
    }
}
