#include <std_include.h>
#include <database.h>
#include <io.h>

void choose_option(bool *exit, tree *t);

void test_tree(tree *t)
{
  insert_ware(t, NULL, "Daim", "Sötsak. Bra i tårta.", 15, "R01", 5);
  insert_ware(t, ware_exists(t, "Daim"), "", "", 0, "D02", 50);
  insert_ware(t, NULL, "Banan", "Böjda i Norge.", 42, "B03", 2);
  insert_ware(t, ware_exists(t, "Banan"), "", "", 0, "B04", 12);
  insert_ware(t, ware_exists(t, "Banan"), "", "", 0, "B05", 1);
  insert_ware(t, ware_exists(t, "Banan"), "", "", 0, "B06", 15);
  insert_ware(t, NULL, "Fil", "Trögflytande.", 12, "F07", 25);
  insert_ware(t, ware_exists(t, "Fil"), "", "", 0, "F08", 15);
  insert_ware(t, ware_exists(t, "Fil"), "", "", 0, "F09", 15);
  insert_ware(t, NULL, "Annanas", "Perfekt till pizza.", 25, "A10", 12);
  insert_ware(t, ware_exists(t, "Annanas"), "", "", 0, "A11", 25);
  insert_ware(t, ware_exists(t, "Annanas"), "", "", 0, "A17", 13);
  insert_ware(t, ware_exists(t, "Annanas"), "", "", 0, "A10", 13);
  insert_ware(t, NULL, "Citron", "Surast i stan.", 12, "C12", 5);

  insert_ware(t, NULL, "Energi Dricka", "Kanske ger dig vingar.", 12, "E13", 5);
  insert_ware(t, NULL, "Häst", "Fyrbenta varelser som äter mycket.", 12, "H14", 5);
  insert_ware(t, ware_exists(t, "Häst"), "", "", 0, "H15", 12);
  insert_ware(t, NULL, "Gurka", "Våra gurkor har ångest.", 12, "G16", 5);
  insert_ware(t, NULL, "FFFF", "Våra gurkor har ångest.", 12, "G17", 5);
  insert_ware(t, NULL, "FFFU", "Våra gurkor har ångest.", 12, "G18", 5);

  insert_ware(t, NULL, "FFFA", "Våra gurkor har ångest.", 12, "G19", 5);
  insert_ware(t, NULL, "AFF", "Våra gurkor har ångest.", 12, "G20", 5);
  insert_ware(t, NULL, "FUCK", "Våra gurkor har ångest.", 12, "A99", 5);
  insert_ware(t, NULL, "BFA", "Våra gurkor har ångest.", 12, "Z1", 5);
  insert_ware(t, NULL, "BFC", "Våra gurkor har ångest.", 12, "Z5", 5);

  insert_ware(t, NULL, "BFFF", "Våra gurkor har ångest.", 12, "Z7", 5);
  insert_ware(t, NULL, "CFFF", "Våra gurkor har ångest.", 12, "B17", 5);
  insert_ware(t, NULL, "DFFF", "Våra gurkor har ångest.", 12, "Q17", 5);
  insert_ware(t, NULL, "EFFF", "Våra gurkor har ångest.", 12, "X17", 5);
  insert_ware(t, NULL, "GFFF", "Våra gurkor har ångest.", 12, "Z17", 5);

  insert_ware(t, NULL, "BFXF", "Våra gurkor har ångest.", 12, "Z7", 5);
  insert_ware(t, NULL, "BFYF", "Våra gurkor har ångest.", 12, "Z0", 5);
  insert_ware(t, NULL, "BFQF", "Våra gurkor har ångest.", 12, "X23", 5);
  insert_ware(t, NULL, "BVF", "Våra gurkor har ångest.", 12, "X27", 5);
  insert_ware(t, NULL, "AEFF", "Våra gurkor har ångest.", 12, "X97", 5);
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
  char user_input = '\0';
  user_input = get_menu_choice();

  switch(user_input)
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

    default: print_incorrect_input();
    }
}
