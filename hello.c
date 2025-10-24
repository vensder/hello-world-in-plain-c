/* hello.c */
#include <stdio.h>
#include <string.h>

int hello(void)
{
  const char *msg = "Hello, World!\n";
  int printf_res = printf(msg);
  return (printf_res < 0) ? 1 : 0;
}
