#ifndef __TREE_SEC__
#define __TREE_SEC__


struct _tree_
{
  node *root;
} ;

			 
struct _node_
{
  void *key;

  void *content;

  node *left;
  node *right;
};


#endif
