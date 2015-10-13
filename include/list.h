#ifndef __LIST__
#define __LIST__

typedef struct _list_ list;
typedef struct _elem_ elem;


bool check_elem_in_list(list *l, elem *e); 

int elem_compare(void *e1, void *e2); 


void generate_new_elem();


#endif
