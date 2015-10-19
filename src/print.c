#include <print.h>
#include <database.h>

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


void print_ware_shelves(ware *w)
{
  print_delimiter;
  /*
  for(elem *e = get_first_shelf(w); e; get_next_shelf(e))
    {
      printf("%6s%6i\n", get_shelf_loc(e), get_shelf_amount(e));
    }
  */
  printf("\n");
}


void print_ware(ware *w)
{
  print_delimiter;
  printf("\n");
  /*
  printf("%-18s%s\n", "Ware name", get_ware_name(w));
  printf("%-18s%s\n", "Ware description", get_ware_desc(w));
  printf("%-18s%i\n", "Ware price", get_ware_price(w));
  */
  print_ware_shelves(w);
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

void print_menu()
{
  printf("\n");
  print_delimiter;
  print_centered("Welcome to warehouse 2.0", LINE_LENGTH);
  print_delimiter;
  printf("\n");

  printf("[A]dd an item\n");
  printf("[R]emove an item\n");
  printf("[E]dit an item\n");
  printf("[P]rint the warehouse\n");
  printf("Pa[C]k your trolley\n");
  printf("E[X]it\n\n");
}

void print_add_header()
{
  printf("\n");
  print_delimiter;
  print_centered("Add ware", LINE_LENGTH);
  print_delimiter;
  printf("\n");
}

void print_remove_header()
{
  printf("\n");
  print_delimiter;
  print_centered("Remove item", LINE_LENGTH);
  print_delimiter;
}

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

void print_trolley_header()
{
  printf("\n");
  print_delimiter;
  print_centered("Pack Trolley", LINE_LENGTH);
  print_delimiter;
}

void print_exit()
{
  printf("\n");
  print_delimiter;
  print_centered("Good bye", LINE_LENGTH);
  print_delimiter;
}
