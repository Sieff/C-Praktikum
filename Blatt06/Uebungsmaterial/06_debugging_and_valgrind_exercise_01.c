#include <stdio.h>

int hoch2(int eingabe) //Kommentar
{
	return eingabe*eingabe;
}

char testfunktion00() //Kommentar
{
	char output = 'A';
	printf("Diese Funktion testet auch etwas\n");

	return output;
}

void testfunktion01(char eingabe)
{
	printf("Eingabe war %d\n", eingabe);
}


int main()
{
	int counter = 0; //Kommentar
	char beliebigesZeichen = 'J'; //Kommentar
	char charOut;

	for(;;) //Kommentar
	{
		counter++; //Kommentar
		hoch2(counter); //Kommentar
		charOut = testfunktion00();
		testfunktion01(charOut);
		if(counter%10 == 0) //Kommentar
		{
			break;
		}
	}
	testfunktion00(); //Kommentar

	printf("Das Programm konnte erfolgreich kompiliert werden!\n");
	return 0;
}


