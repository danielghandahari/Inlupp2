#define _GNU_SOURCE

#include <read.h>

#include <ctype.h>
#include <stdlib.h>



// TODO empty strings are to be catched and killed
bool read_stream(char *string_dest, size_t buffer_size, FILE *input)
{
  char *buffer = (char *)calloc(1, sizeof(char) * buffer_size);

  ssize_t num_of_chars = getline(&buffer, &buffer_size, input);
  
  check_debug(buffer, "\tread_stream\tbuffer is NULL pointer");
  check_debug(num_of_chars > 0, "\tread_stream\tunable to read stream or empty string");

  buffer[num_of_chars] = '\0';
  strcpy(string_dest, buffer);

  log_info("\tread_stream\tbuffer \"%s\"", buffer);
  free(buffer);
  return true;

 error:
  free(buffer);
  return false;
}



#define read_string_aux(A) read_stream(A, STREAM_LENGTH, STREAM_INPUT)

bool read_string(char *dest)
{
  char tmp[STREAM_LENGTH] = {'\0'};
  check_debug(read_string_aux(tmp), "\tread_string\tread_stream failed");

  for(int i = 0; tmp[i] != '\0'; ++i)
    {
      if(tmp[i] == '\n')
	{
	  tmp[i] = '\0';
	  break;
	}
    }

  check_debug(strlen(tmp) > 1, "\tread_string\tempty string");

  log_info("\tread_string\ttmp \"%s\"", tmp);
  strcpy(dest, tmp);

  return true;
  
 error:
  return false;
}



#define read_char_aux(A) read_stream(tmp, 1, STREAM_INPUT)

bool read_char(char *dest)
{
  char tmp[2] = {'\0'};

  check_debug(read_char_aux(tmp), "\tread_char\tread_stream failed");
  check_debug(isalnum(tmp[0]), "\tread_char\ttmp is not alphabetic nor numeric");
  log_info("\tread_char\ttmp '%c'", tmp[0]);

  dest[0] = tmp[0];

  return true; 

 error:
  return false;
}



bool is_number(char *s)
{
  for(int i = 0; s[i] != '\0'; ++i)
    {
      check_debug(isdigit(s[i]), "\tis_number\ts is not numeric");
    }

  return true;

 error:
  return false;
}



bool read_int(int *dest)
{
  char buffer[STREAM_LENGTH];

  check_debug(read_string(buffer), "\tread_int\tread_string failed");
  check_debug(strlen(buffer) > 1, "\tread_int\tempty string");
  check_debug(is_number(buffer), "\tread_int\tbuffer is not a numeric value");
  
  log_info("\tread_int\tbuffer \"%s\"", buffer);
  *dest = atoi(buffer);

  return true;

 error:
  return false;
}



bool read_shelf(char *dest)
{
  char s[STREAM_LENGTH];

  check_debug(read_string(s), "\tread_shelf\tread_string failed");
  check_debug(isalpha(s[0]), "\tread_shelf\ts[0] is not alphabetic");
  check_debug(is_number(&s[1]), "\tread_shelf\ttail of s is not mumeric");

  s[0] = toupper(s[0]);
  log_info("\tread_shelf\ts \"%s\"", s);

  strcpy(dest, s);

  return true;

 error:
  return false;
}
