#include <stdio.h>
#include <stdlib.h>

void getInfo(int* iptr)
{
	printf("Wert:  %d\n", *iptr );

	printf("Zeiger-Adresse:  %p\n", iptr );
}

int main()
{
	int i = 1234; //Variable über Stack initialisieren
	int* foo = &i; //Adresse von i in Pointer foo speichern
	getInfo(foo); //Info holen
	printf("Zeiger-Adresse foo:  %p\n", foo );


	int * ptr = malloc(sizeof(int)); //Speicher reservieren
	* ptr = 123; //Speicher belegen
	getInfo(ptr); //Info holen
	printf("Zeiger-Adresse ptr:  %p\n", ptr );
	free(ptr);	//Speicher freigeben

	//pointer werden kopiert, deshalb adresse jeweils gleich
	return 0;
}
