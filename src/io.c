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

void user_input_string(char *dest, const char *m)
{
  char tmp[STREAM_LENGTH] = {'\0'};

  while(1) // TODO check for invalid input
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

  while(1) // TODO check for invalid input
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

  while(1) // TODO check for invalid input
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

  void *w = NULL; // TODO ware_exists(t, ware_name);

  char ware_description[STREAM_LENGTH] = {'\0'};
  int ware_price = -1;
  
  if(w) // TODO implement
    {
      printf("Ware already exists in warehouse\n");
      // print_ware(w);
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

  //insert_ware(t, w, ware_name, ware_desc, ware_price, ware_shelf, ware_amount);
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
