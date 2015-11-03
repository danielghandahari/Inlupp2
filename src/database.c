#define _GNU_SOURCE

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <tree.h>
#include <list.h>
#include <assert.h>
#include <database.h>
#include <tree_secret.h>
#include <list_secret.h>
#include <dbg.h>
#include <string.h>
#include <ctype.h>
#define Equal action == 0
#define ElementOf(SHELF) &(SHELF)
#define ElementOrShelfOf(SHELF) (ElementOf(SHELF) == NULL || SHELF == NULL)
#define check_shelf_used_ASSERT(NODE) ware *emptylistptr =(ware*)((*NODE)->content); \
  assert((emptylistptr || emptylistptr->shelves || emptylistptr->shelves->first))
 
char * make_key(char *ware_name); //TODO, lägg alla funktioner som behövs här 
bool find_elem_DB(elem *e, char *key);
void incr_shelf(shelf *s, int incr);

//ICKE-GENERELLA STRUCTAR FÖR TREE.C
struct _ware_
{
  char *name;
  char *desc;
  int price;

  list *shelves;
};
//==================================


//ICKE-GENERELLA STRUCTAR FÖR LIST.C

struct _shelf_
{
  char *location;
  int amount;
};

struct _sum_
{
  int totalmount;
};
//===================================


ware * create_ware()
{
  ware *w = calloc(1, sizeof(ware));
  return w;
}

shelf *create_shelf()
{
  shelf *s = (shelf *) calloc(1, sizeof(shelf));
  return s;
}

int key_compare(void *key1, void *key2)
{
  assert(key1 && key2);

  char *str1 = (char*)key1;
  char *str2 = (char*)key2;

  log_info("key_compare", str1, "%s");
  log_info("key_compare", str2, "%s");

  assert(strlen(str1) > 0);
  assert(strlen(str2) > 0);
  
  return strcmp(str1, str2);
}



int elem_compare(void *e1, void *e2)
{
  shelf *shlf1 = (shelf*)e1;
  shelf *shlf2 = (shelf*)e2;

  assert(shlf1); 
  assert(shlf2);
  
  return key_compare(shlf1->location , shlf2->location);
}




bool check_shelf_used(node **n, char *key)
{
  //  check_shelf_used_ASSERT(n);

  node **current = n;
  
  if(*current)
    {
      log_info("check_shelf_used", current, "%p");

      ware *c =(ware*)((*current)->content);
      log_info("check_shelf_used", c, "%p");

      bool eleminlist = find_elem_in_list_DB(c->shelves, key);
      log_info("check_shelf_used", eleminlist, "%d");

      if (eleminlist) return true;
      
      else return check_shelf_used(&((*current)->left), key) || check_shelf_used(&((*current)->right), key); 
    }
  return false;
}



bool check_shelf_used_in_tree(tree *t, char *key)
{
  assert(t); 
  return  check_shelf_used(&(t->root), key);
}



void incr_shelf_and_tot(list *l, char *key, int incr)
{
  elem *e = get_elem_in_list_DB(l, key);
  log_info("incr_shelf_and_tot", e, "%p");

  shelf *s = (shelf*)e->box;
  log_info("incr_shelf_and_tot", s, "%p");

  incr_shelf(s, incr);
  log_info("incr_shelf_and_tot", s->amount, "%d");

  //TODO make it work
  //  int *totalamount  = (int*)l->stuff;
  //  (*totalamount) += incr;
}



void incr_shelf(shelf *s, int incr)
{
  log_info("incr_shelf", s->amount, "%d");
  s->amount += incr;
}



bool check_used_by_ware(tree *t, void *key, char *shelfloc)
{
  node *mynode = get_node_in_tree(t, key);
  ware *myitem = (ware*)mynode->content;

  return find_elem_in_list_DB(myitem->shelves, shelfloc);
}

bool find_elem_in_list_DB(list *l, char *key)
{
  return find_elem_DB(l->first, key);
}

bool find_elem_DB(elem *e, char *key)
{
  return get_elem_DB(e, key);
}

elem * get_elem_in_list_DB(list *l, char *key)
{
  return get_elem_DB(l->first, key);
}

elem * get_elem_DB(elem *e, char *key)
{
  elem *current = e;
  
  while (current)
    {
      shelf *s = (shelf*)current->box;
      int action = key_compare(s->location, key);

      log_info("get_elem_DB", current, "%p");
      log_info("get_elem_DB", s, "%p");
      log_info("get_elem_DB", action, "%d");
      
      if (action == 0) return current;
      current = current->next;
    }

  return NULL;
}


//TIMS FUNKTIONER

ware *ware_exists(tree *t, char *warename)
{
  log_info("ware_exists", t, "%p");
  log_info("ware_exists", warename, "%p");
  log_info("ware_exists", warename, "%s");

  char *key  = make_key(warename);
  
  node *n = get_node_in_tree(t, key); //TODO fix warename skickas in som om det vore en 'key'.
  log_info("ware_exists", n, "%p");

  if(!n) return NULL;

  ware *w = (ware*)n->content;
  log_info("ware_exists", w, "%p");

  return w;
}

ware *get_ware_at_aux(node *n, int index, int *acc)
{
  log_info("get_ware_at_aux", n, "%p");

  log_info("get_ware_at_aux", *acc, "%d");
  log_info("get_ware_at_aux", index, "%d");

  //if(*acc > index) return NULL; //might cause logical faults

  ware *ret_val = NULL;

  if(n->left) ret_val = get_ware_at_aux(n->left, index, acc);
  
  if(ret_val) goto done;

  if(index == *acc) return get_ware(n);
  else ++(*acc);

  if(n->right) ret_val = get_ware_at_aux(n->right, index, acc);


 done:
  return ret_val;
}

ware *get_ware_at(tree *t, int index)
{
  log_info("get_ware_at", t, "%p");
  log_info("get_ware_at", index, "%d");

  int *acc = calloc(1, sizeof(int));
  *acc = 0;
  node *root = get_root(t);

  if(!root) return NULL;

  ware *w = get_ware_at_aux(root, index, acc);
  log_info("get_ware_at", w, "%p");

  free(acc);

  return w;
}

bool shelf_ok(tree *t, ware *w, char *shelfloc)
{
  log_info("shelf_ok", t, "%p");
  log_info("shelf_ok", w, "%p");
  log_info("shelf_ok", shelfloc, "%s");
  log_info("shelf_ok", shelfloc, "%p");

  if(w)
    {
      if(find_elem_in_list_DB(w->shelves, shelfloc)) return true;
    }

  return !check_shelf_used_in_tree(t, shelfloc);
}

void insert_ware(tree *t, ware *w, char *warename, char *waredesc, int wareprice, char *shelfloc, int shelfamount)
{
  log_info("insert_ware", t, "%p");
  log_info("insert_ware", w, "%p");
  log_info("insert_ware", warename, "%s");

  log_info("insert_ware", shelfloc, "%s");
  log_info("insert_ware", shelfamount, "%d");

  if (w)
    {
      bool shelfexists = find_elem_in_list_DB(w->shelves, shelfloc);
      log_info("insert_ware", shelfexists, "%d");

      if(shelfexists) incr_shelf_and_tot(w->shelves, shelfloc, shelfamount);
      
      else
	{
	  elem *e = create_elem();
	  log_info("insert_ware", e, "%p");

	  shelf *s = create_shelf();
	  log_info("insert_ware", s, "%p");
	  
	  e->box = s;

	  log_info("insert_ware", e->box, "%p");

	  s->location = strdup(shelfloc);
	  s->amount = 0;

	  insert_elem_in_list(w->shelves, e);
	  //incr_shelf_and_tot(w->shelves, shelfloc, shelfamount);       
	}
    }
  else
    {
      node *n = create_node();
      ware *w = create_ware();
      list *l = create_list();
      elem *e = create_elem();
      shelf *s = create_shelf();

      log_info("insert_ware", n, "%p");
      log_info("insert_ware", w, "%p");
      log_info("insert_ware", l, "%p");
      log_info("insert_ware", e, "%p");
      log_info("insert_ware", s, "%p");

      //shelf
      s->location = strdup(shelfloc);
      s->amount = shelfamount;

      //elem
      e->box = s;
      insert_elem_in_list(l, e);

      //ware
      w->name = strdup(warename);
      w->desc = strdup(waredesc);
      w->price = wareprice;
      w->shelves = l;

      //node
      n->key = make_key(warename);
      n->content = w;

      //tree
      append_node_in_tree(t, n);
    }
}

ware *get_ware(node *n) { return (ware *)get_content(n); }

char *get_ware_name(ware *w) { return w->name; }
char *get_ware_desc(ware *w) { return w->desc; }
int   get_ware_price(ware *w) { return w->price; }

list *get_list(ware *w) { return w->shelves; }

elem *get_first_shelf(ware *w) { return w->shelves->first; }
elem *get_next_shelf(elem *e) { return e->next; }
char *get_shelf_loc(elem *e) { return ((shelf*)e->box)->location; }
int   get_shelf_amount(elem *e) { return ((shelf*)e->box)->amount; }

// ===== ===== ===== =====
//           Tim
// ===== ===== ===== =====

int get_num_shelves(ware *w)
{
  elem *shelf = get_first_shelf(w);
  assert(shelf);

  int num_of_shelves = 0;

  while(shelf)
    {
      num_of_shelves++;
      shelf = get_next_shelf(shelf);
    }

  return num_of_shelves;
}

void remove_shelf_at(tree *t, ware *w, int index)
{
  elem *shelf = get_first_shelf(w);
  assert(w);  

  for(int i = 0; i < index; i++)
    {
      shelf = get_next_shelf(shelf);
      if(!shelf) return;
    }

  rem_elem_in_list(w->shelves, shelf->box);

  char *key = make_key(get_ware_name(w));
  
  if(!get_first_shelf(w)) rem_node_in_tree(t, key);

}

char *get_shelf_loc_at(ware *w, int index)
{
  elem *shelf = get_first_shelf(w);
  int current_index = 0;
  assert(shelf);
  
  while(current_index < index)
    {
      shelf = get_next_shelf(shelf);
      if(!shelf) break;
      current_index++;
    }

  return get_shelf_loc(shelf);
}


void destroy_warehouse_subtree(node **n)
{
  if(!(*n)) return;

  node **temp_left = &((*n)->left);
  node **temp_right = &((*n)->right);


 
  destroy_node_DB(*n);
  destroy_warehouse_subtree(temp_left);
  destroy_warehouse_subtree(temp_right); 
}



void destroy_warehouse(tree *t)
{
  assert(t);
  
  destroy_warehouse_subtree(&(t->root));
  free(t);
}



void destroy_list_DB(list *l)
{
  elem *temp = l->first;

  if(temp)
    {
      shelf *s = (shelf*)temp->box;
      char *t1 = s->location;
      elem *free_temp = temp;

      temp = temp->next;
      
      free(t1);
      free(temp->box);
      free(free_temp);
    }
  free(l->stuff);
  free(l);
}



void destroy_ware(ware *w)
{
  free(w->name);
  free(w->desc);
  free(w);
}

void destroy_only_node(node *n)
{
  free(n->key);
  free(n->content);
  free(n);
}


void destroy_node_DB(node *n)
{
  ware *w = (ware*)n->content;
  destroy_list_DB(w->shelves);
  destroy_ware(w);
  free(n->key);
  free(n);
}



void rem_elem_in_list(list *l, void *elembox)
{
  assert(l);

  rem_elem(&(l->first), elembox);

  if(l->first == l->last) l->last = NULL;
  
}


//GÖR KLART EFTER DU GJORT TIMS FUNKTIONER

void rem_elem(elem **e, void *elembox)
{
  if(!(*e)) return;


  elem *temp_last = get_last_elem(e);
  if((*e) == temp_last)
    {
      shelf *s = (shelf*)(*e)->box;
      free(s->location);
      free(s);
      *e = NULL;
    }

  if(*e)
    {
      elem *temp = get_elem(*e, elembox);

      e = &temp;

      *e = temp->next;

      shelf *s = (shelf*)temp->box;
      free(s->location);
      free(s);
      free(temp);
    }
}



char * make_key(char *ware_name) 
{
  char *new_key = strdup(ware_name);

  for(int i = 0; i < (int)strlen(ware_name); i++)
    {
      new_key[i] = toupper(ware_name[i]);
    }
  return new_key;
  
}




void edit_name(tree *t, char *old_name, char *new_name)
{
  char *my_new_name = strdup(new_name);
  char *old_key = make_key(old_name);
  node *n = get_node_in_tree(t, old_key);
  ware *w = (ware*)n->content;

  char *new_key = make_key(my_new_name);
  ware *new_ware = NULL;
  elem *temp = get_first_shelf(w);

  
  do
    {
      log_info("edit_name", w, "%p");
      log_info("edit_name", temp, "%p");

      insert_ware(t, new_ware, new_name, get_ware_desc(w), get_ware_price(w), get_shelf_loc(temp), get_shelf_amount(temp));

      if(!new_ware)
	{
	  log_info("edit_node", new_ware, "%p");
	  node *temp_n = check_node_exists(&(t->root), new_key);
	  new_ware = get_ware(temp_n);
	}

      temp = temp->next;
    }while(temp);
  
  log_info("edit_name", t, "%p");
  log_info("edit_name", old_key, "%s");
  rem_node_in_tree(t, old_key);

  //append_node_in_tree(t, new_node);  
  
}


void edit_desc(tree *t, char *name, char *new_desc)
{
  char *my_new_desc = strdup(new_desc);

  char *key = make_key(name);

  node *n = get_node_in_tree(t, key);

  ware *w = (ware*)n->content;

  free(w->desc);

  w->desc = my_new_desc;
}



void edit_price(tree *t, char *name, int new_price)
{
  char *key = make_key(name);
  
  node *n = get_node_in_tree(t, key);

  ware *w = (ware*)n->content;
  
  w->price = new_price;
  
}

void edit_shelf_location(tree *t, char *name, char *old_shelf, char *new_shelf)
{
  char *my_new_shelf = strdup(new_shelf);

  char *key =  make_key(name);

  node *n = get_node_in_tree(t, key);

  ware *w = (ware*)n->content;

  elem *e = get_elem_in_list_DB(w->shelves, old_shelf);

  shelf *s = (shelf*)e->box;

  free(s->location);

  s->location = my_new_shelf;
}


void edit_shelf_amount(tree *t, char *name, char *old_shelf, int new_amount)
{
  char *key = make_key(name);

  node *n = get_node_in_tree(t, key);

  ware *w = (ware*)n->content;

  elem *e = get_elem_in_list_DB(w->shelves, old_shelf);

  shelf *s = (shelf*)e->box;

  s->amount = new_amount;
}


void free_key_in_node(node *n)
{
  free(n->key);
}



void free_list_in_node(node *n)
{
  ware *w = (ware*)n->content;
  destroy_list_DB(w->shelves);
}



void free_ware_in_node(node *n)
{
  ware *w = (ware*)n->content;
  destroy_ware(w);
}





void del_node_zero_child(node **n)
{
  free(*n);
  n = NULL;
}

void del_node_one_child(node **n)
{
  if((*n)->right == NULL)
    {
      node *temp = (*n)->left;
      free(*n);
      *n = temp;
      return;
    }

  else if((*n)->left == NULL)
    {
      node *temp = (*n)->right;
      free(*n);
      *n = temp;
      return;
    }
    else assert(false);
}

void del_node_two_child(node **n)
{
  node **mtol = find_max_to_left(n);
  
  copy_node(*mtol, *n);
  
  rem_node(mtol, (*mtol)->key);

}



void copy_node(node *from, node *to)
{
  free_list_in_node(to);
  free_ware_in_node(to);
  free_key_in_node(to);


  to->key = from->key;
  to->content = from->content;

  from->content = NULL;

}



node **find_max_to_left(node **n)
{
  node **temp = &((*n)->left);

  while((*temp)->right) (*temp) = (*temp)->right;
    
  return temp;
}




void rem_node_in_tree(tree *t, void *key)
{
  rem_node(&(t->root), key);
}  


#define NodeIsLeaf(NODE) !(NODE->left) && !(NODE->right)
#define NodeOneChild(NODE) ((NODE->left) && !(NODE->right)) || (!(NODE->left) && (NODE->right)) 
#define NodeTwoChild(NODE) (NODE->left) && (NODE->right)


void rem_node(node **n, void *key)
{
  log_info("rem_node", "balle", "%s");
  log_info("rem_node", key, "%p");

  if((*n)->left && (*n)->right)
    {
      log_info("rem_node", "twochild", "%s");
      del_node_two_child(n);
    }
  else if((*n)->left || (*n)->right)
    {
      log_info("rem_node", "onechild", "%s");
      del_node_one_child(n);
    }
  else
    {
      log_info("rem_node", "zerochild", "%s");
      del_node_zero_child(n);
    }
}
