#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
// #include <boost/program_options.hpp>

// using namespace boost::program_options;

void bubbleSort(std::vector<int> &vec, int n)
{
  int i, j;
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (vec.at(j) > vec.at(j + 1))
      {
        int temp = vec.at(j);
        vec[j] = vec.at(j + 1);
        vec[j + 1] = temp;
      }
    }
  }
}

std::vector<int> getNumberFromString(std::string s)
{
  std::vector<int> numbers;
  std::stringstream stream;
  stream << s;
  std::string temp_str;

  while (!stream.eof())
  {
    int temp_int;
    // stream >> temp_str;
    if (stream >> temp_int)
    {
      numbers.push_back(temp_int);
    }
    temp_str = "";
  }
  return numbers;
}

int main(int argc, char **argv)
{
  // TODO: Add options:
  //        -h, --help
  //        -r, --reverse
  //        -o, --output  FILE
  // Option{"-o", "--output", 3}

  /*try
  {
      options_description desc{"Options"};
      desc.add_options()
      ("help,h", "Help screen");

      variables_map vm;
      store(parse_command_line(argc, argv, desc), vm);
      notify(vm);

      if (vm.count("help"))
      std::cout << desc << '\n';
  }
  catch (const error &ex)
  {
      std::cerr << ex.what() << '\n';
  }*/

  std::string file_name;
  std::istream *stream = &std::cin;
  std::ifstream file;
  if (argc > 1)
  {
    std::string arg(argv[1]);
    file.open(arg);
    if (!file.is_open())
    {
      std::cerr << "Couldn't open file\n";
      return 1;
    }
    stream = &file;
  }

  std::string input;
  std::string input_line;
  while (*stream)
  {
    getline(*stream, input_line);
    input.append(" ");
    input.append(input_line);
  }

  std::vector<int> ints = getNumberFromString(input);

  bubbleSort(ints, ints.size());

  for (int i = 0; i < ints.size(); i++)
  {
    std::cout << ints.at(i) << std::endl;
  }

  return 0;
}