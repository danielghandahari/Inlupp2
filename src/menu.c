#include <std_include.h>
#include <database.h>
#include <io.h>

void choose_option(bool *exit, tree *t);

void menu()
{
  bool exit = false;
  tree *t = create_tree();

  while(!exit)
    {
      print_menu();

      choose_option(&exit, t);
    }
}



void choose_option(bool *exit, tree *t)
{
  switch(get_menu_choice())
    {
    case 'a':
    case 'A': add_ware(t); break;

    case 'r':
    case 'R': remove_ware(t); break;

    case 'e':
    case 'E': edit_ware(t); break;

    case 'p':
    case 'P': print_warehouse(t); break;

    case 'c':
    case 'C': pack_trolley(t); break;

    case 'x':
    case 'X': exit_program(exit, t); break;

    default: printf("This should not happen!\n");
    }
}
