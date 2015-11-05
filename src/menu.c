#include <std_include.h>
#include <database.h>
#include <io.h>

void choose_option(bool *exit, tree *t);

void test_tree(tree *t)
{
  insert_ware(t, NULL, "Daim", "Sötsak. Bra i tårta.", 12, "R34", 5);
  insert_ware(t, ware_exists(t, "Daim"), "", "", 0, "R14", 50);

  insert_ware(t, NULL, "Banan", "Böjda i Norge.", 42, "A10", 2);
  insert_ware(t, ware_exists(t, "Banan"), "", "", 0, "A55", 12);
  insert_ware(t, NULL, "Fucks", "None given.", 32, "A34", 5);

  insert_ware(t, NULL, "Annanas", "Perfekt till pizza.", 12, "G34", 5);
  insert_ware(t, ware_exists(t, "Annanas"), "", "", 0, "R99", 500);
  insert_ware(t, NULL, "Citron", "Surast i stan.", 12, "Q94", 5);

  insert_ware(t, NULL, "Engelbert", "Ett väldigt roligt namn.", 12, "T34", 5);
  insert_ware(t, NULL, "Häst", "Fybenta varelser.", 12, "S34", 5);
  insert_ware(t, ware_exists(t, "Häst"), "", "", 0, "E99", 12);
  insert_ware(t, NULL, "Gud", "Finns inte på riktigt.", 12, "Z34", 5);
}

void menu()
{
  bool exit = false;
  tree *t = create_tree();

  test_tree(t);

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
    case 'C': pack_trolley_io(t); break;

    case 'x':
    case 'X': exit_program(exit, t); break;

    default: printf("Incorrect input\n");
    }
}
