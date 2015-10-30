/**
 * @file tree.h
 * @author Daniel Ghandahari and Tim Svensson
 * @brief Header file for a general binary search tree
 *
 */


#ifndef __TREE__
#define __TREE__


typedef struct _tree_ tree;
typedef struct _node_ node;




node * create_node();

tree * create_tree();

//FÖR ADD_ITEM

bool check_node_exists_in_tree(tree *t, void *key);

node * check_node_exists(node **n, void *key);

int key_compare(void *key1, void *key2);



void append_node_in_tree(tree *t, node *mynode);

void append_node(node **n, node *mynode); 


node * get_node_in_tree(tree *t, void *key);

node * get_node(node **n, void *key);


bool find_node_in_tree(tree *t, void *key);

bool find_node(node **n, void *key);

  
//FÖR REMOVE_ITEM

// node * get_node_in_tree(tree *t, void *key);     finns i add

// bool find_elem_in_list(list *l, void *boxwithkey)     finns i add





bool check_elems_left();

void *get_content(node *n);

node *get_root(tree *t);
#endif
