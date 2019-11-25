#include <stdio.h>
#include <stdlib.h>

// Koordinaten-Struct, keine Änderungen notwendig
typedef struct
{
	//Koordinaten
	int x,y;
} myCoordinate;

//Methode kann verwendet werden, um die Ausgabe in den print-Methoden zu realisieren
void printStruct(myCoordinate *input)
{
	printf("%d\t%d\n", input->x, input->y);
}

//##############################################################################
//##############################################################################
//##############################################################################

// Eine neue Struct-Speicher-Datenstruktur wird angelegt und ist nach Rückgabe
// betriebsbereit
myCoordinate *createStructStorage()
{
	myCoordinate * ptr = calloc(1, sizeof(myCoordinate));
	return ptr;
}

// Der Speicher der Struct-Speicher-Datenstruktur sowie aller noch gespeicherten
// Koordinaten-Structs wird freigegeben
void freeStructStorage(myCoordinate * ptr)
{
	free(ptr);
}

//##############################################################################

// Füge ein neues Element am Ende des Struct-Speichers ein
void insert(myCoordinate * ptr, myCoordinate * coordinate)
{
	int i = 0;
	int test = (int) *(ptr + i);
	while(test != 0)
	{
		i++;
		test = (int) *(ptr + i);
	}
 	if(ptr + i + 1 != 0)
 	{
 		ptr = realloc(ptr, i*2*(sizeof(myCoordinate)));
 	}
 	ptr[i+1] = *coordinate;
}

// Füge ein neues Element an Position pos ein
void insertAt(myCoordinate * ptr, int j, myCoordinate coordinate)
{
	int i = 0;
	while(*(ptr + i) != 0)
	{
		i++;
	}
 	if(ptr + i + 1 != 0)
 	{
 		ptr = realloc(ptr, i*2*(sizeof(myCoordinate)));
 	}
 	if(ptr + j != 0)
 	{
 		for(int k = i; k >= j; k--)
 		{
 			ptr[k+1] = ptr[k];
 		}
 	}
 	ptr[j] = coordinate;
}

//##############################################################################
/*
// Gib die Koordinaten des Elements an Position pos aus
TODO printAt(TODO)
{
	//TODO
}

// Gib die Koordinaten der Elemente zwischen den Positionen pos1 und pos2 aus
TODO printRange(TODO)
{
	//TODO
}
*/
// Gib die Koordinaten aller Elemente aus
void printAll(myCoordinate * ptr)
{
	int i = 0;
	while(ptr + i != 0)
	{
		printStruct(ptr + i);
	}
}
/*
//##############################################################################

// Lösche das Element an Position pos
TODO deleteAt(TODO)
{
	//TODO
}

// Lösche alle Elemente zwischen den Positionen pos1 und pos2
TODO deleteRange(TODO)
{
	//TODO
}

// Leere die gesamte Struct-Speicher-Datenstruktur
TODO deleteAll(TODO)
{
	//TODO
}

//##############################################################################

// Gib die Anzahl enthaltener Elemente aus
TODO printSize(TODO)
{
	int numElements;

	//TODO

	printf("Gesamtzahl Elemente: %d\n", numElements);
}
*/
//##############################################################################
//##############################################################################
//##############################################################################
// Nachfolgend ein paar Testmethoden, die bei der Korrektheitsprüfung helfen
// sollen. An den test-Methoden muss nichts geändert werden, Sie können sie aber
// natürlich bei Bedarf erweitern

// Einfacher Ausgabetest
void test1()
{
	printf("Test1:\n");
	myCoordinate *test = (myCoordinate*)malloc(sizeof(myCoordinate));
	test->x = 1;
	test->y = 10;

	myCoordinate *storage = createStructStorage();
	insert(storage, test);

	// Die beiden nachfolgenden Methoden sollten die gleiche Ausgabe produzieren
	printAll(storage);
	printStruct(test);

	freeStructStorage(storage);
}
/*
// Hinzufügen und löschen einzelner Elemente
void test2()
{
	printf("Test2:\n");

	myCoordinate **testArray = (myCoordinate **)malloc(3*sizeof(myCoordinate*));
	for (int i = 0; i < 3; ++i)
	{
		testArray[i] = (myCoordinate *)malloc(sizeof(myCoordinate));
		testArray[i]->x = i;
		testArray[i]->y = i*10;
	}


	myCoordinate *storage = createStructStorage();

	insert(storage, testArray[0]);
	insert(storage, testArray[1]);
	insertAt(storage,0,testArray[2]);

	printSize(storage);

	deleteAt(storage,1);

	printSize(storage);
	printAll(storage);

	freeStructStorage(storage);
}


// Hinzufügen und Löschen ganzer Bereiche
void test3()
{
	printf("Test3:\n");

	myCoordinate *storage = createStructStorage();

	myCoordinate **testArray = (myCoordinate **)malloc(10*sizeof(myCoordinate*));
	for (int i = 0; i < 10; ++i)
	{
		testArray[i] = (myCoordinate *)malloc(sizeof(myCoordinate));
		testArray[i]->x = i;
		testArray[i]->y = i*10;

		insert(storage,testArray[i]);
		printAt(storage,i);
	}
	printSize(storage);

	printRange(storage,0,4);
	deleteRange(storage,0,2);
	printRange(storage,0,4);

	printSize(storage);

	deleteAll(storage);

	printSize(storage);

	freeStructStorage(storage);
}
*/
//##############################################################################
//##############################################################################
//##############################################################################

int main()
{
	test1();
	printf("\n");
	//test2();
	printf("\n");
	//test3();
	return 0;
}
