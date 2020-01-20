#include <stddef.h>

#include "hash.h"

static void* table[1024] = { NULL };

static hash_remove_func remove_func = NULL;

void hash_init (hash_remove_func func)
{
	remove_func = func;
}

void hash_fini (void)
{
	for (unsigned int i = 0; i < 1024; i++)
	{
		hash_remove(i);
	}
}

int hash_insert (unsigned int key, void* value)
{
	key = key % 1024;

	if (table[key] == NULL)
	{
		table[key] = value;
		return 1;
	}
	else
	{
		return 0;
	}
}

int hash_remove (unsigned int key)
{
	key = key % 1024;

	if (table[key] != NULL)
	{
		if (remove_func != NULL)
		{
			remove_func(table[key]);
		}

		table[key] = NULL;

		return 1;
	}
	else
	{
		return 0;
	}
}
