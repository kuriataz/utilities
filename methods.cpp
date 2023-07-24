#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
#include <string_view>
#include "methods.hpp"


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

void reverse(bool is_reverse)
{
    is_reverse = true;
}

void output(std::string &output_file_name, std::string value, bool is_output)
{
    is_output = true;
    output_file_name = value;
}

void stable(std::string &sort_type)
{
    sort_type = "insertSort";
}

void quick(std::string &sort_type)
{
    sort_type = "quickSort";
}