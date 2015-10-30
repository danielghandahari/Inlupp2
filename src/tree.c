#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <tree.h>
#include <tree_secret.h>
#include <dbg.h>



#define Equal action == 0
#define Left action > 0
#define Right action < 0
#define PtrToLeftNode(NODE) &((*NODE)->left)
#define PtrToRightNode(NODE) &((*NODE)->right)




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
			 
node * check_node_exists(node **nn, void *key)
{
  log_info("check_node_exists", nn, "%p");
  log_info("check_node_exists", key, "%p");

  if(*nn == NULL) return NULL;

  node *n_current = *nn;
  void *n_key = n_current->key;

  log_info("check_node_exists", n_key, "%p");

  int result = key_compare(n_key, key);

  log_info("check_node_exists", result, "%d");

  if(result == 0) return n_current;
  else if(result < 0) return check_node_exists(&(n_current->left), key);
  else if(result > 0) return check_node_exists(&(n_current->right), key);

  return NULL;
}


			 
bool check_node_exists_in_tree(tree *t, void *key)
{
  log_info("check_node_exists_in_tree", t, "%p");
  log_info("check_node_exists_in_tree", key, "%p");

  assert(t == NULL);
  return check_node_exists(&(t->root), key);   
}


			 
void append_node(node **n, node *mynode)
{
  log_info("append_node", *n, "%p");
  log_info("append_node", mynode, "%p");

  assert(mynode != NULL);

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
  assert(t != NULL);
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



void *get_content(node *n)
{
  return n->content;
}

node *get_root(tree *t)
{
  return t->root;
}



