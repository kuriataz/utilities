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
    int id_length = trunc(log10(record.id));
    constexpr int white_before_word = 4;
    constexpr int white_after_word = 7;
    Array<std::string> words = wrap(record.word, 6);
    Array<std::string> descriptions = wrap(record.description, 60);


    int i = 1;
    int j = 1;
    int w_size = words.size();
    int d_size = descriptions.size();
    bool print_id = false;
    std::cout << w_size << " - w_size\n";
    std::cout << d_size << " - d_size\n";
    if (w_size == i && d_size == j)
    {
        std::cout << whitespaces(white_before_word - 1 - id_length) << record.id
                  << " |  " << whitespaces(white_after_word) << "| \n";
    }
    while (i < w_size || j < d_size)
    {
        if (print_id)
        {
            std::cout << whitespaces(white_before_word);
        }
        else
        {
            std::cout << whitespaces(white_before_word - 1 - id_length) << record.id;
            print_id = true;
        }
        if (i < w_size)
        {
            std::cout << " |  " << words[i] << whitespaces(white_after_word - words[i].length()) << "| ";
            i++;
        }
        else if (i == w_size)
        {
            std::cout << " |  " << whitespaces(white_after_word) << "| ";
        }
        else
        {
            std::cout << whitespaces(white_before_word) << " |  " << whitespaces(white_after_word) << "| ";
        }

        if (j < d_size)
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
