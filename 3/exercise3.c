#include <stdio.h>
#include <stdlib.h>

/*
Zeiger auf den allokierten Speicher geht nach Funktionsende verloren,
jedoch bleibt Speicher reserviert, free() fehlt.
*/
void speicherleck()
{
	int *zeiger = malloc(sizeof(*zeiger));
}

/*
Reservierter Speicher für den Zeiger wurde bereits wieder freigegeben,
es kann sein, dass der Speicher bereits wieder belegt ist.
*/
void nutzungNachFree()
{
	int *zeiger = malloc(sizeof(int));
	free(zeiger);
	*zeiger = 42;
}

/*
Freigabe obwohl Speicher nicht dynamisch reserviert ist.
*/
void freigabeNichtReservierterSpeicher()
{
	int i = 0;
	free(i);
}

/*
Hilfsmethode
*/
int *zeigerAufArray()
{
	int array[10];
	return array;
}
/*
Es wird auf nicht reservierten Speicher zugegriffen.
*/
void zugriffNichtReservierterSpeicher()
{
	int *zeiger = zeigerAufArray();
	*(zeiger + 1) = 17;
	free(zeiger); 
}

/*
free() wird mehrfach aufgerufen, dies führt zu einem undefinierten Verhalten.
*/
void mehrfachFree()
{
	int *zeiger = (int *)malloc(5 * sizeof(int));
	free(zeiger);
	free(zeiger);
}


int main(void)
{
	speicherleck();
	nutzungNachFree();	
	freigabeNichtReservierterSpeicher();
	zugriffNichtReservierterSpeicher();
	mehrfachFree();
	return 0;
}
