#ifndef __TREE__
#define __TREE__


typedef struct _tree_ tree;
typedef struct _node_ node;

node * create_node();

tree * create_tree();
  

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



bool check_node_exists_in_tree(tree *t, node *mynode);

bool check_node_exists(node **n, node *mynode);

int key_compare(void *key1, void *key2);



void append_node_in_tree(tree *t, node *mynode);

void append_node(node **n, node *mynode); 


#endif
