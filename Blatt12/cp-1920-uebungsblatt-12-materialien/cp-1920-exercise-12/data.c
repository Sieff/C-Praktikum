#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "data.h"
int hash = 0;
struct data
{
	//String Blob Counter
	char* content;
	int length;
	//char[] blob;
	int refcount;
	bool isBlob;
};

/* "content" is a null-terminated string. */
data* data_new_string (char const* content)
{
	data * data = malloc(sizeof(data));
	
	for(data->length = 0; content[data->length] != '\0'; ++data->length);
	data->content = (char*)malloc(data->length*sizeof(char));
	for(int i = 0; i < data->length; i++)
	{
		data->content[i] = content[i];
	}
	data->refcount = 0;
	data->isBlob = false;
	return data;
}

/* "content" is a blob of length "length". */
data* data_new_blob (char const* content, unsigned int length)
{
	data * data = malloc(sizeof(data));
	data->content = (char*)malloc(length * sizeof(char));
	for(unsigned int i = 0; i < length; i++)
	{
		data->content[i] = content[i];
	}
	data->length = length;
	data->refcount = 0;
	data->isBlob = true;
	return data;
}

data* data_ref (data* data)
{
	data->refcount++;
	return data;
}

/* Frees memory allocated by "data" if reference count reaches 0. */
void data_unref (data* data)
{
	data->refcount--;
	if(data->refcount == 0)
	{
		free(data->content);
		free(data);
	}
}

/* Returns a newly-allocated string that must be freed by the caller. */
char* data_as_string (data const* data)
{
	char * string;
	
	if(data->isBlob)
	{
		char adress[100];
		sprintf(adress, "%p", data->content);
		string = (char*)malloc((7 + strlen(adress)) * sizeof(char));
		sprintf(string, "Blob: %s", adress);
	}
	else
	{
		string = (char*)malloc((9 + data->length) * sizeof(char));
		sprintf(string, "String: %s", data->content);
	}
	return string;
}

/*unsigned int data_hash(data const* data)
{
    unsigned int hash, i;
    for(hash = i = 0; i < (unsigned int)data->length; ++i)
    {
        hash += data->content[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

	printf("%u %s %p\n", hash % 1024, data->content, data->content);
    return hash;
} */

unsigned int data_hash(data const* data)
{
    return hash++;
}

int data_cmp (data const* a, data const* b)
{
	int length;
	int ret = 0;
	
	if(a->length < b->length)
	{
		ret = -1;
		length = a->length;
	}
	else if(a->length > b->length)
	{
		ret = 1;
		length = b->length;
	}

	for(int i = 0; i < length; i++)
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
	return ret;
}