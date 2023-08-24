#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <array.hpp>
#include <vector>
#include <data.hpp>

void add(std::vector<std::string> record_to_add, Data &data_base)
{
    Record to_data_base(record_to_add);
    data_base.data.push_back(to_data_base);
}

void remove(std::string word, Data &data_base)
{
    std::vector<Record> new_data;
    // Array<Record> data(data_base.data);

    for (int i = 0; i != data_base.data.size(); i++)
    {
        if (data_base.data[i].record[0].compare(word) != 0)
        {
            new_data.push_back(data_base.data[i]);
        }
    }

    data_base.data = new_data;
}

void show(std::string word, Data &data_base)
{
    int size = data_base.data.size();
    Record *begin = &data_base.data[0];
    Record *end = &data_base.data[size];
    // Array<Record> data(data_base.data);

    std::cout << "HERE\n";

    for (int i = 0; i != size; i++)
    {
        if (data_base.data[i][0] == word)
        {
            std::vector<std::string> record = data_base.data[i].record;
            std::string *begin = &record[0];
            std::string *end = &record[record.size()];
            for ( ; begin != end; begin++)
            {
                // data_base << *begin << " ";
                std::cout << *begin << " ";
            }
            std::cout << '\n';
        }
    }
}

void list(Data &data_base)
{
    int size = data_base.data.size();
    for (int i = 0; i != size; i++)
    {
        std::vector<std::string> record = data_base.data[i].record;
        std::string *begin = &record[0];
        std::string *end = &record[record.size()];
        for ( ; begin != end; begin++)
        {
            // data_base << *begin << " ";
            std::cout << *begin << " ";
        }
        std::cout << '\n';

    }
}