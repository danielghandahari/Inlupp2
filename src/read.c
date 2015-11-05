#define _GNU_SOURCE

#include <read.h>


#define read_stdin() read_stream(STREAM_INPUT)

char* read_stream(FILE *input)
{
  char *buffer = NULL;
  size_t buffer_size = 0;

  ssize_t num_of_chars = getline(&buffer, &buffer_size, input);
  
  check_debug(buffer, "'buffer' is NULL pointer");
  check_debug(num_of_chars > 0, "Unable to read stream or empty string");

  buffer[num_of_chars-1] = '\0';
  log_info("read_stream", buffer, "%s");
  
  return buffer;

 error:
  if(buffer) free(buffer);
  return NULL;
}



char* read_string()
{
  char *s = NULL;
  s = read_stdin();

  check_debug(s, "'read_stream' failed");

  for(int i = 0; s[i] != '\0'; ++i)
    {
      if(s[i] == '\n')
	{
	  s[i] = '\0';
	  break;
	}
    }

  check_debug(strlen(s) >= 1, "'tmp' is an empty string");
  return s;
  
 error:
  return NULL;
}



char read_char()
{
  char *tmp = NULL;
  tmp = read_stdin();

  check_debug(tmp, "'read_stream' failed");
  //  check_debug(tmp[1] == '\0', "'tmp' is a string");

  char c = tmp[0];
  check_debug(isalnum(c), "'c' is neither letter nor number");
  
  free(tmp);
  return c;
 error:
  return '\0';
}



bool is_number(char *s)
{
  for(int i = 0; s[i] != '\0'; ++i)
    {
      check_debug(isdigit(s[i]), "'s' is not numeric");
    }

  return true;

 error:
  return false;
}



int read_int()
{
  char *tmp = NULL;
  tmp = read_stdin();

  check_debug(tmp, "'read_string' failed");
  check_debug(is_number(tmp), "'is_number' failed");

  int i = 0;
  i = atoi(tmp);

  free(tmp);
  return i;

 error:
  return -1;
}



char* read_shelf()
{
  char *s = NULL;
  s = read_stdin();

  check_debug(s, "'read_string' failed");
  check_debug(strlen(s) > 1, "'s' is to short");
  check_debug(strlen(s) < 4, "'s' is to long");
  check_debug(isalpha(s[0]), "head of 's' is not alphabetic");
  check_debug(is_number(&s[1]), "Tail of 's' is not numeric");

  s[0] = toupper(s[0]);
  return s;

 error:
  return NULL;
}
