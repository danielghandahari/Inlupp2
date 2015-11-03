#include <tree_secret.h>
#include <list_secret.h>




/**
 * @file database_secret.h
 * @author Daniel Ghandahari and Tim Svensson
 * @brief Hidden header file for structs for database.c
 *
 */


#ifndef __DB_S__
#define __DB_S__

/**
 * @brief Type for wares in database
 */

//ICKE-GENERELLA STRUCTAR FÖR TREE.C
struct _ware_
{
  char *name;
  char *desc;
  int price;

  list *shelves;
};
//==================================


/**
 * @brief Type for wares shelfs in database
 */

//ICKE-GENERELLA STRUCTAR FÖR LIST.C

struct _shelf_
{
  char *location;
  int amount;
};

struct _sum_
{
  int totalmount;
};
//===================================


#endif









