#pragma once

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <array.hpp>
#include <dict_commands.hpp>


struct Record
{
    std::string id;
    std::string word;
    std::string description;

    Record() = default;

    Record(std::string word, std::string description, int max_id): word(word), description(description), id(std::to_string(max_id))
    {

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

struct Dict : public Dict_Commands
{
    Array<Record> data;
    int max_id = 0;
    std::string base_name;

    ~Dict() {}

    virtual void add(std::string, std::string);

    virtual void remove(int);
    virtual void remove(std::string);

    virtual void list();

    virtual void select(std::string);

    virtual void update(std::string, std::string, std::string);

    virtual void connect(std::string&);

    virtual void disconnect();

    void get_data_from_base(std::fstream&);
    void send_data_to_base(std::fstream&);
};

void dict_help();
