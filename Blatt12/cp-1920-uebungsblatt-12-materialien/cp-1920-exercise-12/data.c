#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "data.h"

// data Datenstruktur zur speicherung eines strings oder blobs
struct data
{
	// Das Objekt
	char* content;
	// Länge des Objekts
	int length;
	// Zähler für referenzen
	int refcount;
	// Ob das Objekt ein blob ist
	bool isBlob;
};

/* "content" is a null-terminated string. */
data* data_new_string (char const* content)
{
	// Speicher für das struct allokieren
	data * daten = malloc(sizeof(data));
	
	// Zählen der Länge des strings
	int length;
	for(length = 1; content[length] != '\0'; ++length);
	
	daten->length = length;

	// Allokieren des Speichers für den string
	daten->content = malloc(daten->length * sizeof(char));

	// Initialisierung der Felder im struct
	for(int i = 0; i < daten->length; i++)
	{
		daten->content[i] = content[i];
	}
	daten->refcount = 1;
	daten->isBlob = false;

	return daten;
}

/* "content" is a blob of length "length". */
data* data_new_blob (char const* content, unsigned int length)
{
	// Speicher für das struct allokieren
	data * daten = malloc(sizeof(data));

	// Allokieren des Speichers für das Objekt
	daten->content = malloc(length * sizeof(char));

	// Initialisierung der Felder im struct
	for(unsigned int i = 0; i < length; i++)
	{
		daten->content[i] = content[i];
	}
	daten->length = length;
	daten->refcount = 1;
	daten->isBlob = true;

	return daten;
}

// Erhöht den Zähler der Referenzen im struct
data* data_ref (data* data)
{
	data->refcount++;
	return data;
}

/* Frees memory allocated by "data" if reference count reaches 0. */
void data_unref (data* data)
{
	
	// Der referenzen Zähler wird um 1 verringert
	data->refcount--;

	// Wenn das struct nicht mehr referenziert wird, wird der allokierte Speicher freigegeben
	if(data->refcount == 0)
	{
		free(data->content);
		free(data);
	}
	
	
}

/* Returns a newly-allocated string that must be freed by the caller. */
char* data_as_string (data const* data)
{
	// String für die Rückgabe wird deklafiert
	char * string;
	
	// Wenn der content ein blob ist gibt es eine andere Behandlung als für einen String
	if(data->isBlob)
	{
		// Char array für die adresse deklariert
		char address[100];
		// address wird befüllt mit der Adresse des contents
		sprintf(address, "%p", data->content);
		// string wird initialisiert
		string = (char*)malloc((7 + strlen(address)) * sizeof(char));
		// string wird mit "Blob: " und der Adresse befüllt
		sprintf(string, "Blob: %s", address);
	}
	else
	{
		// string wird initialisiert
		string = malloc((9 + data->length) * sizeof(char));
		//String mit Inhalt füllen
		sprintf(string, "%s", "String: ");
		strncat(string, data->content, data->length);
	}

	return string;
}

// Berechnung eines Hashes für das Struct
unsigned int data_hash(data const * data) 
{ 
	// Startwert für den Hash wird festgelegt
	size_t hash = 420;

   	// Abhängig von dem content im struct wird ein Hashwert berechnet
	char string[data->length];

	for(int i = 0; i < data->length; i++)
	{
		string[i] = data->content[i];
	}
	for(int i = 0; i < data->length; i++)
	{
		hash = 33 * hash ^ (unsigned char) string[i];
	}

	return hash; 
} 

int data_cmp (data const* a, data const* b)
{	
	// Wenn a kürzer ist als b -> -1
	if(a->length < b->length)
	{
		return -1;
	}

	// Wenn b kürzer ist als a -> 1
	if(a->length > b->length)
	{
		return 1;
	}

	// Wenn beide gleich lang sind wird eintrag für eintrag verglichen
	for(int i = 0; i < a->length; i++)
	{
		if((int)a->content[i] > (int)b->content[i])
		{
			return 1;
		}

		if((int)a->content[i] < (int)b->content[i])
		{
			return -1;
		}
	}

	// Falls a und b genau gleich sind -> 0
	return 0;
}