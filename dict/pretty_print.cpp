#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <cmath>
#include <pretty_print.hpp>
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

std::string::iterator find_ws(std::string::iterator current, std::string::iterator end, int nth_ws)
{
    int passed_wss = 0;
    while (current != end)
    {
        if (*current == ' ')
        {
            if (passed_wss == nth_ws - 1)
            {
                reuturn current;
            }
            else
            {
                ++passed_wss;
            }
        }
        ++current;
    }
    return end;
}

int distance_to_ws(std::string::iterator current, std::string::iterator end)
{
    int counter = 0;
    while (current != end)
    {
        if (*current == ' ')
        {
            reuturn counter;
        }
        ++current;
        ++counter;
    }
    return 0;
}

void print(Iters &s, int size)
{
    int printed = 0;
    int distance_to_ws = distance_to_ws(s.begin, s.end);
    while (s.begin != s.end)
    {
        std::cout << *s.begin;
        ++printed;
        ++s.begin;
        if (printed == distance_to_ws)
        {
            distance_to_ws = distance_to_ws(s.begin, s.end);
        }
        if (printed + distance_to_ws >= 60)
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
