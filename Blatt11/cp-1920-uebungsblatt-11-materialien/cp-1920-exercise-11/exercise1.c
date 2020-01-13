#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <assert.h>

struct array_element
{
	int age;
	char name[256];
};

struct array
{
	off_t size;
	off_t count;
	struct array_element element[];
};

void array_append(struct array* arr, int age, char* name)
{
	if ((sizeof(*arr) + sizeof(struct array_element) * (arr->count + 1)) > arr->size)
	{
		return;
	}

	arr->element[arr->count].age = age;
	strncpy(arr->element[arr->count].name, name, 256);
	arr->count++;
}

void array_init(struct array* arr, off_t size)
{
	//Größe und Anzahl der Elemente werden belegt
	arr->size = size;
	arr->count = 0;

	int nb;
	struct array_element buf; 

	//Myarray wird geöffnet um es später zu lesen und zu beschreiben
	int fd = open("myarray", O_RDWR | O_CREAT, 0600);

	//myarray wird gestatted
	struct stat st;
	int ret = stat("myarray", &st);
	assert(ret == 0);

	//Iterieren über myarray, startend nach 2* der Größe von off_t 
	//und in Schritten der Größe von einem array_element struct
	for(int i = 2 * sizeof(off_t); i < st.st_size; i = i + sizeof(struct array_element))
	{
		nb = pread(fd, &buf, sizeof(struct array_element), i);
		assert(nb == sizeof(struct array_element));

		//Falls der erste Char des Namen = 0 ist kann es sich um keinen Echten Namen handeln,
		//dementsprechend ist dies kein Element mehr was aufgenommen werden muss -> break
		//Ansonsten wird es appended
		if(buf.name[0] != 0)
		{
			array_append(arr, buf.age, buf.name);
		}
		else
		{
			break;
		}
	}
	
	//myarray wird geschlossen
	close(fd);
}

void array_reset(struct array* arr)
{
	arr->count = 0;
}

struct array_element* array_get(struct array* arr, off_t index)
{
	if (index >= arr->count)
	{
		return NULL;
	}

	return &arr->element[index];
}

void array_print(struct array* arr)
{
	for (off_t i = 0; i < arr->count; i++)
	{
		struct array_element* e = array_get(arr, i);
		printf("arr[%lu] = { %d, %s }\n", i, e->age, e->name);
	}
}

int main(void)
{
	//myarray wird geöffnet
	int fd;
	fd = open("myarray", O_RDWR | O_CREAT, 0600);

	//Das struct wird erstellt und gemapped
	struct array * arr = mmap(NULL, sizeof(struct array), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	array_init(arr, 1024);
	array_print(arr);	

	array_reset(arr);
	array_append(arr, 18, "Max Mustermann");
	array_append(arr, 21, "Moritz Mustermann");
	array_append(arr, 18, "Petra Mustermann");
	array_append(arr, 21, "Paula Mustermann");
	array_print(arr);

	array_reset(arr);
	array_append(arr, 21, "Paula Mustermann");
	array_print(arr);

	//Das Struct wird unmapped und myarray geschlossen
	munmap(arr, sizeof(struct array));
	close(fd);

	return 0;
}
