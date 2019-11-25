#include <stdio.h>

/*
 *  Bestimme, ob 'eingabe' jeweils durch 2,3,4 oder 5 teilbar ist...Fokus liegt hierbei
 *  auf einer vollständigen Ausgabe
 *  Bsp: method01(6) -> Teilbar durch 2
 *  					Teilbar durch 3
 */
void method01(int eingabe)
{
	if(eingabe%4 == 0)
	{
		printf("Teilbar durch 4\n");
	}
	else if(eingabe%2 == 0)
	{
		printf("Teilbar durch 2\n");
	}
	else if(eingabe%3 == 0)
	{
		printf("Teilbar durch 3\n");
	}
	else if(eingabe%5 == 0)
	{
		printf("Teilbar durch 5\n");
	}
	else
	{
		printf("Eingabe ist nicht teilbar durch 2,3,4 oder 5\n");
	}
	printf("\n");
}

/*
 * Berechne x = (eingabe/2)*2
 * Die Rückgabe soll der Eingabe entsprechen
 * Bsp: method02(3) -> "Eingabe == Ausgabe: 3 == 3"
 */
void method02(int eingabe)
{
	int ausgabe;
	ausgabe = (eingabe/2)*2;

	printf("Eingabe == Ausgabe: %d == %d\n", eingabe, ausgabe);
}

/*
 * Berechne die Fakultät von 'eingabe', d.h. 1*2*3*...*'eingabe'
 * Bsp: method03(5) -> 120
 */
int method03(int eingabe)
{
	if(eingabe == 0)
	{
		return 1;
	}
	else if(eingabe > 0)
	{
		int rekEingabe = eingabe;
		return eingabe * method03(rekEingabe--);
	}
}

/*
 *Gibt die Ziffern der Eingabezahl in umgekehrter Reihenfolge aus
 * Bsp: method04(12340) -> 04321
 */
void method04(int eingabe)
{
	while(eingabe != 0)
	{
		int rest = eingabe %10;
		printf("%s", rest);
		eingabe = (eingabe-rest)/20;
	}
	printf("\n");
}


int main(int argc, char const *argv[])
{
	// Method 1
	printf("Method01:\n");
	for(int i = 1; i <= 10; i++)
	{
		method01(i);
	}

	// Method 2
	printf("Method02:\n");
	for(int i = 1; i <= 10; i++)
	{
		method02(i);
	}

	// Method 3
	printf("Method03:\n");
	for(int i = 0; i <= 10; i++)
	{
		printf("Fakultät von %d ist %d\n", i, method03(i));
	}

	// Method04
	printf("Method04:\n");
	method04(1234);
	method04(1);
	method04(10000);
}
