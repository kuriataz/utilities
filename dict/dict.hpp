#pragma once

#include <cmath>
#include <cstdlib>
#include <string>

#include <array.hpp>
#include <db_interface.hpp>
#include <iterator.hpp>

int longest_word_lenght(std::string s);

struct Record
{
  int id = 0;
  size_t id_length = trunc(log10(id));
  std::string word;
  size_t word_length = word.length();
  std::string description;
  size_t desc_length = description.length();

  Record() = default;

  Record(std::string word, std::string description, int max_id)
      : word(word), description(description), id(max_id)
  {
  }

  bool operator>(const Record &obj) { return this->word > obj.word; }
  bool operator<(const Record &obj) { return this->word < obj.word; }
  bool operator!=(const Record &obj) { return this->word != obj.word; }
  bool operator==(const Record &obj) { return this->word == obj.word; }
};

struct Dict : public DB_Interface
{
  Array<Record> data;
  int max_id = 0;
  std::string db_name = "dict/data_base.txt";
  iterator<Record> begin_of_data = data.begin();
  iterator<Record> end_of_data = data.end();

  ~Dict() {}

  virtual void add(std::string &word, std::string &description);

  virtual void remove(int id);
  virtual void remove(std::string word);

  virtual void list();

  virtual void select(std::string word);

  virtual void update(int, std::string &column,
                      std::string &new_value) override;

  [[nodiscard]] bool connect(std::string &db_name);
  bool new_connect(std::string &db_name);

  void disconnect();

  void get_data_from_base(std::fstream &db);
  void send_data_to_base(std::fstream &db);
};

void pretty_print(Record record, int max_id_length, int max_word_length);

void dict_help();
