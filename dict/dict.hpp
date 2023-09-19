#pragma once

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <array.hpp>
#include <dict_commands.hpp>


struct Record
{
    int id = 0;
    std::string word;
    std::string description;

    Record() = default;

    Record(std::string word, std::string description, int max_id): word(word), description(description), id(max_id)
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

    virtual void add(std::string &word, std::string &description);

    virtual void remove(int id);
    virtual void remove(std::string word);

    virtual void list();

    virtual void select(std::string word);

    virtual void update(int, std::string &column, std::string &new_value);

    virtual void connect(std::string &base_name);

    virtual void disconnect();

    void get_data_from_base(std::fstream &db);
    void send_data_to_base(std::fstream &db);
};

void dict_help();
