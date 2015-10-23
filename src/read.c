#define _GNU_SOURCE

#include <read.h>



bool read_stream(char *string_dest, size_t buffer_size, FILE *input)
{
  char *buffer = (char *)calloc(1, sizeof(char) * buffer_size);

  ssize_t num_of_chars = getline(&buffer, &buffer_size, input);
  
  check_debug(buffer, "'buffer' is NULL pointer");
  check_debug(num_of_chars > 0, "Unable to read stream or empty string");

  buffer[num_of_chars-1] = '\0'; //This removes the '\n' at the end of the buffer
  strcpy(string_dest, buffer);

  log_info("read_stream", buffer, "%s");
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
  check_debug(read_string_aux(tmp), "'read_stream' failed");

  for(int i = 0; tmp[i] != '\0'; ++i)
    {
      if(tmp[i] == '\n')
	{
	  tmp[i] = '\0';
	  break;
	}
    }

  check_debug(strlen(tmp) >= 1, "'tmp' is an empty string");
  strcpy(dest, tmp);
  return true;
  
 error:
  return false;
}



#define read_char_aux(A) read_stream(tmp, 1, STREAM_INPUT)

bool read_char(char *dest)
{
  char tmp[2] = {'\0'};

  check_debug(read_char_aux(tmp), "'read_stream' failed");
  check_debug(isalnum(tmp[0]), "'tmp' is not alphabetic nor numeric");

  dest[0] = tmp[0];
  return true; 

 error:
  return false;
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



bool read_int(int *dest)
{
  char buffer[STREAM_LENGTH];

  check_debug(read_string(buffer), "'read_string' failed");
  check_debug(is_number(buffer), "'is_number' failed");
  *dest = atoi(buffer);
  return true;

 error:
  return false;
}



bool read_shelf(char *dest)
{
  char s[STREAM_LENGTH];

  check_debug(read_string(s), "'read_string' failed");
  check_debug(strlen(s) > 1, "'s' is to short");
  check_debug(strlen(s) < 4, "'s' is to long");
  check_debug(isalpha(s[0]), "head of 's' is not alphabetic");
  check_debug(is_number(&s[1]), "Tail of 's' is not numeric");

  s[0] = toupper(s[0]);
  strcpy(dest, s);
  return true;

 error:
  return false;
}
