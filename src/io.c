#include <std_include.h>

#define CORRECT_INPUT "AREPCX"



char read_char();
char *read_string();
char *read_word();
int read_int();




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



void add_item()
{

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



char read_char()
{
  char input = NULL;

  scanf(" %c", &input);

  return input;
}

char *read_string()
{
  char *input = {'\0'};

  scanf("%s", input);

  return input;
}

char *read_word()
{
  char *input = read_string();

  for(int i = 0; i < strlen(input); i++)
    {
      if(input[i] == ' ')
	{
	  input[i] = '\0';
	  break;
	}
    }

  return input;
}

int read_int()
{
  
}
