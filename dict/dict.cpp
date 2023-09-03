#include <cstdlib>
#include <vector>
#include <string>
#include <dict.hpp>
#include <iostream>
#include <fstream>
#include <sort.hpp>
#include <uniq.hpp>

void Dict::add(std::string word, std::string description)
{
    std::string new_description;
    new_description += " - ";
    new_description += description;
    Record new_record(word, new_description);
    data.push_back(new_record);
}

// doesnt work - might be problem with line#31 (Array)
void Dict::remove(std::string word)
{
    Array<Record> new_data;

    for (Record& record: data)
    {
        if (record.word != word)
        {
            new_data.push_back(record);
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
    bubbleSort<Record>(data.begin(), data.end());
    // find_uniq<Record>(data.begin(), data.end());
    base.close();
}

void Dict::send_data_to_base(std::fstream &base)
{
    if (!(base.is_open()))
    {
        std::cerr << "couldn't open the file\n";
    }

    Record *begin = data.begin();
    Record *end = data.end();
    bubbleSort<Record>(begin, end);
    for ( ; begin != end; begin++)
    {
        base << (*begin).word << (*begin).description << '\n';
    }
    // for (int i = 0; i != data.size(); i++)
    // {
    //     base << data[i].word << data[i].description << '\n';
    // }
    base.close();
}
