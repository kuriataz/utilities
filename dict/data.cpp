#include <cstdlib>
#include <vector>
#include <string>
#include <data.hpp>
#include <iostream>
#include <fstream>


struct Dict : public Functions
{
    Dict() = default;

    Array<Record> data;

    void add(std::string word, std::string description)
    {
        Record new_record(word, description);
        data.push_back(new_record);
    }

    void remove(std::string word)
    {
        Array<Record> new_data;
        // Array<Record> data(data_base.data);

        for (int i = 0; i != data.size(); i++)
        {
            if (data[i].word != word)
            {
                new_data.push_back(data[i]);
            }
        }
        data = new_data;
    }
    void show(std::string word)
    {
        for (int i = 0; i != data.size(); i++)
        {
            if (data[i].word == word)
            {
                std::cout << data[i].word << data[i].description << '\n';
            }
        }
    }

    void list()
    {
        for (int i = 0; i != data.size(); i++)
        {
            std::cout << data[i].word << data[i].description << '\n';
        }
    }

    void get_data_from_base(std::fstream &base)
    {

    }

    void send_data_to_base(std::fstream &base)
    {

    }
};
