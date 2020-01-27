#ifndef MYNODES_H
	#define MYNODES_H
	
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
void printStruct(myCoordinate *input);


void getNodeAt(coordCollection *structStorage, int pos, coordNode **left, coordNode **right);

//##############################################################################
//##############################################################################
//##############################################################################

// Eine neue Struct-Speicher-Datenstruktur wird angelegt und ist nach Rückgabe
// betriebsbereit
coordCollection *createStructStorage();

// Der Speicher der Struct-Speicher-Datenstruktur sowie aller noch gespeicherten
// Koordinaten-Structs wird freigegeben
void freeStructStorage(coordCollection *structStorage);

//##############################################################################
// Füge ein neues Element an Position pos ein
void insertAt(coordCollection *structStorage, int pos, myCoordinate *input);

// Füge ein neues Element am Ende des Struct-Speichers ein
void insert(coordCollection *structStorage, myCoordinate *input);



//##############################################################################

// Gib die Koordinaten des Elements an Position pos aus
void printAt(coordCollection *structStorage, int pos);

// Gib die Koordinaten der Elemente zwischen den Positionen pos1 und pos2 aus
void printRange(coordCollection *structStorage, int pos1, int pos2);
// Gib die Koordinaten aller Elemente aus
void printAll(coordCollection *structStorage);

//##############################################################################

// Lösche das Element an Position pos
void deleteAt(coordCollection *structStorage, int pos);

// Lösche alle Elemente zwischen den Positionen pos1 und pos2
// Verbesserungspotential durch explizite Implementierung
void deleteRange(coordCollection *structStorage, int pos1, int pos2);

// Leere die gesamte Struct-Speicher-Datenstruktur
void deleteAll(coordCollection *structStorage);

//##############################################################################

// Gib die Anzahl enthaltener Elemente aus
void printSize(coordCollection *structStorage);



#endif