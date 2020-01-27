#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"
#include "hash.h"

static int data_cmp_qsort_cb (void const* a, void const* b)
{
	data const* const* d1 = a;
	data const* const* d2 = b;

	return data_cmp(*d1, *d2);
}

int main (void)
{
	int ret = 0;
	data* array[128] = { NULL };

	/* Set up hash table. data_unref is called automatically for removed entries. */
	hash_init((hash_remove_func)data_unref);

	for (unsigned int i = 0; i < 128; i++)
	{
		char content[128];
		data* data;
		unsigned int hash;

		sprintf(content, "Hallo Welt #%u!", i);

		if (i % 2 == 0)
		{
			/* Save string in data object. */
			data = data_new_string(content);
		}
		else
		{
			/* Save blob in data object. Since strlen is used, null terminator is omitted. */
			data = data_new_blob(content, strlen(content));

			/* If data_new_blob is not implemented, fall back to data_new_string. */
			if (data == NULL)
			{
				data = data_new_string(content);
			}
		}

		hash = data_hash(data);

		/* Insertion will fail if a collision occurs. */
		if (!hash_insert(hash, data))
		{
			char* string;

			string = data_as_string(data);
			printf("Kollision! (%s)\n", string);
			free(string);
			data_unref(data);
			ret = 1;
			goto end;
		}

		/* Increase reference count and add to array. */
		array[i] = data_ref(data);
	}

	qsort(array, 128, sizeof(data*), data_cmp_qsort_cb);

	/* Print out array contents. */
	for (unsigned int i = 0; i < 128; i++)
	{
		char* string;

		string = data_as_string(array[i]);
		printf("Data #%u = %s\n", i, string);
		free(string);
	}

end:
	/* Remove array and hash table contents. */
	for (unsigned int i = 0; i < 128; i++)
	{
		if (array[i] != NULL)
		{
			data_unref(array[i]);
			array[i] = NULL;
		}
	}

	hash_fini();

	return ret;
}
