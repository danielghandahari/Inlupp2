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

  ware *w = ware_exists(t, ware_name);
  log_info("add_ware", w, "%p");

  char ware_description[STREAM_LENGTH] = {'\0'};
  int ware_price = -1;
  
  if(w)
    {
      print_add_or_update_shelf();
      print_ware(w);
    }
  else
    {
      print_new_ware();

      read_description(ware_description);      
      read_price(&ware_price);
    }
  
  char ware_shelf[STREAM_LENGTH] = {'\0'};
  bool shelf_not_ok = false;
  do
    {
      if(shelf_not_ok) printf("Shelf already in use\n");

      read_shelf(ware_shelf);
      shelf_not_ok = !shelf_ok(t, w, ware_shelf);
    } while(shelf_not_ok);
  

  int ware_amount;
  read_amount(&ware_amount);  

  insert_ware(t, w, ware_name, ware_description, ware_price, ware_shelf, ware_amount);

  print_ware_added();
}



void remove_ware(tree *t)
{
  log_info("remove_ware", t, "%p");
  print_remove_header();

  //TODO

  int index = get_ware_index(t);
  ware *w;

  if(index > -1) w = get_ware_at(t, index);
  else
    {
      printf("No wares to remove\n");
      goto exit;
    }
  int num_shelves = get_num_shelves(w);

  log_info("remove_ware", index, "%d");
  log_info("remove_ware", num_shelves, "%d");

  printf("The ware %s has the associated shelf/shelves:\n\n", get_ware_name(w));
  
  int input = 0;

  do
    {
      log_info("remove_ware", w, "%p");

      print_shelves_numbered(w);
      //TODO make simpler, similar to how get_ware_index get's it's index, try to combine
      user_input_int(&input, "To remove a shelf, input shelf index\ninput 0 to exit.\n");
      
      if(0 < input && input <= num_shelves)
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

 exit:
  return;
}


void edit_ware_aux(tree *t, int index)
{
  bool again = true;

  if(index < 0)
    {
      return;
    }
  do
    {
      ware *w = get_ware_at(t, index);
      print_ware(w);

      char input = '\0';
      printf("[N]ame [D]escription\n[P]rice [S]helf [A]mount\nE[X]it\n");
      read_char(&input);

      //TODO move to separet function
      switch(input)
	{
	case 'n':
	case 'N':
	  {
	    char name[STREAM_LENGTH] = {'\0'};
	    read_name(name);
	    edit_name(t, get_ware_name(w), name);
	  }
	  break;

	case 'd':
	case 'D':
	  {
	    char description[STREAM_LENGTH] = {'\0'};
	    read_description(description);
	    edit_desc(t, get_ware_name(w), description);
	  }
	  break;

	case 'p':
	case 'P':	  
	  {
	    int price = -1;
	    read_price(&price);
	    edit_price(t, get_ware_name(w), price);
	  }
	  break;

	case 's':
	case 'S':
	  {
	    print_shelves_numbered(w);

	    printf("Old shelf\n");
	    int chosen_shelf = -1;
	    bool shelf_not_ok = false;
	    do
	      {
		user_input_int(&chosen_shelf, "Index");
		shelf_not_ok =
		  0 <= chosen_shelf &&
		  chosen_shelf > get_num_shelves(w);
	      } while(shelf_not_ok);

	    printf("New shelf\n");
	    char new_location[STREAM_LENGTH] = {'\0'};

	    do
	      {
		user_input_shelf(new_location, "New location\n");

		shelf_not_ok = !shelf_ok(t, w, new_location);
	      } while(shelf_not_ok);

	    edit_shelf_location(t, get_ware_name(w), get_shelf_loc_at(w, chosen_shelf - 1), new_location);
	  }
	  break;

	case 'a':
	case 'A':
	  {
	    print_shelves_numbered(w);

	    printf("Shelf\n");
	    int chosen_shelf = -1;
	    do
	      {
		user_input_int(&chosen_shelf, "Index");
	      } while(0 <= chosen_shelf && chosen_shelf > get_num_shelves(w));

	    int amount = -1;
	    read_amount(&amount);

	    edit_shelf_amount(t, get_ware_name(w), get_shelf_loc_at(w, chosen_shelf-1), amount);
	  }
	  break;

	case 'x':
	case 'X': again = false; break;

	default: print_incorrect_input();
	}

    } while(again);
}

//TODO fix output
void edit_ware(tree *t)
{
  print_edit_header();

  int index = -1;
  index = get_ware_index(t);

  edit_ware_aux(t, index);
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
  
 print_next_page:  
  if(!w)
    {
      print_warehouse_empty();
      goto exit;
    }

  //TODO move to print.c
  printf("Index || Ware\n");

  while(w && (index % PRINT_TILL_CHECK) < PRINT_TILL_CHECK)
    {
      print_index_name(index, get_ware_name(w));
      ++index;
      
      w = get_ware_at(t, index);
    }

  if(!w)
    {
      print_end_of_warehouse();
    }

  char input[STREAM_LENGTH] = "\0";

 incorrect_input:

  print_warehouse_menu();
  read_string(input);

  //TODO move to different fuction
  switch(input[0])
    {
    case 'p':
    case 'P':
      ++page;
      goto print_next_page; break;

    case 'x':
    case 'X':
      goto exit; break;

    default:
      if(is_string_digit(input))
	{
	  int i = atoi(input);
	  if(0 < i && i <= index % PRINT_TILL_CHECK)
	    {
	      int final = i - 1 + 20 * page;
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

  if(index > -1)
    {
      print_ware(get_ware_at(t, index));
    }
}


//TODO fix this shit
void pack_trolley_io(tree *t)
{
  //=======================
  list *trolley = create_list();
  //========================
  print_trolley_header();
  //void *trolley;


  bool again = true;

  do
    {
      int index = get_ware_index(t);
      ware *w = get_ware_at(t, index);

      printf("Item: %s", get_ware_name(w));
      //=================
      
      //================
      int amount = -1;
      //TODO make macro to ease reading
      user_input_int(&amount, "$ How many items would you like to take?\n");
      
      //==================
      pack_trolley(trolley, get_ware_name(w), amount);
      //==================

      print_trolley_current(trolley);
    
      print_pack_again();
      
      char input = '\0';
      int loop = 1;
      
      while(loop)
	{
	  read_char(&input);
	  switch(input)
	    {
	    case 'n':
	    case 'N': again = false; loop = 0; break;
	  
	    case 'y':
	    case 'Y': loop = 0; break;
	    default: print_incorrect_input(); continue;
	    }
	  
	}
      

    } while(again);
  //print trolley_final
}



void exit_program(bool *exit, tree *t)
{
  print_exit();
  destroy_warehouse(t);
  *exit = true;
}
