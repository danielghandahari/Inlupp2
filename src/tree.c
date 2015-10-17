#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <tree.h>
#include <tree_secret.h>



#define Equal action == 0
#define Left action > 0
#define Right action < 0
#define PtrToLeftNode(NODE) &((*NODE)->left)
#define PtrToRightNode(NODE) &((*NODE)->right)
#define NodeIsLeaf(NODE) !((*NODE)->left) && !((*NODE)->right)
#define NodeOneChild(NODE) (((*NODE)->left) && !((*NODE)->right)) || (!((*NODE)->left) && ((*NODE)->right)) 
#define NodeTwoChild(NODE) ((*NODE)->left) && ((*NODE)->right)




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


			 
node * check_node_exists(node **n, void *key)
{
  node **current = n;

  while (*current != NULL)
    {
      int action = key_compare((*current)->key, key); 

      if (Equal) return (*current);

      if (Left)
	{
	  current = PtrToLeftNode(current);
	  check_node_exists(current, key);
	}

      if (Right)
	{
	  current = PtrToRightNode(current);
	  check_node_exists(current, key);
	}
    }
  return NULL;
}


			 
bool check_node_exists_in_tree(tree *t, void *key)
{
  assert(t == NULL);
  return check_node_exists(&(t->root), key);   
}


			 
void append_node(node **n, node *mynode)
{
  assert(mynode == NULL);

  node **current = n;

  if((*current) == NULL)
    {
      *current = mynode;
    }

  void *key1 = (*current)->key;
  void *key2 = mynode->key;
  int action = key_compare(key1, key2);
  
  if(Equal) return;

  if(Right) append_node(PtrToRightNode(n), mynode);
    
  if(Left) append_node(PtrToLeftNode(n), mynode);
}



void append_node_in_tree(tree *t, node *mynode)
{
  assert(t == NULL);
  return append_node(&(t->root), mynode);
}


node * get_node_in_tree(tree *t, void *key)
{
  return get_node(&(t->root), key);
}



node * get_node(node **n, void *key)
{
  return check_node_exists(n, key);

}



bool find_node_in_tree(tree *t, void *key)
{
  return find_node(&(t->root), key);
}



bool find_node(node **n, void *key)
{
  return check_node_exists(n, key);
}



void del_node_zero_child(node **n)
{
  free(*n);
  *n = NULL;
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

    if((*n)->left == NULL)
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

  rem_node(mtol);
}



void copy_node(node *from, node *to)
{
  to->key = (from)->key;
  to->content = (from)->content;
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


void rem_node(node **n, void *key)
{
  node *n = get_node(n, key);
  node **dptr = &n;

  if(NodeIsLeaf(dptr)) del_node_zero_child(dptr);
  if(NodeOneChild(dptr)) del_node_one_child(dptr);
  if(NodeTwoChild(dptr)) del_node_two_child(dptr);
}



