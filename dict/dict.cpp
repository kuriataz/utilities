#include <cstdlib>
#include <vector>
#include <string>
#include <dict.hpp>
#include <iostream>
#include <fstream>
#include <sort.hpp>
#include <uniq.hpp>
#include <methods.hpp>


void Dict::add(std::string word, std::string description)
{
    // std::string new_description;
    // new_description += description;
    Record new_record(word, description, max_id + 1);
    max_id++;
    data.push_back(new_record);
}

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

void Dict::remove(int id)
{
    Array<Record> new_data;
    std::string id_as_string = std::to_string(id);

    for (Record& record: data)
    {
        if (record.id != id_as_string)
        {
            new_data.push_back(record);
        }
    }
    data = new_data;
}

void Dict::select(std::string word)
{
    for (int i = 0; i != data.size(); i++)
    {
        if (data[i].word == word)
        {
            std::cout << data[i].word << pretty_print() << data[i].description << '\n';
        }
    }
}

void Dict::list()
{
    for (int i = 0; i != data.size(); i++)
    {
        std::cout << data[i].word << '\n';
    }
}

void Dict::update(std::string id, std::string column, std::string new_value)
{
    for (int i = 0; i != data.size(); i++)
    {
        if (data[i].id == id)
        {
            if (column == "word")
            {
                data[i].word = new_value;
            }
            else if (column == "description")
            {
                data[i].description = new_value;
            }
        }
    }
}

void Dict::get_data_from_base(std::fstream &base)
{
    if (!(base.is_open()))
    {
        std::cerr << "couldn't open the file\n";
    }
    std::string line;
    std::string max;
    getline(base, max);
    max_id = std::stoi(max);
    while (getline(base, line))
    {
        Array<std::string> strings = tokenize(line, ",");
        std::string id = strings[0];
        std::string word = strings[1];
        std::string description = strings[2];
        Record record(word, description, std::stoi(id));
        data.push_back(record);
    }
}

void Dict::send_data_to_base(std::fstream &base)
{
    if (!(base.is_open()))
    {
        std::cerr << "couldn't open the file\n";
    }

    Record *begin = data.begin();
    Record *end = data.end();
    insertionSort<Record>(begin, end);
    base << std::to_string(max_id) << '\n';
    for ( ; begin != end; begin++)
    {
        base << (*begin).id << "," << (*begin).word << "," <<  (*begin).description << '\n';
    }
}

void dict_help()
{
    std::cout << "DICT - program to keep words and their description\n\n"
              << "COMMANDS:\n"
              << "dict add WORD DESCRIPTION         - add a word and the description\n"
              << "dict remove ID                  - id of the record to be removed\n"
              << "dict list                         - list all words\n"
              << "dict select WORD                  - show all entries with given word\n"
              << "dict update ID COLUMN NEW_VALUE   - updates the column of given id's record with the new_value\n"
              << "dict shell                        - interactive mode for the db system, use q to quit\n";
}
