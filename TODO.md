, in description
what with words longer than 6 chars? should they be cut or the space for WORD should be as big as for DESCRIPTION?


dict add [OPTION] WORD DESCRIPTION - add a word and the description
dict remove [OPTION] WORD          - remove the word and its description
dict list [OPTION]                 - list all words
dict show [OPTION] WORD            - show the record (word and description)



- subcommand 'list' for listing keys keys (words) with flags for unique and duplicates.
- subcommand 'select' all entries with given key (word).
- add column 'id' which is auto_increment.
- subcommand 'remove' taking id of the record to be removed.
- subcommand 'update' taking id, column and new value. any column apart from the auto_increment
  column may be updated.
- pretty print the table to the terminal so that the columns are automatically adjusted to fit the
  widest element. string columns should be wrapped at 40 chars.
- use pretty print to format the results of 'list' and 'select'.
- implement interactive mode for the db system accessed via subcommand 'shell'. database is kept
  in-memory until the interactive session is closed. all subcommands except shell are executable in
  the interactive mode. when used within shell, the shell command should inform the user that it is
  not possible to nest shells. shell must have command history.
- query execution via subcommand 'query'. grammar:
```
  primary-expression -> string | integer
  field-expression -> identifier '.' identifier
  condition-expression -> primary-expression | field-expression
  condition-operator -> '==' | '!=' | '>' | '<' | '>=' | '<='
  condition-logical -> 'and' | 'or'
  condition-base -> condition-expression condition-operator condition-expression
  condition -> condition-base | condition-base condition-logical condition
  identifier-list -> identifier | identifier ',' identifier-list
  primary-expression-list -> primary-expression | primary-expression ',' primary-expression-list
  tuple -> '(' primary-expression-list ')'
  tuple-list -> tuple | tuple ',' tuple-list
  select-query -> 'select' identifier-list 'from' identifier ['where' condition]
  insert-query -> 'insert' ['into'] identifier 'values' tuple-list
```
