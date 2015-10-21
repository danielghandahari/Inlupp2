#define CORRECT_INPUT "AREPCX"

#include <io.h>
#include <ctype.h>



char get_menu_choice(char *prompt)
{
  char c = '\0';

  while(1)
    {
      printf("%s", prompt);
      print_choice();
      if(read_char(&c)) break;
    }

  return c;
}

void user_input_string(char *dest, const char *m)
{
  char tmp[STREAM_LENGTH] = {'\0'};

  while(1) //TODO check for invalid input
    {
      printf("%s", m);
      print_choice();
      if(read_string(tmp)) break;
    }

  log_info("%20s%s", "user_input_string", tmp);
  strcpy(dest, tmp);
}

void user_input_shelf(char *dest, const char *m)
{
  char tmp[STREAM_LENGTH] = {'\0'};

  while(1) //TODO check for invalid input
    {
      printf("%s", m);
      print_choice();
      if(read_shelf(tmp)) break;
    }

  log_info("%20s%s", "user_input_shelf", tmp);
  strcpy(dest, tmp);
}

void user_input_int(int *dest, const char *m)
{
  int tmp = -1;

  while(1) //TODO check for invalid input
    {
      printf("%s", m);
      print_choice();
      if(read_int(&tmp)) break;
    }

  log_info("%20s%i", "user_input_int", tmp);
  *dest = tmp;
}



#define read_name(A) user_input_string(A, "Ware name\n")
#define read_description(A) user_input_string(A, "Ware description\n")
#define read_price(A) user_input_int(A, "Ware price\n")
#define read_shelf(A) user_input_shelf(A, "Ware shelf\n")
#define read_amount(A) user_input_int(A, "Ware amount\n")

void add_ware(tree *t)
{
  print_add_header();

  char ware_name[STREAM_LENGTH] = {'\0'};
  read_name(ware_name);

  void *w = ware_exists(t, ware_name);

  char ware_description[STREAM_LENGTH] = {'\0'};
  int ware_price = -1;
  
  if(w) //TODO implement
    {
      printf("Ware already exists in warehouse\n");
      print_ware(w);
    }
  else
    {
      read_description(ware_description);      
      read_price(&ware_price);
    }
  
  char ware_shelf[STREAM_LENGTH] = {'\0'};
  read_shelf(ware_shelf);

  int ware_amount;
  read_amount(&ware_amount);  


  printf("\n");
  printf("%-15s%s\n", "Name", ware_name);
  printf("%-15s%s\n", "Description", ware_description);
  printf("%-15s%i\n", "Price", ware_price);
  printf("%-15s%s\n", "Shelf", ware_shelf);
  printf("%-15s%i\n", "Amount", ware_amount);

  insert_ware(t, w, ware_name, ware_description, ware_price, ware_shelf, ware_amount);
}



void remove_ware(tree *t)
{
  print_remove_header();

  //TODO

  //print warehouse
  //get index of ware to remove
  //print ware
  //get shelf to remove
  //remove shelf
  //print result
}



void edit_ware(tree *t)
{
  print_edit_header();

  //TODO

  //print warehouse
  //get index of ware to be edited

  //again:

  //print ware
  //get ware based on index
  //get attribute to edit
  //input new value of attribute

  //check: edit another attribute?
  //if yes: goto again
  //else: exit
}



#define PRINT_TILL_CHECK 20

int print_warehouse(tree *t)
{
  print_warehouse_header();

  int index = 0;
  int page = 0;
  ware *w = get_ware_at(t, index);
  
  if(!w)
    {
      //TODO move to print.c
      print_warehouse_empty();
      goto exit;
    }

 print_next_page:
  while(w)
    {
      //TODO move to print.c
      printf("%-6i ", (index) + 1);
      printf("%s\n", get_ware_name(w));
      ++index;
      
      w = get_ware_at(t, index);
    }

  if(!w) print_end_of_warehouse();

 incorrect_input:

  //TODO move to print.c
  printf("Choose a ware 1 - 20\n");
  printf("[P]rint next page\n");
  printf("E[X]it warehouse viewer\n");

  char input[STREAM_LENGTH] = {'\0'};
  read_string(input); //TODO check valid input

  //TODO move to different fuction
  switch(input[0])
    {
    case 'p':
    case 'P':
      ++page;
      goto print_next_page;
      break;

    case 'x':
    case 'X':
      return -1;
      break;

    default:
      if(isdigit(input))
	{
	  int i = atoi(input);
	  if(0 < i && i <= PRINT_TILL_CHECK) return i - 1 + 20 * page;
	}
      
      goto incorrect_input;
    }

 exit:
  return -1;
}



void pack_trolley(tree *t)
{
  print_trolley_header();

  //TODO

  //do

  //print warehouse
  //select ware to pack
  //get number of wares to put in the trolley

  //while(pack another ware)

  //print trolley
}



void exit_program(bool *exit, tree *t)
{
  print_exit();
  //TODO destroy_warehouse(t);
  *exit = true;
}
