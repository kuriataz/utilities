#pragma once

#include <cstdlib>
#include <vector>
#include <string>
#include <array.hpp>

struct Record
{
    std::vector<std::string> record;
    std::string word;
    // std::string description;

    Record() = default;

    // Record(std::string word, std::vector<std::string> description): word(word), description(description){}
    // Record(std::vector<std::string> record): word(record[0])
    // {
    //     record.erase(record.begin());
    //     description = record;
    // }
    // Record(std::string word, std::string description): word(word), description(description){}
    Record(std::vector<std::string> record): record(record), word(record[0]){}

    std::string& operator[] (int index)
    {
        return record[index];
    }
};

struct Data
{
    std::vector<Record> data;
    // Array<Record> data;

    Data() = default;
    // Data(std::vector<Record> data): data(data){}
};

// Data get_data_from_base(std::string);
Data get_data_from_base(std::fstream&);
void send_data_to_base(Data&, std::fstream&);
// void send_data_to_base(Data&, std::string);