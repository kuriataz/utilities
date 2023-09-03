#pragma once

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <array.hpp>
#include <functions.hpp>


struct Record
{
    std::string word;
    std::string description;

    Record() = default;

    Record(std::string word, std::string description): word(word), description(description)
    {
        // this->description += " - ";
        // this->description += description;
    }

    bool operator> (const Record& obj)
    {
        return this->word > obj.word;
    }
    bool operator< (const Record& obj)
    {
        return this->word < obj.word;
    }
    bool operator!= (const Record& obj)
    {
        return this->word != obj.word;
    }
    bool operator== (const Record& obj)
    {
        return this->word == obj.word;
    }
};

struct Dict : public Functions
{
    Array<Record> data;

    ~Dict() {}

    virtual void add(std::string, std::string);

    virtual void remove(std::string);

    virtual void list();

    virtual void show(std::string);

    void get_data_from_base(std::fstream&);
    void send_data_to_base(std::fstream&);
};


