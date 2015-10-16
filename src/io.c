#define CORRECT_INPUT "AREPCX"

#include <io.h>


bool correct_input(const char c, const char *correct)
{
  for(int i = 0; correct[i] != '\0'; i++)
    {
      if(c == correct[i]) return true;
    }

  return false;
}

char get_menu_choice()
{
  char input;

  while(1)
    {
       print_choice();

       check_debug(read_char(&input), "\tget_user_choice\tread_char failed");
       check_debug(correct_input(input, CORRECT_INPUT), "\tget_user_choice\tincorrect input");

       break;

    error:
       print_incorrect_input();
    }

  return input;
}



void get_string_input(char *dest, const char *prompt)
{
  char s[STREAM_LENGTH];

  print_string(prompt);

  while(1)
    {
      if(!read_string(s)) goto incorrect;

      break;

    incorrect:
      print_incorrect_input();
    }

  strcpy(dest, s);
}


void add_item()
{
  print_add_header();

  char item_name[STREAM_LENGTH] = {'\0'};

  get_string_input(item_name, "Input item name\n");

  /* char item_description[STREAM_LENGTH] = {'\0'}; */
  /* int item_price = -1; */

  //check_item_exists
  //if exists
  //print item
  //else

  
  
  //price

  //shelf
  //quantity
}



void remove_item()
{
  print_remove_header();
}



void edit_item()
{
  print_edit_header();
}



void print_warehouse()
{
  print_warehouse_header();
}



void pack_trolley()
{
  print_trolley_header();
}



void exit_program(bool *exit)
{
  print_exit();
  *exit = true;
}
