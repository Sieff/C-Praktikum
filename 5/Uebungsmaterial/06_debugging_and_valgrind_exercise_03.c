#include <stdio.h>
#include <stdlib.h>

// Koordinaten-Struct, keine Änderungen notwendig
typedef struct
{
	//Koordinaten
	int x,y;
} myCoordinate;

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
	//node * head = NULL;
	node * head = malloc(sizeof(node));
	//node * tail = NULL;
	node * tail = malloc(sizeof(node));

	head->next = tail;
	head->prev = tail;

	tail->next = head;
	tail->prev = head;
	
	return head;
}

// Der Speicher der Struct-Speicher-Datenstruktur sowie aller noch gespeicherten
// Koordinaten-Structs wird freigegeben
void freeStructStorage(node* ptr)
{
	ptr->next = NULL;
	ptr->prev = NULL;
	free(ptr);
}

//##############################################################################

// Füge ein neues Element am Ende des Struct-Speichers ein
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
void insertAt(node * ptr, int j, myCoordinate * coordinate)
{
	node * current = ptr;
	for(int k = 0; k<j; k++)
	{
		current = current->next;
		if(current->coordinate == NULL)
		{
			insert(ptr, coordinate);
		}
	}

	node * new = NULL;
	new = malloc(sizeof(node));

	new->coordinate = coordinate;
	new->next = current->next;
	new->prev = current;

	current->next = new;
	node * currentnext = current->next;
	currentnext->prev = new;
}

//#############################################################################
// Gib die Koordinaten des Elements an Position pos aus
void printAt(node * ptr, int position)
{
	node * current = ptr->next;
	for(int k = 0; k < position; k++)
	{
		current = current->next;
		if(current->coordinate == NULL)
		{
			return;
		}
	}
	printStruct(current->coordinate);
}

// Gib die Koordinaten der Elemente zwischen den Positionen pos1 und pos2 aus
void printRange(node * ptr, int pos1, int pos2)
{
	node * current = ptr->next;
	for(int k = 0; k < pos1; k++)
	{
		current = current->next;
		if(current->coordinate == NULL)
		{
			return;
		}
	}

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

// Lösche das Element an Position pos
void deleteAt(node * ptr, int position)
{
	node * current = ptr;
	for(int k = 0; k <= position; k++)
	{
		current = current->next;
		if(current->coordinate == NULL)
		{
			return;
		}
	}

	node * currentnext = current->next;
	current->next = currentnext->next;
	node * currentnextnext = currentnext->next;
	currentnextnext->prev = current;
}

// Lösche alle Elemente zwischen den Positionen pos1 und pos2
void deleteRange(node * ptr, int pos1, int pos2)
{
	node * startnode = ptr;
	for(int k = 0; k < pos1; k++)
	{
		startnode = startnode->next;
		if(startnode->coordinate == NULL)
		{
			return;
		}
	}

	node * endnode = ptr;
	for(int k = 0; k <= pos2+1; k++)
	{
		endnode = endnode->next;
		if(endnode->coordinate == NULL)
		{
			return;
		}
	}

	startnode->next = endnode;
	endnode->prev = startnode;
}

// Leere die gesamte Struct-Speicher-Datenstruktur
void deleteAll(node * ptr)
{
	node * tail = ptr->prev;
	tail->prev = tail->next;
	ptr->next = ptr->prev;

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
