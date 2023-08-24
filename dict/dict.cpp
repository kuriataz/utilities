#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <array.hpp>
#include <vector>
#include <data.hpp>

// void add(std::vector<std::string> record, std::ofstream &data_base)
// {
//     data_base << record[0] << " - ";
//     // std::string *begin = record.begin();
//     // std::string *end = record.end();
//     std::string *begin = &record[1];
//     std::string *end = &record[record.size()];
//     for ( ; begin != end; begin++)
//     {
//         data_base << *begin << " ";
//     }
//     data_base << std::endl;
// }

void add(std::vector<std::string> record_to_add, Data &data_base)
{
    Record to_data_base(record_to_add);
    // to_data_base.record.push_back(record_to_add[0]);
    // to_data_base.record.push_back("-");
    // data_base.data[data_base.data.size() - 1].record.push_back(record_to_add[0]);
    // data_base.data[data_base.data.size() - 1].record.push_back("-");
    // std::string *begin = record.begin();
    // std::string *end = record.end();
    // std::string *begin = &record_to_add[1];
    // std::string *end = &record_to_add[record_to_add.size()];
    // for ( ; begin != end; begin++)
    // {
    //     // data_base << *begin << " ";
    //     // data_base.data[data_base.data.size() - 1].record_to_add.push_back(*begin);
    //     to_data_base.record.push_back(*begin);
    // }
    data_base.data.push_back(to_data_base);
    // data_base << std::endl;
}

void remove(std::string word, Data &data_base)
{
    int size = data_base.data.size();
    Record *begin = &data_base.data[0];
    Record *end = &data_base.data[size];
    // Array<Record> data(data_base.data);

    for (int i = 0; i != size; i++)
    {
        if (data_base.data[i][0] == word)
        {
            data_base.data.erase(data_base.data.begin() + i);
        }
    }

    // std::ifstream data_base;
    // data_base.open(file);
    // std::ofstream temp;
    // temp.open("temp.txt");

    // std::string line;
    // while (getline(data_base, line))
    // {
    //     if (line != word)
    //     {
    //         temp << line << '\n';
    //     }
    // }
    // temp.close();
    // data_base.close();

    // const char * p = file.c_str();
    // remove(p);
    // rename("temp.txt", p);
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