/* hello.c */
#include <stdio.h>
#include <string.h>

int hello(void)
{
  const char *msg = "Hello, World!\n";
  int printf_res = printf(msg);

  if (printf_res < strlen(msg))

  {
    return 1;
  }
  else
  {
    return 0;
  }
}
