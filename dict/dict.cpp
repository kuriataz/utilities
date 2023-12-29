#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

// #include <conncpp.hpp>

#include <array.hpp>
#include <dict.hpp>
#include <iterator.hpp>
#include <methods.hpp>
#include <pretty_print.hpp>
#include <sort.hpp>
#include <uniq.hpp>

void Dict::add(std::string &word, std::string &description)
{
  Record new_record(word, description, max_id + 1);
  max_id++;
  data.push_back(new_record);
}

void Dict::remove(std::string word)
{
  Array<Record> new_data;

  for (Record &record : data)
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

  for (Record &record : data)
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
  int max_id_length = 2;
  int max_word_length = 0;
  int max_desc_length = 0;
  for (Record &record : data)
  {
    if (max_id_length < record.id_length)
    {
      max_id_length = record.id_length;
    }

    if (max_word_length < record.word_length)
    {
      max_word_length = record.word_length;
    }
  }

  //- 1 because before first | must be (max_id_length - "ID" length(2))
  // whitespaces
  std::cout << "ID "
            << whitespaces(max_id_length - 2)
            //- 3 because before first | must be (max_word_length - "WORD"
            // length(4)) whitespaces
            << "|WORD  " << whitespaces(max_word_length - 4)
            << "|DESCRIPTION\n";
  for (Record &record : data)
  {
    if (record.word == word)
    {
      pretty_print(record, max_id_length, max_word_length);
    }
  }
}

void Dict::list()
{
  int max_id_length = 2;
  int max_word_length = 0;
  int max_desc_length = 0;
  for (Record &record : data)
  {
    if (max_id_length < record.id_length)
    {
      max_id_length = record.id_length;
    }

    if (max_word_length < record.word_length)
    {
      max_word_length = record.word_length;
    }
  }

  //- 1 because before first | must be (max_id_length - "ID" length(2))
  // whitespaces
  std::cout << "ID "
            << whitespaces(max_id_length - 2)
            // must be (max_word_length - "WORD"
            // length(4)) whitespaces
            << "|WORD  " << whitespaces(max_word_length - 4)
            << "|DESCRIPTION\n";
  for (Record &record : data)
  {
    pretty_print(record, max_id_length, max_word_length);
  }
}

void Dict::update(int id, std::string &column, std::string &new_value)
{
  std::string ws(" \t\f\v\n\r");
  for (Record &record : data)
  {
    if (record.id == id)
    {
      if (column == "word" || column == "WORD")
      {
        record.word = new_value;
        std::size_t found = record.word.find_last_not_of(ws);
        if (found != std::string::npos)
        {
          record.word.erase(found + 1);
        }
      }
      else if (column == "description" || column == "DESCRIPTION")
      {
        record.description = new_value;
        std::size_t found = record.description.find_last_not_of(ws);
        if (found != std::string::npos)
        {
          record.description.erase(found + 1);
        }
      }
    }
  }
}

bool Dict::connect(std::string &db_name)
{
  this->db_name = db_name;
  std::fstream db;
  db.open(db_name, std::ios::in);
  if (db_name == "")
  {
    std::cerr << "failed to connect\n";
    return false;
  }
  get_data_from_base(db);
  db.close();
  return true;
}
// bool Dict::new_connect(std::string &db_name)
// {
//   // Instantiate Driver
//   sql::Driver *driver = sql::mariadb::get_driver_instance();

//   // Configure Connection
//   sql::SQLString url("jdbc:mariadb://localhost:3306/table");
//   sql::Properties properties(
//       {{"user", "app_user"}, {"password", "Password123!"}});

//   // Establish Connection
//   std::unique_ptr<sql::Connection> conn(driver->connect(url, properties));
// }

void Dict::disconnect()
{
  std::fstream db;
  db.open(db_name, std::ios::out);
  send_data_to_base(db);
  db.close();
  db_name = "";
}

// bool commit

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
  if (db_name == "")
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
    db << record.id << "," << record.word << "," << record.description << '\n';
  }
  // tried to make flags for unique and duplicate working for list command...
  // for ( ; begin_of_data != end_of_data; ++begin_of_data)
  // {
  //     db << (*begin_of_data).id << "," << (*begin_of_data).word << "," <<
  //     (*begin_of_data).description << '\n';
  // }
}

void pretty_print(Record record, int max_id_length, int max_word_length)
{
  std::string id_as_string = std::to_string(record.id);
  Iters id{id_as_string.begin(), id_as_string.end()};
  Iters word{record.word.begin(), record.word.end()};
  Iters desc{record.description.begin(), record.description.end()};

  while (!(id.finished && word.finished && desc.finished))
  {
    print(id, max_id_length + 1);
    std::cout << "|";
    print(word, max_word_length + 2);
    std::cout << "|";
    print(desc, 60);
    std::cout << "\n";
  }
}

void dict_help()
{
  std::cout
      << "DICT - program to keep words and their description\n\n"
      << "COMMANDS:\n"
      << "dict add 'WORD' 'DESCRIPTION'     - add a word and the description\n"
      << "dict remove ID                    - id of the record to be removed\n"
      << "dict list                         - list all words\n"
      << "dict select WORD                  - show all entries with given "
         "word\n"
      << "dict update ID COLUMN NEW_VALUE   - updates the column of given id's "
         "record with the new_value\n"
      << "dict shell                        - interactive mode for the db "
         "system, use q to quit\n";
}
