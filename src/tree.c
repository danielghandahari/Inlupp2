#include<stdbool.h>
#include<string.h>
#include<tree.h>
<<<<<<< HEAD

#define Equal action == 0
#define Left action > 0
#define Right action < 0
#define PtrToLeftNode &((*current)->left
#define PtrToRightNode &((*current)->right


=======
>>>>>>> origin/daniel

#define Equal action == 0

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

#define PtrToLeftNode



bool check_node_exists(node **n, node *mynode)
{
  node **current = n;

  while (*current != NULL)
    {
      int action = key_compare((*current)->key, mynode->key); //TODO: MACRO?

      if (Equal) return true;

      if (Left)
	{
<<<<<<< HEAD
	  current = PtrToLeftNode;
=======
	  current = &((*current)->left);
>>>>>>> origin/daniel
	  check_node_exists(current, mynode);
	}

      if (Right)
	{
<<<<<<< HEAD
	  current = PtrToRightNode;
=======
	  current = &((*n)->righ)t;
>>>>>>> origin/daniel
	  check_node_exists(current, mynode);
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
      **n = &(mynode);      //KOLLA
    }

  void *key1 = (*n)->key;
  void *key2 = mynode->key;
  int action = key_compare(key1, key2);
  
  if(Equal) return;

  if(Right) append_node(&((*n)->right), mynode);
    
  if(Left) append_node(&((*n)->left), mynode);
}



