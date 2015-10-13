#ifndef __LIST__
#define __LIST__

typedef struct _list_ list;
typedef struct _elem_ elem;

struct _list_
{
  void *stuff;

  elem *first;
  elem *last;
};

struct _elem_
{
  void *box;

  elem *next;
};

bool check_elem_in_list(list *l, elem *e); 

<<<<<<< HEAD
=======
bool check_elem_in_list(list *l, elem *e); 

>>>>>>> 981ef866c627a34aedfbacaca8aa9b0503134503
int elem_compare(void *e1, void *e2); 


void generate_new_elem();


#endif
