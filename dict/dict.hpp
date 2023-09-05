#pragma once

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <array.hpp>
#include <functions.hpp>


struct Record
{
    std::string id;
    std::string word;
    std::string description;

    Record() = default;

    Record(std::string word, std::string description, int max_id): word(word), description(description), id(std::to_string(max_id))
    {
        // id = max_id + 1;
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
    int max_id = 0;

    ~Dict() {}

    virtual void add(std::string, std::string);

    virtual void remove(int);
    virtual void remove(std::string);

    virtual void list();

    virtual void select(std::string);

    virtual void update(std::string, std::string, std::string);


    // virtual void select(Array<std::string>);

    void get_data_from_base(std::fstream&);
    void send_data_to_base(std::fstream&);
};


