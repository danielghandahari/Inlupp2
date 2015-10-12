#include <std_include.h>
#include <read.h>

int main(int argc, char *argv[])
{
  char tmp[LENGTH];

  printf("Input text: ");

  if(read_string(tmp)) printf("You wrote: %s\n", tmp);
  else printf("FUCK! %s\n", tmp);

  printf("\nInput char: ");

  if(read_char(tmp)) printf("You wrote: %c\n", tmp[0]);
  else printf("FUCK! %s\n", tmp);

  int tmp_int = -1;
  printf("\nInput number: ");

  if(read_int(&tmp_int)) printf("You wrote: %d\n", tmp_int);
  else printf("FUCK! %d\n", tmp_int);

  printf("\nInput shelf: ");

  if(read_shelf(tmp)) printf("Your shelf: %s\n", tmp);
  else printf("FUCK! %s\n", tmp);

  return 0;
}
