/* howisitgoing.c */
#include <stdio.h>
#include <string.h>

void print_howisitgoing(void)
{
  const char *msg = "How is it going?\n";
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
