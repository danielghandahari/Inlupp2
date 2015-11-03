#ifndef __TROLLEY_H__
#define __TROLLEY_H__


typedef struct _trolley_ trolley;

int get_tot(tree *t, char *key);
int get_amount(list *l, char *key);
char * get_key(list *l, char *key);
void pack_trolley(tree *t, list *l, char *key, int amount);

#endif
