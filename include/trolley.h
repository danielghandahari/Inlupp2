#ifndef __TROLLEY_H__
#define __TROLLEY_H__


typedef struct _trolley_ trolley;

trolley * create_trolley();
bool trolley_is_empty(list *l);
int get_trolley_price(list *l);
void incr_amount(elem *e, int incr);
void incr_trolley_price(list *l, int incr);
int get_tot(tree *t, char *key);
int get_amount(list *l, char *key);
char * get_key(list *l, char *key);
void pack_trolley(list *l, char *ware_name, int amount);
elem * get_elem_trolley(list *l, char *key);
elem * get_elem_trolley_aux(elem *e, char *key);
void destroy_trolley(list *l);

#endif
