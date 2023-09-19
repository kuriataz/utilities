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

    // os << whitespaces(indent);
    output.push_back(whitespaces(indent));
    size_t curr = indent;
    std::string word_to_output;
    std::string word;
    while (in >> word)
    {
        if (curr + word.size() > width)
        {
            // os << "\n" << whitespaces(indent);
            output.push_back(word_to_output);
            word_to_output = "";
            curr = indent;
        }
        // os << word << " ";
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

// Array<std::string> wrap_desc(std::string description)
// {
//     const char *desc_as_c = description.c_str();
//     int desc_length = description.length();
//     int wrap0 = 0;
//     Array<std::string> descriptions;
//     if (desc_length <= 60)
//     {
//         descriptions.push_back(description);
//         return descriptions;
//     }
//     std::string new_desc;
//     int i = 0;
//     int white1 = 0;
//     int white2 = description.find(" ");
//     while (desc_length > 60)
//     {
//         while (i != 60)
//         {
//             if (desc_as_c[i] == ' ')
//             {
//                 white1 = white2;
//                 white2 = i;
//             }
//             i++;
//         }

//         new_desc = description.substr(wrap0, 60);
//         descriptions.push_back(new_desc);
//         wrap0 += 60;
//         if (desc_length <= wrap0 + 60)
//         {
//             descriptions.push_back(description.substr(wrap0));
//             break;
//         }
//     }
//     return descriptions;
// }
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
    int id_length = 1;
    if (record.id > 9)
    {
        id_length++;
    }
    if (record.id > 99)
    {
        id_length++;
    }
    Array<std::string> words = wrap(record.word, 6);
    Array<std::string> descriptions = wrap(record.description, 60);
    std::cout << whitespaces(4 - id_length) << record.id << " |  "
              << words[1] << whitespaces(7 - words[1].length()) << "| "
              << descriptions[1] << "\n";
    int i = 2;
    int j = 2;
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
