#include <read.h>
#include <dbg.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>


void test()
{
  char tmp[512];

  printf("read_string\n> ");
  if(read_string(tmp)) printf("Echo\t%s\n", tmp);
  else printf("Failed\n");

  printf("read_char\n> ");
  if(read_char(tmp)) printf("Echo\t%c\n", tmp[0]);
  else printf("Failed\n");

  int tmpp;

  printf("read_int\n> ");
  if(read_int(&tmpp)) printf("Echo\t%d\n", tmpp);
  else printf("Failed\n");

  printf("read_shelf\n> ");
  if(read_shelf(tmp)) printf("Echo\t%s\n", tmp);
  else printf("Failed\n");

}



int main(int argc, char *argv[])
{
  test();

  return 0;
}
