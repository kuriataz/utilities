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

Data get_data_from_base(std::fstream &input)
{
    Data data_base;
    // std::ifstream input;
    // input.open(base);
    if (!(input.is_open()))
    {
        std::cerr << "couldn't open the file\n";
    }
    else
    {
        std::string word;
        while (input >> word)
        {
            Record new_record;
            if (word == "\n")
            {
                data_base.data.push_back(new_record);
                continue;
            }
            new_record.record.push_back(word);
        }
    }
    input.close();
    return data_base;
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
    // std::ofstream output;
    // output.open(base);
    if (!(output.is_open()))
    {
        std::cerr << "couldn't open the file\n";
    }
    else
    {
        std::string word;
        for (int i = 0; i != data_base.data.size(); i++)
        {
            for (int j = 0; j != data_base.data[i].record.size(); j++)
            {
                output << data_base.data[i].record[j] << " ";
            }
            output << '\n';
        }
    }
    // output.close();
}