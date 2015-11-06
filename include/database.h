 /**
 * @file database.h
 * @author Daniel Ghandahari and Tim Svensson
 * @brief Header file for the database
 *
 */


#ifndef __DATABASE__
#define __DATABASE__

#include <stdbool.h>



typedef struct _tree_ tree;


/**
 * @struct _ware_
 * Struct that holds strings name and desc, that holds information about the wares name and description. The struct also holds an int called price, representing a wares price. Struct holds a struct _list_ pointer pointing to a uniq list for a ware.
 * @see _ware_
 * @var _ware_::name
 * the name of the goods
 * @var _ware_::desc
 * description about the goods
 * @var _ware_::price
 * the price of this type of goods
 * @var _ware_::loc
 * location of the goods.
 * @var _ware_::shelves
 * pointer to a struct _list_for the ware
 */
typedef struct _ware_ ware;

typedef struct _shelves_ shelves;
typedef struct _shelf_ shelf;
typedef struct _list_ list;
typedef struct _elem_ elem;
typedef struct _node_ node;
typedef struct _sum_ sum;


/**
 * @brief returns string ware_name int uppercase letters
 */
char * make_key(char *ware_name); 



/**
 * @brief returns a pointer to a ware, allocated on the heap
 */
ware * create_ware();   


/**
 * @brief increments shelf, pointed by s, with incr. Increments total amonut of shelfs, pointed by l->shelves
 */
void incr_shelf_and_tot(list *l, char *key, int incr);




/**
 * @brief returns true if shelflocation key exists in the list pointed by l
 */
bool find_elem_in_list_DB(list *l, char *key);




/**
 * @brief returns element from list, pointed by l, where key is its shelflocation
 */
elem * get_elem_in_list_DB(list *l, char *key);


/**
 * @brief returns true if key is in tree, pointed by t
 */
bool check_shelf_used_in_tree(tree *t, char *key);   



/**
 * @brief returns true if shelflocation is used by a ware, where key is pointing to wares name, in the tree, where t points to the tree. shelfloc points to the shelflocation
 */
bool check_used_by_ware(tree *t, void *key, char *shelfloc);

//======
// ware
//======


/**
 * @brief returns pointer to a ware if that ware exists in the tree
 */
ware *ware_exists(tree *t, char *ware_name);

/**
 * @brief returns pointer to a ware at index index
 */
ware *get_ware_at(tree *t, int index);

/**
 * @brief checks is a ware is in the list w->shelves. otherwise checks the tree, pointed by t, if the shelf is used
 */
bool shelf_ok(tree *t, ware *w, char *ware_shelf);

/**
 * @brief if w points to an existing ware, creates a shelf for it or increments its existing shelf. otherwise creates a ware with the given parameters
 */
void insert_ware(tree *t, ware *w, char *ware_name, char *ware_desc, int ware_price, char *ware_shelf, int ware_amount);

/**
 * @brief returns a pointer to a wares name
 */

ware *get_ware_at(tree *t, int index);
ware *get_ware(node *n);
char *get_ware_name(ware *w);
int get_tot_ware(ware *w);

/**
 * @brief returns a pointer to a wares description
 */
char *get_ware_desc(ware *w);

/**
 * @brief returns wares price
 */
int get_ware_price(ware *w);

//======
// list
//======

/**
 * @brief returns a pointer to a wares list
 */
list *get_list(ware *w);

/**
 * @brief returns a pointer to a wares lists first element
 */
elem *get_first_shelf(ware *w);

/**
 * @brief returns a pointer to next element
 */
elem *get_next_shelf(elem *e);
int   get_num_shelves(ware *w);

//=======
// shelf
//=======

/**
 * @brief returns a pointer to an elements shelflocation
 */
char *get_shelf_loc(elem *e);

char *get_shelf_loc_at(ware *w, int index);

void remove_shelf_at(tree *t, ware *w, int index);

/**
 * @brief returns amount of a ware on a shelflocation
 */
int get_shelf_amount(elem *e);

/**
 * @brief returns a pointer to a ware 
 */
ware *get_ware(node *n);


/**
 * @brief frees all allocated memory in tree, pointed by t
 */
void destroy_warehouse(tree *t);


/**
 * @brief frees all allocated memory in list, pointed by l
 */
void destroy_list_DB(list *l);

/**
 * @brief frees all allocated memory in ware, pointed w
 */
void destroy_ware(ware *w);

/**
 * @brief frees all allocated memory in node, pointed by n
 */
void destroy_node_DB(node *n);

void destroy_only_node(node *n);

/**
 * @brief removes element from list, pointed by l
 */
void rem_elem_in_list(list *l, void *elembox);




/**
 * @brief replacing wares name with a new name, pointed by new_name. generates a new key for the node with the key pointed by old_key. The node is in the tree, pointed by t
 */
void edit_name(tree *t, char *old_key, char *new_name);

/**
 * @brief replacing wares description with a new description, pointed by new_desc. The node, with the key, pointed by key, is in the tree, pointed by t
 */
void edit_desc(tree *t, char *key, char *new_desc);

/**
 * @brief replacing wares description with a new price, new_price. The node, with the key, pointed by key, is in the tree, pointed by t
 */
void edit_price(tree *t, char *key, int new_price);

/**
 * @brief replacing wares, lists shelf location with a new shelf location, pointed by, new_shelf. The node, with the key, pointed by key, is in the tree, pointed by t. old_shelf is used to find the right element in the list
 */
void edit_shelf_location(tree *t, char *key, char *old_shelf, char *new_shelf);

/**
 * @brief replacing wares, lists shelf amount with a new shelf amount, new_amount. The node, with the key, pointed by key, is in the tree, pointed by t. old_shelf is used to find the right element in the list
 */
void edit_shelf_amount(tree *t, char *key, char *old_shelf, int new_amount);






void rem_node_in_tree(tree *t, void *key);









#endif
