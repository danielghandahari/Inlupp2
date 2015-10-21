#ifndef __LIST_S__
#define __LIST_S__

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

#endif
