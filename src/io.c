#define CORRECT_INPUT "AREPCX"

#include <io.h>
#include <ctype.h>

int get_ware_index(tree *t);


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

  while(1) //TODO check for invalid input
    {
      printf("%s", m);
      print_choice();
      if(read_string(tmp)) break;
    }

  strcpy(dest, tmp);
}

void user_input_shelf(char *dest, const char *m)
{
  char tmp[STREAM_LENGTH] = {'\0'};

  while(1)
    {
      printf("%s", m);
      print_choice();
      if(read_shelf(tmp)) break;
    }

  strcpy(dest, tmp);
}

void user_input_int(int *dest, const char *m)
{
  int tmp = -1;

  while(1) //TODO check for invalid input
    {
      printf("%s", m);
      print_choice();
      if(read_int(&tmp)) break;
    }

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
  log_info("add_ware", ware_name, "%s");

  void *w = ware_exists(t, ware_name);
  log_info("add_ware", w, "%p");

  char ware_description[STREAM_LENGTH] = {'\0'};
  int ware_price = -1;
  
  if(w)
    {
      printf("\nWare already exists in warehouse\n\n");
      print_ware(w);
    }
  else
    {
      printf("\nNew ware\n\n");

      read_description(ware_description);      
      read_price(&ware_price);
    }
  
  //TODO check for used shelf
  char ware_shelf[STREAM_LENGTH] = {'\0'};
  do
    {
      read_shelf(ware_shelf);
    } while(!shelf_ok(t, w, ware_shelf));
  

  int ware_amount;
  read_amount(&ware_amount);  

  insert_ware(t, w, ware_name, ware_description, ware_price, ware_shelf, ware_amount);

  //TODO move to print.c
  printf("\nWare added to warehouse\n\n");
}



void remove_ware(tree *t)
{
  log_info("remove_ware", t, "%p");
  print_remove_header();

  //TODO

  int index = get_ware_index(t);

  ware *w = get_ware_at(t, index);
  int num_shelves = get_num_shelves(w);

  log_info("remove_ware", index, "%d");
  log_info("remove_ware", num_shelves, "%d");

  printf("The ware %s has the associated shelf/shelves:\n\n", get_ware_name(w));
  
  int input = 0;

  do
    {
      log_info("remove_ware", w, "%p");

      print_shelves(w);
      //TODO make simpler, similar to how get_ware_index get's it's index, try to combine
      user_input_int(&input, "To remove a shelf, input it's assosiated number or\ninput 0 to exit.");
      
      if(input > 0 && input < num_shelves)
	{
	  printf("Shelf %s removed\n", get_shelf_loc_at(w, input - 1));
	  remove_shelf_at(t, w, input - 1);

	  num_shelves = get_num_shelves(w);
	  if(num_shelves < 1)
	    {
	      printf("All shelves removed from warehouse");
	      break;
	    }
	}
      else
	{
	  print_incorrect_input();
	}
    } while(input != 0);
}


//TODO fix output
void edit_ware(tree *t)
{
  print_edit_header();

  int index = -1;
  index = get_ware_index(t);

 again:

  ware *w = get_ware_at(t, index);
  print_ware(w);

  //get attribute to edit
  char input = {'\0'};
  read_char(&input);

  //input new value of attribute
  switch(input)
    {
      //name
    case 'n':
    case 'N':
      char *name = {'\0'};
      read_name(name);
      //send to database
      goto again;
      break;

      //description
    case 'd':
    case 'D':
      char *description = {'\0'};
      read_description(description);
      //send to database
      goto again;
      break;

      //price
    case 'p':
    case 'P':
      int price = -1;
      read_price(price);
      //send to database
      goto again;
      break;

      //shelf
    case 's':
    case 'S':
      char *shelf = {'\0'};
      read_shelf(shelf
      break;

      //amount
    case 'a':
    case 'A':

      break;

    case 'x':
    case 'X':
      goto exit;
      break;

    default:
      print_incorrect_input();
    }

 exit:
}



bool is_string_digit(const char *s)
{
  for(int i = 0, length = strlen(s); i < length; i++)
    {
      if(!isdigit(s[i])) return false;
    }

  return true;
}

#define PRINT_TILL_CHECK 20

int get_ware_index(tree *t)
{
  print_warehouse_header();

  log_info("get_ware_index", t, "%p");

  int index = 0;
  int page = 0;
  ware *w = get_ware_at(t, index);

  log_info("get_ware_index", w, "%p");
  
  if(!w)
    {
      print_warehouse_empty();
      goto exit;
    }

 print_next_page:
  while(w)
    {
      print_index_name(index, get_ware_name(w));
      ++index;
      
      w = get_ware_at(t, index);
    }

  if(!w) print_end_of_warehouse();

 incorrect_input:
  print_warehouse_menu();

  char input[STREAM_LENGTH] = {'\0'};
  read_string(input);

  //TODO move to different fuction
  switch(input[0])
    {
    case 'p':
    case 'P':
      if(w)
	{
	  ++page;
	  goto print_next_page;
	}
      else
	{
	  printf("End of wareohuse\n");
	  goto exit;
	}
      break;

    case 'x':
    case 'X':
      return -1;
      break;

    default:
      if(is_string_digit(input))
	{
	  int i = atoi(input);
	  if(0 < i && i <= PRINT_TILL_CHECK)
	    {
	      int final = i - 1 + 20 * page;
	      print_ware(get_ware_at(t, final));
	      return final;
	    }
	}
      
      goto incorrect_input;
    }

 exit:
  return -1;
}

void print_warehouse(tree *t)
{
  int index = get_ware_index(t);

  print_ware(get_ware_at(t, index));
}


//TODO fix this shit
void pack_trolley(tree *t)
{
  print_trolley_header();

  bool again = true;

  do
    {
      int index = get_ware_index(t);

      ware *w = get_ware_at(t, index);

      int amount = -1;
      //TODO make macro to ease reading
      user_input_int(&amount, "How many of '%s' would you like to take?\n", get_ware_name(w));

      //print_trolly_current

      again = false;

    } while(again);

  //print trolley_final
}



void exit_program(bool *exit, tree *t)
{
  print_exit();
  destroy_warehouse(t);
  *exit = true;
}
