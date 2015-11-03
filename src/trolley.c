#include <database.h>
#include <database_secret.h>
#include <trolley_secret.h>
#include <trolley.h>


int get_tot(tree *t, char *key)
{
  node *n = get_node_in_tree(t, key);
  ware *w = (ware*)n->content;

  return *((int*)w->shelves->stuff);
}



char * get_key(list *l, char *key)
{
  elem *e = get_elem_in_list_DB(l, key);

  trolley *t = (trolley*)e->box;

  return t->key;
}



int get_amount(list *l, char *key)
{
  elem *e = get_elem_in_list_DB(l, key);

  trolley *t = (trolley*)e->box;

  return t->amount;
}



void pack_trolley(tree *t, list *l, char *key, int amount)
{
  elem *e = get_elem_in_list_DB(l, key);

  if(e)
    {
      trolley *t = (trolley*)e->box;
      t->amount += amount;
    }
  else
    {
      char *tree_key = make_key(key);

      if(find_node_in_tree(t, tree_key))
	{
	  
	  elem *new_elem = create_elem();
	  trolley *new_trolley = (trolley*)new_elem->box;

	  new_trolley->key = key;
	  new_trolley->amount = amount;

	  insert_elem_in_list(l, new_elem);
      
	}
    }
}
