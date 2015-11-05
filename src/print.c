#include <print.h>

#define LINE_LENGTH 50
#define print_delimiter print_line(LINE_LENGTH, '=')


void print_centered(const char *s, int line_length)
{
  int string_length = strlen(s);
  int center = line_length / 2;

  int white_space = center - string_length / 2;

  for(int i = 0; i < white_space; i++)
    {
      printf(" ");
    }

  printf("%s\n", s);
}

void print_line(const int line_length, const char c)
{
  for(int i = 0; i < line_length; i++)
    {
      printf("%c", c);
    }

  printf("\n");
}

void print_incorrect_input()
{
  printf("\n");
  printf("Incorrect input\n");
}

void print_choice()
{
  printf("$ ");
}



// menu

#define COL_PRINT(A, B) printf("%10s %s", A, B)

void print_menu()
{
  printf("\n");
  print_delimiter;
  print_centered("Warehouse 2.0", LINE_LENGTH);
  print_delimiter;
  printf("\n");

  COL_PRINT("[A]", "Add an item\n");
  COL_PRINT("[R]", "Remove an item\n");
  COL_PRINT("[E]", "Edit an item\n");
  COL_PRINT("[P]", "Print the warehouse\n");
  COL_PRINT("[C]", "Pack your trolley\n");
  COL_PRINT("[X]", "Exit\n\n");
}



// shelves

void print_shelves(ware *w)
{
  printf("\n"); 
  print_centered("Shelves", LINE_LENGTH);

  for(elem *e = get_first_shelf(w); e != NULL; e = get_next_shelf(e))
    {
      char *s_loc = get_shelf_loc(e);
      int s_amount = get_shelf_amount(e);

      printf("---------------\n");
      printf("%-10s %s\n", "Location", s_loc);
      printf("%-10s %d\n", "Amount", s_amount);
    }
  
  printf("\n");
}

void print_shelves_numbered(ware *w)
{
  printf("\n"); 
  print_centered("Shelves", LINE_LENGTH);
  int i = 1;

  for(elem *e = get_first_shelf(w); e != NULL; e = get_next_shelf(e))
    {
      char *s_loc = get_shelf_loc(e);
      int s_amount = get_shelf_amount(e);

      printf("%-2d %-10s %s\n", i, "Location", s_loc);
      printf("%-13s %d", "Amount", s_amount);
      i++;
    }
  
  printf("\n");
}



// ware

void print_ware(ware *w)
{
  printf("\n");
  print_centered("Ware", LINE_LENGTH);
  printf("%-18s%s\n", "Name", get_ware_name(w));
  printf("%-18s%s\n", "Description", get_ware_desc(w));
  printf("%-18s%i\n", "Price", get_ware_price(w));

  print_shelves(w);
}



// Add

void print_add_header()
{
  printf("\n");
  print_delimiter;
  print_centered("Add ware", LINE_LENGTH);
  print_delimiter;
  printf("\n");
}

void print_add_or_update_shelf()
{
  printf("\n");
  print_centered("Ware exists in warehouse", LINE_LENGTH);
  printf("\n");
}

void print_new_ware()
{
  printf("\n");
  print_centered("Ware does not exist in warehouse",LINE_LENGTH);
  printf("\n");
}

void print_ware_added()
{
  printf("\n");
  print_centered("Done!", LINE_LENGTH);
  printf("\n");
}



// Remove

void print_remove_header()
{
  printf("\n");
  print_delimiter;
  print_centered("Remove shelves and/or a ware", LINE_LENGTH);
  print_delimiter;
}



// Warehouse

void print_edit_header()
{
  printf("\n");
  print_delimiter;
  print_centered("Edit ware", LINE_LENGTH);
  print_delimiter;
}

void print_warehouse_header()
{
  printf("\n");
  print_centered("||== The warehouse ==||", LINE_LENGTH);
  printf("\n");
}

void print_end_of_warehouse()
{
  printf("\n");
  print_centered("End of warehouse", LINE_LENGTH);
  printf("\n");
}

void print_warehouse_empty()
{
  printf("\n");
  print_centered("Nothing to show", LINE_LENGTH);
}

void print_index_name(int index, char *ware_name)
{
  printf("%-5i -- %s\n", index + 1, ware_name);
}

void print_warehouse_menu()
{
  COL_PRINT("[n]", "Input ware index\n");
  COL_PRINT("[P]", "Print next page\n");
  COL_PRINT("[X]", "Exit warehouse viewer\n");
}



// Trolley

void print_trolley_header()
{
  printf("\n");
  print_delimiter;
  print_centered("Pack Trolley", LINE_LENGTH);
  print_delimiter;
}



// Exit

void print_exit()
{
  printf("\n");
  print_delimiter;
  print_centered("Good bye", LINE_LENGTH);
  print_delimiter;
}
