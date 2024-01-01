#include <mariadb_dictionary.hpp>

select(name)
{
  query = "select * from words where value = " + name;
  connection.query(query);
  // Parse results
  return ...;
}