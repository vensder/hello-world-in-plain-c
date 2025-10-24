/* goodbye.c */
#include <stdio.h>
#include <string.h>

int goodbye(void)
{
  const char *msg = "Goodbye, World!\n";
  int printf_res = printf(msg);
  return (printf_res < 0) ? 1 : 0;
}
