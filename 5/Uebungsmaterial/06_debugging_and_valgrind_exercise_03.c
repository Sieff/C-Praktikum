#include <stdio.h>
#include <stdlib.h>

// Koordinaten-Struct, keine Änderungen notwendig
typedef struct
{
	//Koordinaten
	int x,y;
} myCoordinate;

// Kettenglied für linkedlist.
// besteht aus Wert für Koordinate, nächstes und vorriges Kettenglied
typedef struct node
{
	myCoordinate * coordinate;
	struct node * next;
	struct node * prev;
}node;

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
node * createStructStorage()
{
	node * head = malloc(sizeof(node));
	node * tail = malloc(sizeof(node));

	// Kopf und Ende der linkedlist werden als Wächter initialisiert, zeigen aufeinander
	// Liste ist doppelt verkettet im Kreis
	head->coordinate = NULL;
	tail->coordinate = NULL;

	head->next = tail;
	head->prev = tail;

	tail->next = head;
	tail->prev = head;
	
	return head;
}


//##############################################################################


// Es wird über die Linkedlist bis zum Element an position iteriert und dieses zurückgegegeben
// Stoppt, wenn position Größer als die Länge der Liste,
// am Ende der Liste und gibt dann das letzte Element der Liste zurück
node * iterateTo(node * ptr, int position)
{
	node * current = ptr->next;
	for(int k = 0; k < position; k++)
	{
		current = current->next;
		if(current->coordinate == NULL)
		{
			current = current->prev;
			break;
		}
	}
	return current;
}


// Füge ein neues Element am Ende des Struct-Speichers ein
// Neues Glied wird zwischen Ende und Element vor dem Ende eingegliedert
void insert(node * ptr, myCoordinate * coordinate)
{

	node * tail =  ptr->prev;

	node * new = NULL;
	new = malloc(sizeof(node));

	new->coordinate = coordinate;
	new->next = tail;
	new->prev = tail->prev;

	node * tailprev = tail->prev;
	tailprev->next = new;
	tail->prev = new; 

}

// Füge ein neues Element an Position pos ein
// Falls Position größer als Länge der Liste wird Element hinten angefügt, 
// ansonsten wird ein neues Glied erstellt und die Elemente werden neu verkettet
void insertAt(node * ptr, int position, myCoordinate * coordinate)
{
	node * current = iterateTo(ptr, position);
	if(current->coordinate == NULL)
	{
		printf("%s\n", "if");
		insert(ptr, coordinate);
	}
	else
	{
		node * new = NULL;
		new = malloc(sizeof(node));

		new->coordinate = coordinate;
		new->next = current;
		new->prev = current->prev;

		node * currentPrev = current->prev;
		currentPrev->next = new;
		current->prev = new; 
	}
	
}

//#############################################################################
// Gib die Koordinaten des Elements an Position pos aus
void printAt(node * ptr, int position)
{
	node * current = iterateTo(ptr, position);
	printStruct(current->coordinate);
}

// Gib die Koordinaten der Elemente zwischen den Positionen pos1 und pos2 aus
// gibt auch die Elemente an den Grenzen aus
void printRange(node * ptr, int pos1, int pos2)
{
	node * current = iterateTo(ptr, pos1);

	for(int k = pos1; k <= pos2; k++)
	{
		printStruct(current->coordinate);
		current = current->next;
		if(current->coordinate == NULL)
		{
			return;
		}
	}

}

// Gib die Koordinaten aller Elemente aus
void printAll(node * ptr)
{
	node * current = ptr->next;
	while(current->coordinate != NULL)
	{
		printStruct(current->coordinate);
		current = current->next;
	}
	
}

//##############################################################################

// Lösche das Element an Position position
// Tut nichts, wenn an position kein Element steht
void deleteAt(node * ptr, int position)
{
	node * current = iterateTo(ptr, position);

	if(current->coordinate != NULL)
	{
		node * currentPrev = current->prev;
		currentPrev->next = current->next;
		node * currentNext = current->next;
		currentNext->prev = current->prev;


		free(current->coordinate);
		free(current);	
	}

	
}

// Lösche alle Elemente zwischen den Positionen pos1 und pos2
// löscht auch die Grenzelemente
void deleteRange(node * ptr, int pos1, int pos2)
{
	node * nodeInFrontOfRange = iterateTo(ptr, pos1)->prev;
	node * freeThis;

	node * nodeBehindRange = ptr->next;
	for(int i = 0; i < pos2 + 1; i++)
	{
		freeThis = nodeBehindRange;
		nodeBehindRange = nodeBehindRange->next;
		if(nodeBehindRange->coordinate == NULL)
		{
			break;
		}

		if(i >= pos1)
		{
			free(freeThis->coordinate);
			free(freeThis);
		}
	}

	nodeInFrontOfRange->next = nodeBehindRange;
	nodeBehindRange->prev = nodeInFrontOfRange;
}

// Leere die gesamte Struct-Speicher-Datenstruktur
// Wächter bleiben erhalten
void deleteAll(node * ptr)
{
	node * freeThis;
	node * current = ptr->next;
	while(current->coordinate != NULL)
	{
		freeThis = current;
		current = current->next;
		free(freeThis->coordinate);
		free(freeThis);
		
	}

	node * tail = ptr->prev;
	tail->prev = ptr;
	ptr->next = tail;

}

// Der Speicher der Struct-Speicher-Datenstruktur sowie aller noch gespeicherten
// Koordinaten-Structs wird freigegeben
// Löscht alle Kettenglieder und dann auch die Wächter
void freeStructStorage(node* ptr)
{
	deleteAll(ptr);

	node * tail = ptr->next;

	free(ptr->coordinate);
	free(tail->coordinate);

	free(tail);
	free(ptr);
}

//##############################################################################

// Gib die Anzahl enthaltener Elemente aus
void printSize(node * ptr)
{
	int numElements = 0;
	node * current = ptr->next;

	while(current->coordinate != NULL)
	{
		numElements++;
		current = current->next;
	}

	printf("Gesamtzahl Elemente: %d\n", numElements);
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

	node *storage = createStructStorage();
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


	node *storage = createStructStorage();

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

	node *storage = createStructStorage();

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
	printf("\n");
	deleteRange(storage,0,2);
	printRange(storage,0,4);
	printf("\n");

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
