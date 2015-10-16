#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <menu.h>

int main()
{
  FILE *inlupp2_stderr = fopen("inlupp2_stderr", "w");
  dup2(fileno(inlupp2_stderr), STDERR_FILENO);

  menu();

  fclose(inlupp2_stderr);

  return 0;
}
