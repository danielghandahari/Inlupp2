#include <stdlib.h>
#include <string.h>

typedef struct _tree_ tree;
typedef struct _node_ node;
typedef struct _content_ content;

typedef struct _list_ list;
typedef struct _elem_ elem;



struct _tree_
{
  node *root;
};

struct _node_
{
  char *key;

  content *content;

  node *left;
  node *right;
};

struct _content_
{
  char *name;
  char *desc;
  int price;

  list *shelves;
};

// generel lista

struct _list_
{
  void *stuff;

  elem *first;
  elem *last;
};

struct _elem_
{
  void * box;

  elem *next;
};

// listan inehåll

struct shelf
{
  char* shelf_num;
  int amount;
};

struct sum
{
  int totamount;
};
