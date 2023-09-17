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

Array<std::string> wrap_desc(std::string description)
{
    int desc_length = description.length();
    int wrap0 = 0;
    Array<std::string> descriptions;
    if (desc_length <= 60)
    {
        descriptions.push_back(description);
    }
    std::string new_desc;
    while (desc_length > 60)
    {
        new_desc = description.substr(wrap0, 60);
        descriptions.push_back(new_desc);
        wrap0 += 60;
        if (desc_length <= wrap0 + 60)
        {
            descriptions.push_back(description.substr(wrap0));
            break;
        }
    }
    return descriptions;
}

Array<std::string> wrap_word(std::string word)
{
    Array<std::string> words_arr = tokenize(word, " ");
    int length = 0;
    // for (int i = 0; i != words_arr.size(); i++)
    // {
    //     std::string line;
    //     words_arr[i]
    // }
    int word_length = word.length();
    int wrap0 = 0;
    Array<std::string> words;
    if (word_length <= 6)
    {
        words.push_back(word);
    }
    std::string new_word;
    while (word.length() > 6)
    {
        if (word.find(" ") == wrap0)
        {
            new_word = word.substr(wrap0 + 1, 6);
        }
        else
        {
            new_word = word.substr(wrap0, 6);
        }
        word = word.substr(6);
        words.push_back(new_word);
        // wrap0 += 6;
    }
    // if (word_length <= wrap0 + 6)
    {
        words.push_back(word.substr(wrap0));
        // break;
    }
    return words;
}

void pretty_print(Record record)
{
    int i = 1;
    int j = 1;
    Array<std::string> words = wrap_word(record.word);
    Array<std::string> descriptions = wrap_desc(record.description);
    std::cout << whitespaces(4 - 2) << record.id << " |  "
              << words[0] << whitespaces(7 - words[0].length()) << "| "
              << descriptions[0] << "\n";
    while (i != words.size() || j != descriptions.size())
    {
        if (i != words.size())
        {
            std::cout << whitespaces(4) << " |  "
            << words[i] << whitespaces(7 - words[i].length()) << "| ";
            i++;
        }
        else
        {
            std::cout << whitespaces(4) << " |  " << whitespaces(7) << "| ";
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
