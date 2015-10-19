#define CORRECT_INPUT "AREPCX"

#include <io.h>



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



void add_ware(tree *t)
{
  print_add_header();

  char ware_name[STREAM_LENGTH] = {'\0'};

  while(1) // TODO check for invalid input
    {
      printf("Input ware name\n");
      print_choice();
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
	  printf("Input description\n");
	  print_choice();
	  if(read_string(ware_description)) break;
	}
      while(1) // TODO check for invalid input
	{
	  printf("Input price\n");
	  print_choice();
	  if(read_int(&ware_price)) break;
	}
    }
  
  char ware_shelf[STREAM_LENGTH] = {'\0'};

  while(1) // TODO check for invalid input
    {
      printf("Input shelf location\n");
      print_choice();
      if(read_shelf(ware_shelf)) break;
    }

  int ware_amount;
  
  while(1) // TODO check for invalid input
    {
      printf("Input amount\n");
      print_choice();
      if(read_int(&ware_amount)) break;
    }

  printf("\n");

  printf("%-15s%s\n", "Name", ware_name);
  printf("%-15s%s\n", "Description", ware_description);
  printf("%-15s%i\n", "Price", ware_price);

  printf("%-15s%s\n", "Shelf", ware_shelf);
  printf("%-15s%i\n", "Amount", ware_amount);
}

void remove_ware(tree *t)
{
  print_remove_header();
}

void edit_ware(tree *t)
{
  print_edit_header();
}


#define PRINT_TILL_CHECK 20

void print_warehouse(tree *t)
{
  print_warehouse_header();

  //ware *w = get_first_ware(t)

  //if(!w)
  {
    printf("The warehouse is empty");
    return;
  }

  //for(int num_printed = 0; w; w = get_next_ware(w, t))
    {
      //char *str_to_print = "%d: %s", num_printed, get_ware_name(w);
      //printf(str_to_print);

      //w = get_next_ware(w, t);
      //if(++num_printed >= PRINT_TILL_CHECK)
      {
	printf("Select a ware by typing its corresponding index,\n type 'X' to exit or type 'N' to print the next page\n");
	print_choice();
	
      }
    }
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
