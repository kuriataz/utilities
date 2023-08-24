#pragma once

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <array.hpp>

struct Record
{
    std::vector<std::string> record;
    std::string word;
    std::string description;

    Record() = default;

    // Record(std::string word, std::vector<std::string> description): word(word), description(description){}
    // Record(std::vector<std::string> record): word(record[0])
    // {
    //     record.erase(record.begin());
    //     description = record;
    // }
    // Record(std::string word, std::string description): word(word), description(description){}
    Record(std::vector<std::string> record): record(record), word(record[0])
    {
        if (record.size() > 1)
        {
            description += " -";
            for (int i = 1; i != record.size(); i++)
            {
                description += " ";
                description += record[i];
            }
        }
    }

    Record(std::string record_as_string)
    {
        std::string minus = "-";
        size_t white_space = record_as_string.find(minus);
        word = record_as_string.substr(0, white_space - 1);
        description = record_as_string.substr(white_space -1);
        record.push_back(word);
        record.push_back(description);
    }

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
void get_data_from_base(Data&, std::fstream&);
void send_data_to_base(Data&, std::fstream&);
// void send_data_to_base(Data&, std::string);