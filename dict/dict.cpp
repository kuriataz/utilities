#include <cstdlib>
#include <vector>
#include <string>
#include <dict.hpp>
#include <iostream>
#include <fstream>
#include <sort.hpp>
#include <uniq.hpp>
#include <methods.hpp>
#include <pretty_print.hpp>


void Dict::add(std::string &word, std::string &description)
{
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

    for (Record& record: data)
    {
        if (record.id != id)
        {
            new_data.push_back(record);
        }
    }
    data = new_data;
}


void Dict::select(std::string word)
{
    std::cout << "  ID |" << "  WORD   |" << " DESCRIPTION\n";
    for (int i = 0; i != data.size(); i++)
    {
        if (data[i].word == word)
        {
            pretty_print(data[i]);
        }
    }
}

void Dict::list()
{
    std::cout << "  ID |" << "  WORD   |" << " DESCRIPTION\n";
    for (int i = 0; i != data.size(); i++)
    {
        pretty_print(data[i]);
    }
}

void Dict::update(int id, std::string &column, std::string &new_value)
{
    // for (int i = 0; i != data.size(); i++)
    for (Record record : data)
    {
        if (record.id == id)
        {
            if (column == "word")
            {
                record.word = new_value;
            }
            else if (column == "description")
            {
                record.description = new_value;
            }
        }
    }
}

void Dict::connect(std::string &base_name)
{
    this->base_name = base_name;
    std::fstream base;
    base.open(base_name, std::ios::in);
    if (base_name == "")
    {
        std::cerr << "failed to connect\n";
        return;
    }
    get_data_from_base(base);
    base.close();
}

void Dict:: disconnect()
{
    std::fstream base;
    base.open(base_name, std::ios::out);
    send_data_to_base(base);
    base.close();
    base_name = "";
}

void Dict::get_data_from_base(std::fstream &db)
{
    std::string line;
    std::string max;
    getline(db, max);
    if (max == "")
    {
        max = "0";
    }
    max_id = std::stoi(max);
    while (getline(db, line))
    {
        Array<std::string> strings = tokenize(line, ",");
        std::string id = strings[0];
        std::string word = strings[1];
        std::string description = strings[2];
        Record record(word, description, std::stoi(id));
        data.push_back(record);
    }
}

void Dict::send_data_to_base(std::fstream &db)
{
    if (base_name == "")
    {
        std::cerr << "not connected to the base\n";
        return;
    }
    if (!(db.is_open()))
    {
        std::cerr << "couldn't open the file\n";
    }

    Record *begin = data.begin();
    Record *end = data.end();
    insertionSort<Record>(begin, end);
    db << std::to_string(max_id) << '\n';
    for (Record record : data)
    {
        db << record.id << "," << record.word << "," <<  record.description << '\n';
    }
}

void dict_help()
{
    std::cout << "DICT - program to keep words and their description\n\n"
              << "COMMANDS:\n"
              << "dict add 'WORD' 'DESCRIPTION'     - add a word and the description\n"
              << "dict remove ID                    - id of the record to be removed\n"
              << "dict list                         - list all words\n"
              << "dict select WORD                  - show all entries with given word\n"
              << "dict update ID COLUMN NEW_VALUE   - updates the column of given id's record with the new_value\n"
              << "dict shell                        - interactive mode for the db system, use q to quit\n";
}
