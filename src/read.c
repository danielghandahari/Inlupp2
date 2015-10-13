#define _GNU_SOURCE

#include <read.h>

#include <ctype.h>
#include <stdlib.h>

// TODO empty strings are to be catched and killed
bool read_stdin(char *string_dest, size_t buffer_size)
{
  char *buffer = (char *) malloc(sizeof(char) * buffer_size);
  ssize_t string_length = getline(&buffer, &buffer_size, INPUT);

  check_debug(string_length > 0, "Unable to read stream or empty string");

  buffer[string_length] = '\0';
  strcpy(string_dest, buffer);

  log_info("buffer %s", buffer);
  free(buffer);
  return true;

 error:
  free(buffer);
  return false;
}


bool read_string(char *string_ptr)
{
  char *tmp_ptr = (char *) malloc(sizeof(char) * LENGTH);
  check_debug(tmp_ptr, "NULL");

  for(int i = 0; i < strlen(tmp_ptr); ++i)
    {
      if(tmp_ptr[i] == '\n')
	{
	  tmp_ptr[i] = '\0';
	  break;
	}
    }

  log_info("tmp_ptr %s", tmp_ptr);
  strcpy(string_ptr, tmp_ptr);
  free(tmp_ptr);
      
  return true;
  
 error:
  free(tmp_ptr);
  return false;
}


bool read_char(char *char_ptr)
{
  check_debug(char_ptr, "NULL pointer");

  if(read_stdin(char_ptr, 1))
    {
      log_info("char_ptr %c", char_ptr[0]);
      return true; 
    }

 error:
  return false;
}


bool read_int(int *int_ptr)
{
  char *tmp_str = (char *) malloc(sizeof(char) * LENGTH);

  read_string(tmp_str);

  check_debug(tmp_str, "tmp_str == %p", tmp_str);
  
  for(int i = 0; i < strlen(tmp_str); ++i)
    {
      if(!isdigit(tmp_str[i]))
	{
	  log_err("tmp_str is not a numerig value");
	  return false;
	}
    }

  log_info("tmp_str %s", tmp_str);
  *int_ptr = atoi(tmp_str);

  return true;

 error:
  free(tmp_str);
  return false;
}


bool read_shelf(char *shelf_ptr)
{
  char *tmp_string = {'\0'};

  if(!read_string(tmp_string))
    {
      log_err("Unable to read string");
      return false;
    }

  if(!isalpha(tmp_string[0]))
    {
      log_err("Head of tmp_string is not alphabetic");
      return false;
    }

  for(int i = 1; i < strlen(tmp_string); ++i)
    {
      if(!isdigit(tmp_string[i]))
	{
	  log_err("Tail of tmp_string is not numeric");
	  return false;
	}
    }

  tmp_string[0] = toupper(tmp_string[0]);
  log_info("tmp_string %s", tmp_string);

  strcpy(shelf_ptr, tmp_string);
  return true;
}
