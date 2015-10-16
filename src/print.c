#include <print.h>



void print_string(const char *s)
{
  printf("%s",s);
}



void print_incorrect_input()
{
  char out[STREAM_LENGTH] = {'\0'};

  strcat(out, "\n");
  strcat(out, "Incorrect input\n");

  print_string(out);
}

void print_choice()
{
  char out[STREAM_LENGTH] = {'\0'};
  
  strcat(out, "\n");
  strcat(out, "$ ");

  print_string(out);
}



void print_menu()
{
  char out[STREAM_LENGTH] = {'\0'};

  strcat(out, "\n");
  strcat(out, "==========================\n");
  strcat(out, " Welcome to warehouse 2.0\n");
  strcat(out, "==========================\n\n");

  strcat(out, "[A]dd an item\n");
  strcat(out, "[R]emove an item\n");
  strcat(out, "[E]dit an item\n");
  strcat(out, "[P]rint the warehouse\n");
  strcat(out, "Pa[C]k your trolley\n");
  strcat(out, "E[X]it\n");

  print_string(out);
}



void print_add_header()
{
  char out[STREAM_LENGTH] = {'\0'};
  
  strcat(out, "\n");
  strcat(out, "=============\n");
  strcat(out, " Add an item\n");
  strcat(out, "=============\n\n");

  print_string(out);
}



void print_remove_header()
{
  char out[STREAM_LENGTH] = {'\0'};

  strcat(out, "\n");
  strcat(out, "=============\n");
  strcat(out, " Remove item\n");
  strcat(out, "=============\n\n");

  print_string(out);
}



void print_edit_header()
{
  char out[STREAM_LENGTH] = {'\0'};

  strcat(out, "\n");
  strcat(out, "=============\n");
  strcat(out, " Edit item\n");
  strcat(out, "=============\n\n");

  print_string(out);
}



void print_warehouse_header()
{
  char out[STREAM_LENGTH] = {'\0'};

  strcat(out, "\n");
  strcat(out, "===========\n");
  strcat(out, " Warehouse\n");
  strcat(out, "===========\n\n");

  print_string(out);
}



void print_trolley_header()
{
  char out[STREAM_LENGTH] = {'\0'};

  strcat(out, "\n");
  strcat(out, "==============\n");
  strcat(out, " Pack Trolley\n");
  strcat(out, "==============\n\n");

  print_string(out);
}



void print_exit()
{
  char out[STREAM_LENGTH] = {'\0'};

  strcat(out, "\n");
  strcat(out, "==========\n");
  strcat(out, " Good bye\n");
  strcat(out, "==========\n\n");

  print_string(out);
}
