#ifndef __dbg_h__
#define __dbg_h__

#include <stdio.h>
#include <errno.h>
#include <string.h>

#define INDENT "%-19s%-12s%-5d"

#ifdef NDEBUG
#define debug(M, ...)

#else
#define debug(M, ...)				\
  fprintf(stderr,				\
	  INDENT "%s\n",			\
	  "[DEBUG]",				\
	  __FILE__":",				\
	  __LINE__,				\
	  M,					\
	  ##__VA_ARGS__)
#endif
#define clean_errno()				\
  (errno == 0 ? "None" : strerror(errno))

#define log_err(M, ...)				\
  fprintf(stderr,				\
	  "[ERROR] (%s:%d: errno: %s) " M "\n",	\
	  __FILE__,				\
	  __LINE__,				\
	  clean_errno(),			\
	  ##__VA_ARGS__)

#define log_warn(M, ...)			\
  fprintf(stderr,				\
	  "[WARN] (%s:%d: errno: %s) " M "\n",	\
	  __FILE__,				\
	  __LINE__,				\
	  clean_errno(),			\
	  ##__VA_ARGS__)

#define log_info(func, varname, format, ...)	\
  fprintf(stderr,				\
	  INDENT "%-20s%-20s" format "\n",	\
	  "[INFO]",				\
	  __FILE__":",				\
	  __LINE__,				\
	  func, #varname, varname		\
	  ##__VA_ARGS__)

#define check(A, M, ...)			\
  if(!(A))					\
    {						\
      log_err(M, ##__VA_ARGS__);		\
      errno=0; goto error;			\
    }

#define sentinel(M, ...)			\
  {						\
    log_err(M, ##__VA_ARGS__);			\
    errno=0; goto error;			\
  }

#define check_mem(A)				\
  check((A), "Out of memory.")

#define check_debug(A, M, ...)			\
  if(!(A))					\
    {						\
      debug(M, ##__VA_ARGS__);			\
      errno=0; goto error;			\
    }

#endif
