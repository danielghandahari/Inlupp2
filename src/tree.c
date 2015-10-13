1#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "tree.h"

#define Equal action == 0
#define Left action > 0
#define Right action < 0
#define PtrToLeftNode &((*current)->left
#define PtrToRightNode &((*current)->right
			 
tree * create_tree()
{
  tree *t = calloc(1, sizeof(tree));
  return t;
}



node * create_node()
{
  node *n = calloc(1, sizeof(node));
  return n;
}


			 
bool check_node_exists(node **n, node *mynode)
{

//assert(mynode == NULL);

  node **current = n;

  while (*current != NULL)
    {
      int action = key_compare((*current)->key, mynode->key); 

      if (Equal) return true;

      if (Left)
	{
	  current = PtrToLeftNode;
	  check_node_exists(current, mynode);
	}

      if (Right)
	{
	  current = PtrToRightNode;
	  check_node_exists(current, mynode);
	}
    }
  return false;
}


			 
bool check_node_exists_in_tree(tree *t, node *mynode)
{
//assert(t == NULL);
  return check_node_exists(&(t->root), mynode);   
}


			 
void append_node(node **n, node *mynode)
{
//assert(mynode == NULL);

  node **current = n;

  if((*current) == NULL)
    {
      **current = &(mynode);      
    }

  void *key1 = (*current)->key;
  void *key2 = mynode->key;
  int action = key_compare(key1, key2);
  
  if(Equal) return;

  if(Right) append_node(PtrToRightNode, mynode);
    
  if(Left) append_node(PtrToLeftNode, mynode);
}



void append_node_in_tree(tree *t, node *mynode)
{
//assert(t == NULL);
  return append_node(&(t->root), mynode);
}
