#include <cstdlib>
#include <vector>
#include <string>
#include <data.hpp>
#include <iostream>
#include <fstream>

// Data get_data_from_base(std::string base)
// {
//     Data data_base;
//     std::ifstream input;
//     input.open(base);
//     if (!(input.is_open()))
//     {
//         std::cerr << "couldn't open the file\n";
//     }
//     else
//     {
//         std::string word;
//         while (input >> word)
//         {
//             Record new_record;
//             if (word == "\n")
//             {
//                 data_base.data.push_back(new_record);
//                 continue;
//             }
//             new_record.record.push_back(word);
//         }
//     }
//     input.close();
//     return data_base;
// }

void get_data_from_base(Data &data_base, std::fstream &input)
{
    // std::ifstream input;
    // input.open(base);
    if (!(input.is_open()))
    {
        std::cerr << "couldn't open the file - get_data_from_base\n";
    }
    else
    {
        std::string word;
        while (getline(input, word))
        {
            Record new_record(word);
            data_base.data.push_back(new_record);
        }
        input.close();
    }
}

// void send_data_to_base(Data &data_base, std::string base)
// {
//     std::ofstream output;
//     output.open(base);
//     if (!(output.is_open()))
//     {
//         std::cerr << "couldn't open the file\n";
//     }
//     else
//     {
//         std::string word;
//         for (int i = 0; i != data_base.data.size(); i++)
//         {
//             for (int j = 0; j != data_base.data[i].record.size(); j++)
//             {
//                 output << data_base.data[i].record[j] << " ";
//             }
//             output << '\n';
//         }
//     }
//     output.close();
// }

void send_data_to_base(Data &data_base, std::fstream &output)
{
    if (!(output.is_open()))
    {
        std::cerr << "couldn't open the file - send_data_to_base\n";
    }
    else
    {
        for (int i = 0; i != data_base.data.size(); i++)
        {
            output << data_base.data[i].word;
            output << data_base.data[i].description << '\n';
        }
    }
}
