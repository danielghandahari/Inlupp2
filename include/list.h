/**
 * @file list.h
 * @author Daniel Ghandahari and Tim Svensson
 * @brief Header file for a general linked list
 *
 */

#ifndef __LIST__
#define __LIST__


typedef struct _list_ list;
typedef struct _elem_ elem;



elem * create_elem();

list * create_list();

bool find_elem_in_list(list *l, void *elembox);



elem * get_first_elem(list *l);



elem *get_elem(elem *e, void *elembox);

elem * get_elem_in_list(list *l, void *elembox);






int elem_compare(void *e1, void *e2); 


void insert_elem_in_list(list *l, elem *e);

elem * get_last_elem(elem **e);






#endif
