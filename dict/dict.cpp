#include <cstdlib>
#include <vector>
#include <string>
#include <dict.hpp>
#include <iostream>
#include <fstream>
#include <sort.hpp>
#include <uniq.hpp>

Array<std::string> tokenize(std::string s, std::string del)
{
    Array<std::string> strings;
    int start, end = -1*del.size();
    do {
        start = end + del.size();
        end = s.find(del, start);
        // std::cout << s.substr(start, end - start) << std::endl;
        strings.push_back(s.substr(start, end - start));

    } while (end != -1);

    return strings;
}

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

void Dict::select(std::string word)
{
    for (int i = 0; i != data.size(); i++)
    {
        if (data[i].word == word)
        {
            std::cout << data[i].word << data[i].description << '\n';
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
        // size_t dash2 = line.find(",");
        // size_t dash = line.find(",");
        // std::cout << dash << " - dash, dash2 - " << dash2 << "\n";
        // if (dash == std::string::npos)
        // {
        //     std::cerr << "error: - missing\n";
        //     return;
        // }

        Array<std::string> strings = tokenize(line, ",");
        std::string id = strings[0];
        std::string word = strings[1];
        // std::string word = line.substr(dash2 - 1, dash - 1);
        std::string description = strings[2];
        // std::string description = line.substr(dash - 1);
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
