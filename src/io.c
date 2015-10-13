#include <std_include.h>
#include <tree.h>
#include <list.h>
#include <database.h>
#include <io.h>

#define CORRECT_INPUT "AREPCX"


void print_menu()
{
  printf("\n");
  printf("Welcome to warehouse 2.0\n");
  printf("========================\n\n");

  printf("[A]dd an item\n");
  printf("[R]emove an item\n");
  printf("[E]dit an item\n");
  printf("[P]rint the warehouse\n");
  printf("Pa[C]k your trolley\n");
  printf("E[X]it\n\n");
}

#define Print_add_item_header print_string("Add item\n========\n\n");

void print_string(const char *s)
{
  printf("%s",s);
}

void add_item()
{
<<<<<<< HEAD
  /*
=======
>>>>>>> 981ef866c627a34aedfbacaca8aa9b0503134503
  char *item_name;
  char *item_desc;
  char *item_shelf_loc;
  int item_price = -1;
  int item_amount = -1;
<<<<<<< HEAD
  */
=======

>>>>>>> 981ef866c627a34aedfbacaca8aa9b0503134503

}


void remove_item()
{
  printf("Remove item\n");
}


void edit_item()
{
  printf("Edit item\n");
}


void print_warehouse()
{
  printf("Print Warehouse\n");
}


void pack_trolley()
{
  printf("Pack the trolley\n");
}


void exit_program(bool *exit)
{
  printf("Good bye\n");
  *exit = true;
}



char get_user_choice()
{
  printf("Your choice\n");

  return 'X';
}
