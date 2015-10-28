/**
 * @file tree_secret.h
 * @author Daniel Ghandahari and Tim Svensson
 * @brief Hidden header file for structs for tree.c
 *
 */

#ifndef __TREE_SEC__
#define __TREE_SEC__


/**
 * @brief Type for general tree
 */
struct _tree_
{
  node *root;
} ;


/**
 * @brief Type for general node
 */			 
struct _node_
{
  void *key;

  void *content;

  node *left;
  node *right;
};


#endif
