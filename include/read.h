#ifndef __READ_H__
#define __READ_H__

#include <dbg.h>

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>

#define LENGTH 512
#define INPUT stdin

bool read_char(char *char_ptr);
bool read_string(char *string_ptr);
bool read_int(int *int_ptr);
bool read_shelf(char *shelf_ptr);

#endif
