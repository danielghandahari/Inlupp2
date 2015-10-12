#include <std_include.h>
#include <io.h>

void choose_option(bool *exit);

void menu()
{
  bool exit = false;

  while(!exit)
    {
      print_menu();

      choose_option(&exit);
    }
}

void choose_option(bool *exit)
{

  switch(get_user_choice())
    {
    case 'A': add_item(); break;

    case 'R': remove_item(); break;

    case 'E': edit_item(); break;

    case 'P': print_warehouse(); break;

    case 'C': pack_trolley(); break;

    case 'X': exit_program(exit); break;

    default: printf("This should not happen!\n");
    }
}
