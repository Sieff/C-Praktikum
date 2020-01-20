#include <stddef.h>

#include "data.h"

struct data
{
};

/* "content" is a null-terminated string. */
data* data_new_string (char const* content)
{
	return NULL;
}

/* "content" is a blob of length "length". */
data* data_new_blob (char const* content, unsigned int length)
{
	return NULL;
}

data* data_ref (data* data)
{
	return NULL;
}

/* Frees memory allocated by "data" if reference count reaches 0. */
void data_unref (data* data)
{
}

/* Returns a newly-allocated string that must be freed by the caller. */
char* data_as_string (data const* data)
{
	return NULL;
}

unsigned int data_hash (data const* data)
{
	return 0;
}

int data_cmp (data const* a, data const* b)
{
	return 0;
}
