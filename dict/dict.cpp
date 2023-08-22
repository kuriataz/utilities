#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <array.hpp>
#include <vector>

void add(std::string word, std::vector<std::string> description, std::ofstream &data_base)
{
    data_base << word << " - ";
    // std::string *begin = description.begin();
    // std::string *end = description.end();
    std::string *begin = &description[2];
    std::string *end = &description[description.size()];
    for ( ; begin != end; begin++)
    {
        data_base << *begin << " ";
    }
    data_base << std::endl;
}