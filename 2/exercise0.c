#include<stdio.h>

/**
Hilfsmethode zur berechnung der Länge von Strings.
*/
int laengeVonString(char string[])
{
	//Initialisieren eines Zaehlers
	int i = 0;

	//Iteriert über den String und zaehlt solange der String nicht terminiert ist
	while (string[i] != '\0')
	{
		i++;
	}
	return i;
}

/**
Funktion konkateniert zwei Strings,
schreibt Ergebnis in out.
*/
void string_concat (char out[], char string1[], char string2[], int maxSize)
{
	//Prüft ob die beiden Strings zu lang sind
	if (laengeVonString(string1) + laengeVonString(string2) > maxSize)
	{
		printf("Laenge der Strings zu lang!");
	} 
	else 
	{
		//Indizes werden initialisiert
		int i = 0;
		int j = 0;
	
		//String1 wird in out gespeichert
		while (string1[i] != '\0')
		{
			out[i] = string1[i];
			i++;
		}

		//String2 wird hinter String1 in out gespeichert
		while (string2[j] != '\0')
		{
			out[i] = string2[j];
			j++;
			i++;
		}

		//out wird terminiert
		out[i] = '\0';
	}
}

int main (void)
{
	char out[128] = {'\0'};
	string_concat(out, "\0", "World", (sizeof(out) / sizeof(*out)));
	printf("%s\n", out);
	return 0;
}
