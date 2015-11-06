#define _GNU_SOURCE

#include <stdbool.h>
#include <database_secret.h>
#include <stdlib.h>
#include <string.h>
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
 

bool find_elem_DB(elem *e, char *key);
void incr_shelf(shelf *s, int incr);
elem * get_elem_DB(elem *e, char *key);
bool check_shelf_used(node **n, char *key);  
ware *get_ware_at_aux(node *n, int index, int *acc);
void destroy_warehouse_subtree(node **n);
void rem_elem(elem **e, void *elembox);
void free_key_in_node(node *n);
void free_list_in_node(node *n);
void free_ware_in_node(node *n);
void del_node_two_child(node **n);
void del_node_one_child(node **n);
void del_node_zero_child(node **n);
void copy_node(node *from, node *to);
node **find_max_to_left(node **n);
void rem_node(node **n, void *key);



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



void incr_shelf_and_tot(list *l, char *shelf_loc, int incr)
{
  elem *e = get_elem_in_list_DB(l, shelf_loc);
  log_info("incr_shelf_and_tot", e, "%p");

  shelf *s = (shelf*)e->box;
  log_info("incr_shelf_and_tot", s, "%p");

  incr_shelf(s, incr);
  log_info("incr_shelf_and_tot", s->amount, "%d");

  int *tot = (int*)l->stuff;
  *tot += incr;
}



void incr_shelf(shelf *s, int incr)
{
  log_info("incr_shelf", s->amount, "%d");
  s->amount += incr;
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
  
  node *n = get_node_in_tree(t, key);
  log_info("ware_exists", n, "%p");
  ware *w = NULL;

  if(!n) goto exit;

  w = (ware*)n->content;
  log_info("ware_exists", w, "%p");

 exit:
  free(key);
  return w;
}

ware *get_ware_at_aux(node *n, int index, int *acc)
{
  log_info("get_ware_at_aux", n, "%p");
  log_info("get_ware_at_aux", *acc, "%d");
  log_info("get_ware_at_aux", index, "%d");

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
  ware *w = NULL;

  if(!root) goto exit;

  w = get_ware_at_aux(root, index, acc);
  log_info("get_ware_at", w, "%p");

 exit:
  if(acc) free(acc);
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

	  incr_shelf_and_tot(w->shelves, s->location, shelfamount);       
	}
    }
  else
    {
      node *n = create_node();
      ware *w = create_ware();
      list *l = create_list();
      elem *e = create_elem();
      shelf *s = create_shelf();
      int *tot = calloc(1, sizeof(int));
      
      log_info("insert_ware", n, "%p");
      log_info("insert_ware", w, "%p");
      log_info("insert_ware", l, "%p");
      log_info("insert_ware", e, "%p");
      log_info("insert_ware", s, "%p");

      //list
      *tot = shelfamount;
      l->stuff = tot; 
      
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
int get_tot_ware(ware *w)
{
  list *l = get_list(w);
  int *tot = (int*)l->stuff;
  return *tot;
}

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
  assert(t);
  assert(w);
  elem **shelf = &(w->shelves->first);

  for(int i = 0; i < index; i++)
    {
      shelf = &(*shelf)->next;
    }

  rem_elem_in_list(w->shelves, (*shelf)->box);

  char *key = make_key(get_ware_name(w));
  
  if(!get_first_shelf(w)) rem_node_in_tree(t, key);

  free(key);
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



void destroy_shelf(shelf *s)
{
  free(s->location);
  free(s);
}

void destroy_elem(elem *e)
{
  if(e->next) destroy_elem(e->next);

  shelf *s = (shelf*)e->box;
  if(s) destroy_shelf(s);
  free(e);
}

void destroy_list_DB(list *l)
{
  if(l->first) destroy_elem(l->first);

  free(l->stuff);
  free(l);
}

void destroy_ware(ware *w)
{
  if(w->shelves) destroy_list_DB(w->shelves);

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
  if(n->content) destroy_ware(n->content);
  free(n->key);
  free(n);
}

void destroy_warehouse_subtree(node **n)
{
  if((*n)->left) destroy_warehouse_subtree(&(*n)->left);
  if((*n)->right) destroy_warehouse_subtree(&(*n)->right);
 
  destroy_node_DB(*n);
}

void destroy_warehouse(tree *t)
{
  assert(t);
  
  if(t->root) destroy_warehouse_subtree(&(t->root));

  t->root = NULL;
  free(t);
}




void rem_elem_in_list(list *l, void *elembox)
{
  assert(l);

  rem_elem(&(l->first), elembox);

  if(l->first == NULL) l->last = NULL;
  else l->last = get_last_elem(&(l->first));
}



void rem_elem(elem **e, void *elembox)
{
  assert(*e);
  
  shelf *find_s = (shelf*)elembox;
  shelf *e_s = (shelf*)(*e)->box;

  if(key_compare(find_s->location, e_s->location) == 0)
    {
      elem *e_rem = *e;
      *e = (*e)->next;
      free(e_s->location);
      free(e_s);
      free(e_rem);
    }
  else rem_elem(&((*e)->next), elembox);
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




void edit_name(tree *t, char *old_name, char *name)
{
  char *old_key = make_key(old_name);
  node *old_node = get_node_in_tree(t, old_key);

  node *new_node = copy_node(old_node);
  char *new_name = strdup(name);
  char *new_key = make_key(name);
  ware *new_ware = (ware*)new_node->content;

  if(new_ware->name) free(new_ware->name);
  new_ware->name = new_name;

  if(new_node->key) free(new_node->key);
  new_node->key = new_key;
  new_node->left = NULL;
  new_node->right = NULL;
  
  append_node_in_tree(t, new_node);

  rem_node_in_tree(t, old_key);
  free(old_key);
}


void edit_desc(tree *t, char *name, char *new_desc)
{
  char *my_new_desc = strdup(new_desc);
  char *key = make_key(name);
  node *n = get_node_in_tree(t, key);
  ware *w = (ware*)n->content;

  free(w->desc);
  w->desc = my_new_desc;

  free(key);
}



void edit_price(tree *t, char *name, int new_price)
{
  char *key = make_key(name);
  node *n = get_node_in_tree(t, key);
  ware *w = (ware*)n->content;
  
  w->price = new_price;
  
  free(key);
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

  free(key);
}


void edit_shelf_amount(tree *t, char *name, char *old_shelf, int new_amount)
{
  char *key = make_key(name);
  node *n = get_node_in_tree(t, key);
  ware *w = (ware*)n->content;
  elem *e = get_elem_in_list_DB(w->shelves, old_shelf);
  shelf *s = (shelf*)e->box;

  s->amount = new_amount;

  free(key);
}

void del_node_zero_child(node **n)
{
  destroy_node_DB(*n);
  *n = NULL;
}

void del_node_one_child(node **n)
{
  node *next_node = NULL;

  if((*n)->right != NULL)
    {
      next_node = (*n)->right;
      (*n)->right = NULL;
    }
  else if((*n)->left != NULL)
    {
      next_node = (*n)->left;
      (*n)->left = NULL;
    }
    else assert(false);

  del_node_zero_child(n);
  *n = next_node;
}

void del_node_two_child(node **n)
{
  node **n_leaf = find_max_to_left(&((*n)->left));
  node *tmp_left = (*n)->left;
  node *tmp_right = (*n)->right;

  destroy_node_DB(*n);
  *n = copy_node(*n_leaf);

  (*n)->left = tmp_left;
  (*n)->right = tmp_right;
  
  rem_node(&(*n)->left, (*n_leaf)->key);
}

shelf *copy_shelf(shelf *src)
{
  shelf *copy = create_shelf();
  memcpy(copy, src, sizeof(shelf));

  copy->location = strdup(src->location);

  return copy;
}

elem *copy_elem(elem *src)
{
  elem *copy = create_elem();
  memcpy(copy, src, sizeof(elem));

  if(src->next) copy->next = copy_elem(src->next);

  if(src->box) copy->box = copy_shelf(src->box);

  return copy;
}

list *copy_list(list *src)
{
  list *copy = create_list();
  memcpy(copy, src, sizeof(list));

  //borde funka, kan läcka
  if(src->stuff)
    {
      sum *s = calloc(1, sizeof(sum));
      memcpy(s, src->stuff, sizeof(sum));
      copy->stuff = s;
    }

  if(src->first)
    {
      copy->first = copy_elem(src->first);
      copy->last = get_last_elem(&(copy->first));
    }

  return copy;
}

ware *copy_ware(ware *src)
{
  ware *copy = create_ware();
  memcpy(copy, src, sizeof(ware));

  if(src->shelves) copy->shelves = copy_list(src->shelves);
  copy->name = strdup(src->name);
  copy->desc = strdup(src->desc);
  copy->price = src->price;

  return copy;
}

node *copy_node(node *src)
{
  node *copy = create_node();
  memcpy(copy, src, sizeof(node));
 
  copy->content = copy_ware(src->content);
  copy->key = strdup(src->key);
  // left/right kopierade tack vare memcpy

  return copy;
}

node **find_max_to_left(node **n)
{
  while((*n)->right) n = &(*n)->right;

  return n;
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
  int comp_result = key_compare(((*n)->key), key);

  if     (comp_result < 0) rem_node(&(*n)->right, key);
  else if(comp_result > 0) rem_node(&(*n)->left, key);
  else
    {
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
}
