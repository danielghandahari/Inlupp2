#define CORRECT_INPUT "AREPCX"

#include <io.h>

typedef union _result_ result;
union _result_
{
  char char_value;
  char str_value[STREAM_LENGTH];
  int int_value;
};

// read_input
typedef bool (*r_f)(void *);

// validate_input
typedef bool (*v_f)(void *);

// convert_input
typedef result (*c_f)(void *);



bool v_menu_choice(char *c)
{
  for(int i = 0; i < strlen(CORRECT_INPUT); i++)
    {
      if(c[0] == CORRECT_INPUT[i]) return true;
    }
  return false;
}

bool v_greater_than_zero(int i)
{
  return i > 0;
}


result char_to_char(char c)
{
  return (result) {.char_value = c};
}

result str_to_str(char *s)
{
  return (result) {.str_value = strcpy(s)};
}

result int_to_int(int i)
{
  return (result) {.int_value = i};
}



result get_user_input(char *prompt, r_f read, v_f validate, c_f convert, bool cleanup)
{   
  void *input;
  bool read_ok = false;

  do
    {
      print_string(prompt);
      read_ok = read(input);

    } while(!read_ok || (validate && !validate(input)));

  result result = conver(input);

  if(cleanup) free(input);
  return result;
}



char get_menu_choice(char *prompt)
{
  return get_user_input(prompt, read_char, v_menu_choice, char_to_char, false).char_value;
}



void add_item(tree *t)
{
  print_add_header();
  /*
  char ware_name[STREAM_LENGTH] = {'\0'};

  //  get_string(ware_name, "Input item name\n");

  //  ware *w = ware_exists(t, ware_name);

  char item_description[STREAM_LENGTH] = {'\0'};
  int item_price = -1;
  
  if(w)
    {
      // print_ware(w);
    }
  else
    {
      // read ware_desc
      // read ware_price
    }
  
  char ware_shelf[STREAM_LENGTH] = {'\0'};

  do // TODO make beautiful
    {
      //      get_string(ware_shelf, "Input shelf location\n");

    } while(!shelf_ok(t, w, ware_shelf));

  int ware_amount;
  //  get_int(&ware_amount, "Input the amount of wares to be added\n");
  */
}



void remove_item(tree *t)
{
  print_remove_header();
}



void edit_item(tree *t)
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
