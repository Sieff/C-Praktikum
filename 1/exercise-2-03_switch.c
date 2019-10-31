#include <stdio.h>      /* printf */
#include <stdlib.h>     /* atoi */

int main(int argc, char *argv[])
{
  int val = (argc > 1) ? atoi(argv[1]) : 0;

  // Erweitern Sie fuer die Zahlen 0-9, Bsp. für 0
switch (val) {
case 0: 
	printf("null");
	break;
case 1:
	printf("eins");
	break;
case 2:
	printf("zwei");
	break;
case 3:
	printf("drei");
	break;
case 4:
	printf("vier");
	break;
case 5:
	printf("fuenf");
	break;
case 6:
	printf("sechs");
	break;
case 7:
	printf("sieben");
	break;
case 8:
	printf("acht");
	break;
case 9:
	printf("neun");
	break;
}
}
