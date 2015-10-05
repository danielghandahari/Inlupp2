#include <stdlib.h>
#include <bool.h>
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

struct _list_
{
  int tot_amount;
  elem *first;
  elem *last;
}

struct _elem_
{
  char *shelf;
  int amount;
  elem *next;
}
