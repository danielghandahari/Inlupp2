#define CORRECT_INPUT "AREPCX"

#include <io.h>



char get_menu_choice(char *prompt)
{
  char c = '\0';

  while(1)
    {
      print_string(prompt);
  
      if(read_char(&c)) break;
    }

  return c;
}



void add_ware(tree *t)
{
  print_add_header();

  char ware_name[STREAM_LENGTH] = {'\0'};

  while(1) // TODO check for invalid input
    {
      print_string("Input ware name\n");
      if(read_string(ware_name)) break;
    }

  void *w = NULL; // TODO ware_exists(t, ware_name);

  char ware_description[STREAM_LENGTH] = {'\0'};
  int ware_price = -1;
  
  if(w) // TODO implement
    {
      // print_ware(w);
    }
  else
    {
      while(1) // TODO check for invalid input
	{
	  print_string("Input description\n");
	  if(read_string(ware_description)) break;
	}
      while(1) // TODO check for invalid input
	{
	  print_string("Input price\n");
	  if(read_int(&ware_price)) break;
	}
    }
  
  char ware_shelf[STREAM_LENGTH] = {'\0'};

  while(1) // TODO check for invalid input
    {
      print_string("Input shelf location\n");
      if(read_shelf(ware_shelf)) break;
    }

  int ware_amount;
  
  while(1) // TODO check for invalid input
    {
      print_string("Input amount\n");
      if(read_int(&ware_amount)) break;
    }

}



void remove_ware(tree *t)
{
  print_remove_header();
}



void edit_ware(tree *t)
{
  print_edit_header();
}



void print_warehouse(tree *t)
{
  print_warehouse_header();
}



void pack_trolley(tree *t)
{
  print_trolley_header();
}



void exit_program(bool *exit)
{
  print_exit();
  *exit = true;
}
