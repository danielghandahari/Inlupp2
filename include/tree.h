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

void del_node_zero_child(node **n);

void del_node_one_child(node **n);

void del_node_two_child(node **n);

void copy_node(node *from, node *to);



void rem_node_in_tree(tree *t, void *key);


node **find_max_to_left(node **n);


void remove_elem_in_tree(tree *t, void *key);

void remove_elem(node **n, void *key);



bool check_elems_left();

void *get_content(node *n);

node *get_root(tree *t);
#endif
