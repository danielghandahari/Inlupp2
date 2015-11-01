#include <print.h>

#define LINE_LENGTH 25
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

void print_menu()
{
  printf("\n");
  print_delimiter;
  print_centered("Warehouse 2.0", LINE_LENGTH);
  print_delimiter;
  printf("\n");

  printf("[A]dd an item\n");
  printf("[R]emove an item\n");
  printf("[E]dit an item\n");
  printf("[P]rint the warehouse\n");
  printf("Pa[C]k your trolley\n");
  printf("E[X]it\n\n");
}



// ware

void print_shelves(ware *w)
{
  printf("\n"); 
  printf("Shelf || Amount\n");

  for(elem *e = get_first_shelf(w); e != NULL; e = get_next_shelf(e))
    {
      log_info("print_shelves", e, "%p");

      printf("%-5s -- %i\n", get_shelf_loc(e), get_shelf_amount(e));
    }
  
  printf("\n");
}

void print_ware(ware *w)
{
  print_delimiter;
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
  print_centered("Add new- or increase shelf", LINE_LENGTH);
  printf("\n");
}

void print_new_ware()
{
  printf("\n");
  print_centered("New ware", LINE_LENGTH);
  printf("\n");
}

void print_ware_added()
{
  printf("\n");
  print_centered("Ware added to warehouse", LINE_LENGTH);
  printf("\n");
}



// Remove

void print_remove_header()
{
  printf("\n");
  print_delimiter;
  print_centered("Remove item", LINE_LENGTH);
  print_delimiter;
}



// Warehouse

void print_edit_header()
{
  printf("\n");
  print_delimiter;
  print_centered("Edit item", LINE_LENGTH);
  print_delimiter;
}

void print_warehouse_header()
{
  printf("\n");
  print_delimiter;
  print_centered("Warehouse", LINE_LENGTH);
  print_delimiter;
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
  print_centered("The warehouse is empty", LINE_LENGTH);
}

void print_index_name(int index, char *ware_name)
{
  printf("%-5i -- %s\n", index + 1, ware_name);
}

void print_warehouse_menu()
{
  printf("Input ware index\n");
  printf("[P]rint next page\n");
  printf("E[X]it warehouse viewer\n\n");
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
