#include <cstdlib>
#include <vector>
#include <string>
#include <dict.hpp>
#include <iostream>
#include <fstream>

void Dict::add(std::string word, std::string description)
{
    std::string new_description;
    new_description += " - ";
    new_description += description;
    Record new_record(word, new_description);
    data.push_back(new_record);
}

void Dict::remove(std::string word)
{
    Array<Record> new_data;
    // Array<Record> data(data_base.data);

    for (int i = 0; i != data.size(); i++)
    {
        if (data[i].word != word)
        {
            new_data.push_back(data[i]);
        }
    }
    data = new_data;
}
void Dict::show(std::string word)
{
    for (int i = 0; i != data.size(); i++)
    {
        if (data[i].word == word)
        {
            std::cout << data[i].word << data[i].description << '\n';
        }
    }
}

void Dict::list()
{
    for (int i = 0; i != data.size(); i++)
    {
        std::cout << data[i].word << data[i].description << '\n';
    }
}

void Dict::get_data_from_base(std::fstream &base)
{
    if (!(base.is_open()))
    {
        std::cerr << "couldn't open the file\n";
    }
    std::string line;
    while (getline(base, line))
    {
        size_t dash = line.find("-");
        if (dash == std::string::npos)
        {
            std::cerr << "error: - missing\n";
            return;
        }
        std::string word = line.substr(0, dash - 1);
        std::string description = line.substr(dash - 1);
        Record record(word, description);
        data.push_back(record);
    }
    base.close();
}

void Dict::send_data_to_base(std::fstream &base)
{
    if (!(base.is_open()))
    {
        std::cerr << "couldn't open the file\n";
    }
    for (int i = 0; i != data.size(); i++)
    {
        base << data[i].word << data[i].description << '\n';
    }
    base.close();
}
