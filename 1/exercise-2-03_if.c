#include <stdio.h>      /* printf */
#include <stdlib.h>     /* atoi */

int main(int argc, char *argv[])
{
  int val = (argc > 1) ? atoi(argv[1]) : 0;

  // Erweitern Sie fuer die Zahlen 0-9, Bsp. für 0
  if (val == 0)
  {
      printf("null");
  }
  if (val == 1)
  {
      printf("eins");
  }
  if (val == 2)
  {
      printf("zwei");
  }
  if (val == 3)
  {
      printf("drei");
  }
  if (val == 4)
  {
      printf("vier");
  }
  if (val == 5)
  {
      printf("fünf");
  }
  if (val == 6)
  {
      printf("sechs");
  }
  if (val == 7)
  {
      printf("sieben");
  }
  if (val == 8)
  {
      printf("acht");
  }
  if (val == 9)
  {
      printf("neun");
  }
}
