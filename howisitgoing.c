/* howisitgoing.c */
#include <stdio.h>
#include <string.h>

int howisitgoing(void)
{
  const char *msg = "How is it going?\n";
  int printf_res = printf(msg);
  return (printf_res < 0) ? 1 : 0;
}
