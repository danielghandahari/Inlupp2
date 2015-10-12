#include<stdbool.h>
#include<string.h>
#include"tree.h"


struct _tree_
{
  node *root;
};

struct _node_
{
  void *key;

  void *content;

  node *left;
  node *right;
};


node * create_tree()
{
  tree *t = calloc(1, sizeof(tree));
  return t;
}




bool check_node_exists(node **n, node *mynode)
{
  while ((*n) != NULL)
    {
      int action = key_compare((*n)->key, mynode->key); //TODO: MACRO?

      if (action == 0) return true;

      if (action > 0)
	{
	  *n = (*n)->left;
	  check_node_exists(n, mynode);
	}

      if (action < 0)
	{
	  *n = (*n)->right;
	  check_node_exists(n, mynode);
	}
    }
  return false;
}


bool check_node_exists_in_tree(tree *t, node *mynode)
{
  return check_node_exists(&(t->root), mynode);   // TODO: MACRO?
}



node * create_node()
{
  node *n = calloc(1, sizeof(node));
  return n;
}




void append_node_in_tree(tree *t, node *mynode)
{
  assert(t == NULL);

  return append_node(&(t->root), mynode);
}


void append_node(node **n, node *mynode)
{
  if((*n) == NULL)
    {
      node *mynodecopy = create_node();
      **n = mynodecopy;
    }

  void *key1 = (*n)->key;
  void *key2 = mynode->key;
  int action = key_compare(key1, key2);
  
  if(action == 0) return;

  if(action < 0) append_node(&((*n)->right), mynode);
    
  if(action > 0) append_node(&((*n)->left), mynode);
}



