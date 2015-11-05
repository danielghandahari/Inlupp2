#ifndef __READ_H__
#define __READ_H__

#include <dbg.h>

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


#include <unistd.h>

//#define STREAM_LENGTH 512
#define STREAM_INPUT stdin

char read_char();
char* read_string();
int read_int();
char* read_shelf();

#endif
