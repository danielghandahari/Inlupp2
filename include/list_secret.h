/**
 * @file list_secret.h
 * @author Daniel Ghandahari and Tim Svensson
 * @brief Hidden header file for structs for list.c
 *
 */


#ifndef __LIST_S__
#define __LIST_S__

#include <list.h>

/**
 * @brief Type for general list
 */
struct _list_
{
  void *stuff;

  elem *first;
  elem *last;
};



/**
 * @brief Type for general element
 */
struct _elem_
{
  void *box;

  elem *next;
};

#endif
