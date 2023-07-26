#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
#include <string_view>
#include <algorithm>
#include "methods.hpp"
#include "sort_types.hpp"

void help()
{
    std::ifstream help_file;
    std::istream *help_stream = &help_file;
    help_file.open("help.txt");
    if (!help_file.is_open())
    {
    std::cerr << "Failed to open help.txt\n";
    return;
    }
    std::string help_output;
    std::string help_line;

    while (*help_stream)
    {
    if (!help_output.empty())
    {
        help_output.append("\n");
    }
    help_output.append(help_line);
    getline(*help_stream, help_line);
    }
    std::cout << help_output << std::endl;
}

void std::reverse(std::vector<int> &ints, bool is_sorted)
{
    if(!is_sorted)
    {
        bubbleSort(ints, ints.size());
    }
    int temp = 0;
    for (int i = 0; i < (ints.size() / 2) + 1; i++)
    {
        std::swap(ints[i], ints[ints.size() - i - 1]);
    }
}

void output(std::vector<int> &ints, std::string value, bool is_sorted)
{
    std::ofstream output_file;
    output_file.open(value);
    if (!output_file.is_open())
    {
        std::cerr << "wrong file\n";
        std::cout << value << std::endl;
    }
    else
    {
        if(!is_sorted)
        {
            bubbleSort(ints, ints.size());
        }
        for (int i = 0; i < ints.size(); i++)
        {
        output_file << ints.at(i) << std::endl;
        }
    }
    output_file.close();
}

void stable(std::vector<int> &ints)
{
    insertionSort(ints);
}

void quick(std::vector<int> &ints)
{
    int size = ints.size();
    quickSort(ints, 0, size - 1);
}