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
 * @brief Converts string into uppercase letters
 * @param ware_name is string beeing converted to uppercase letters.
 * @result Returns string in uppercase letters.
 */
char * make_key(char *ware_name); 




/**
 * @brief Allocates memory for a ware
 * @param void
 * @result Returns pointer to allocated ware
 */
ware * create_ware();   


/**
 * @brief Increments shelf with shelf flocation shelf_loc and total amount of shelves, in list l, with the amount of incr.
 * @param l points to the linked list containing the shelf
 * @param shelf_loc is the string for the shelf location
 * @param incr is the amount to increment the amount of shelf and totalamount of shelves
 * @result 
 */
void incr_shelf_and_tot(list *l, char *shelf_loc, int incr);





/**
 * @brief Says whether key is in l
 * @param l is a linked list 
 * @param string key, that can be in l
 * @result returns true if key is in l, otherwise false
 */
bool find_elem_in_list_DB(list *l, char *key);




/**
 * @brief Gives the element represented by key, in list l
 * @param l is a linked list
 * @param string key, that can be in l
 * @result returns the element if key is in l, otherwise NULL
 */
elem * get_elem_in_list_DB(list *l, char *key);


/**
 * @brief Checks whether key is used by any ware in t
 * @param t is a binary search tree
 * @param key is a shelf location
 * @result returns true if key is used by any ware in t, otherwise false
 */
bool check_shelf_used_in_tree(tree *t, char *key);   


//======
// ware
//======



/**
 * @brief checks whether ware_name exists in t
 * @param t is a binary search tree
 * @param ware_name represents a ware in a BStree
 * @result returns the ware if ware_name exists in t, otherwise false
 */
ware *ware_exists(tree *t, char *ware_name);


/**
 * @brief Gives a ware at index index, in t
 * @param t is a binary search tree
 * @param index represents an index for a ware in t
 * @result returns the ware if valid index is inputed, otherwise NULL
 */
ware *get_ware_at(tree *t, int index);


/**
 * @brief checks if ware_shelf is in the linked list of w. if not, checks if ware_shelf is in othe other wares linked lists in t
 * @param t is a binary search tree
 * @param w represents a ware in t
 * @param ware_shelf represents the name of a ware
 * @result returns true
 */
bool shelf_ok(tree *t, ware *w, char *ware_shelf);


/**
 * @brief Inserts a ware in t, with parameters ware_name, ware_desc, ware_price, ware_shelf and ware_amount if w is NULL. if w is NULL, a ware with the mentioned parameters is created in t
 * @param t is a binary search tree
 * @param w represents a ware in t
 * @param ware_name represents a wares name
 * @param ware_desc represents a wqares description
 * @param ware_price represents a wares price
 * @param ware_shelf represents a shhelf for a ware
 * @param ware_amount represents the amount of a shelf
 * @result void
 */
void insert_ware(tree *t, ware *w, char *ware_name, char *ware_desc, int ware_price, char *ware_shelf, int ware_amount);



/**
 * @brief Gives ware at an index index
 * @param t is a binary search tree
 * @param index is an index for a ware
 * @result returns ware for specific index index
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
