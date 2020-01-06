#include <stdio.h>
#include <stdlib.h>

// Koordinaten-Struct, keine Änderungen notwendig
typedef struct
{
	//Koordinaten
	int x,y;
} myCoordinate;

typedef struct coordNode
{
	myCoordinate *koordinate;
	struct coordNode *left, *right;

} coordNode;

typedef struct
{
	int mySize;
	coordNode *first, *last;
}coordCollection;

//Methode kann verwendet werden, um die Ausgabe in den print-Methoden zu realisieren
void printStruct(myCoordinate *input)
{
	printf("%d\t%d\n", input->x, input->y);
}


void getNodeAt(coordCollection *structStorage, int pos, coordNode **left, coordNode **right)
{
	int offset = 0;
	*left = NULL;
	*right = NULL;

	// Position im rechten Bereich -> Rückwärtsiteration
	if(pos > structStorage->mySize/2)
	{
		*left = structStorage->last;
		while(pos < structStorage->mySize - offset)
		{
			offset++;
			*left = (*left)->left;
			*right = (*left)->right;
		}
	}
	// Position im linken Bereich -> Vorwärtsiteration
	else
	{
		*right = structStorage->first;
		while(offset < pos)
		{
			offset++;
			*right = (*right)->right;
			*left = (*right)->left;
		}
	}
}

//##############################################################################
//##############################################################################
//##############################################################################

// Eine neue Struct-Speicher-Datenstruktur wird angelegt und ist nach Rückgabe
// betriebsbereit
coordCollection *createStructStorage()
{
	coordCollection *structStorage = (coordCollection *)malloc(sizeof(coordCollection));
	structStorage->mySize = 0;
	structStorage->first = NULL;
	structStorage->last = NULL;

	return structStorage;
}

// Der Speicher der Struct-Speicher-Datenstruktur sowie aller noch gespeicherten
// Koordinaten-Structs wird freigegeben
void freeStructStorage(coordCollection *structStorage)
{
	coordNode *tmpNode = NULL;
	//über alle nodes iterieren
	for (coordNode* currentNode = structStorage->first; currentNode != NULL; currentNode = tmpNode)
	{
		tmpNode = currentNode->right;
		free(currentNode->koordinate);
		free(currentNode);
	}
	free(structStorage);
}

//##############################################################################
// Füge ein neues Element an Position pos ein
void insertAt(coordCollection *structStorage, int pos, myCoordinate *input)
{
	coordNode *left;
	coordNode *right;
	coordNode *newNode = (coordNode *)malloc(sizeof(coordNode));
	newNode->left = NULL;
	newNode->right =NULL;
	newNode->koordinate = input;

	getNodeAt(structStorage, pos, &left, &right);
	// Rechter Nachbar existiert
	if(right)
	{
		newNode->right = right;
		right->left = newNode;

	}
	// Linker Nachbar existiert
	if(left)
	{
		newNode->left = left;
		left->right = newNode;
	}

	// Randwertbetrachtung
	if(!right)
	{
		structStorage->last= newNode;
	}
	if(!left)
	{
		structStorage->first = newNode;
	}

	structStorage->mySize++;
}

// Füge ein neues Element am Ende des Struct-Speichers ein
void insert(coordCollection *structStorage, myCoordinate *input)
{
	insertAt(structStorage, structStorage->mySize, input);
}



//##############################################################################

// Gib die Koordinaten des Elements an Position pos aus
void printAt(coordCollection *structStorage, int pos)
{
	coordNode *left;
	coordNode *right;
	getNodeAt(structStorage, pos, &left, &right);
	if(right)
	{
		printStruct(right->koordinate);
	}

}

// Gib die Koordinaten der Elemente zwischen den Positionen pos1 und pos2 aus
void printRange(coordCollection *structStorage, int pos1, int pos2)
{
	for (int currentPos = pos1; currentPos < pos2; ++currentPos)
	{
		printAt(structStorage, currentPos);
	}
}

// Gib die Koordinaten aller Elemente aus
void printAll(coordCollection *structStorage)
{
	for (coordNode* currentNode = structStorage->first; currentNode != NULL; currentNode = currentNode->right)
	{
		printStruct(currentNode->koordinate);
	}
}

//##############################################################################

// Lösche das Element an Position pos
void deleteAt(coordCollection *structStorage, int pos)
{
	if(structStorage->mySize == 0)
	{
		return;
	}
	coordNode *left, *right;
	getNodeAt(structStorage, pos, &left, &right);


	// Normalfall: linker und recht-rechts-Nachbar
	if(left && right->right)
	{
		left->right=right->right;
		right->right->left = left;
	}
	// kein linker Nachbar
	if(!left && right->right)
	{
		structStorage->first = right->right;
		right->right->left=NULL;
	}
	// kein rechter Nachbar
	if(left && !right->right)
	{
		structStorage->last = left;
		left->right=NULL;
	}
	// Nur ein Eintrag
	if(!left && !right->right)
	{
		structStorage->first = NULL;
		structStorage->last = NULL;
	}

	// Speicherfreigabe
	free(right->koordinate);
	free(right);
	structStorage->mySize--;
}

// Lösche alle Elemente zwischen den Positionen pos1 und pos2
// Verbesserungspotential durch explizite Implementierung
void deleteRange(coordCollection *structStorage, int pos1, int pos2)
{
	for (int currentPos = pos1; currentPos < pos2; ++currentPos)
	{
		// pos1 statt curerentPos, da Einzellöschung Aufrückung bewirkt
		deleteAt(structStorage, pos1);
	}
}

// Leere die gesamte Struct-Speicher-Datenstruktur
void deleteAll(coordCollection *structStorage)
{
	deleteRange(structStorage,0,structStorage->mySize);
}

//##############################################################################

// Gib die Anzahl enthaltener Elemente aus
void printSize(coordCollection *structStorage)
{
	printf("Gesamtzahl Elemente: %d\n", structStorage->mySize);
}

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

	coordCollection *storage = createStructStorage();
	insert(storage, test);

	// Die beiden nachfolgenden Methoden sollten die gleiche Ausgabe produzieren
	printAll(storage);
	printStruct(test);

	freeStructStorage(storage);
}

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


	coordCollection *storage = createStructStorage();

	insert(storage, testArray[0]);
	insert(storage, testArray[1]);
	insertAt(storage,0,testArray[2]);

	printSize(storage);

	deleteAt(storage,1);

	printSize(storage);
	printAll(storage);

	freeStructStorage(storage);
	free(testArray);
}

// Hinzufügen und Löschen ganzer Bereiche
void test3()
{
	printf("Test3:\n");

	coordCollection *storage = createStructStorage();

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

	printf("\nPrint Range\n");
	printRange(storage,0,4);

	deleteRange(storage,0,2);
	printf("\nNach deleteRange:\n");
	printRange(storage,0,4);

	printSize(storage);

	deleteAll(storage);

	printSize(storage);

	freeStructStorage(storage);
	free(testArray);
}

//##############################################################################
//##############################################################################
//##############################################################################

int main()
{
	test1();
	printf("\n");
	test2();
	printf("\n");
	test3();
	return 0;
}
