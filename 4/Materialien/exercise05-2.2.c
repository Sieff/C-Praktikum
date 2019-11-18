#include<assert.h>
#include<stddef.h>
#include<stdio.h>

int findCharPosition(char* string, char searchCharacter, char **out_pointer) {
	int position = 0;
	while(string[position] != '\0' && string[position] != searchCharacter)
	{
		position++;
	}
	if(string[position] == '\0')
	{
		position = -1;
	}
	else
	{
		*out_pointer = &string[position];
	}
	return position;
}

int main() {
	char* string1 = "foo";
	char* string2 = "bananas and ananas";

	int result = findCharPosition(string1, 'a', NULL);
	assert(result == -1);

	result = findCharPosition(string2, ' ', NULL);
	assert(result == 7);

	char* charPosition;
	result = findCharPosition(string2, 'd', &charPosition);
	assert(result == 10);
	assert(charPosition);
	assert(*charPosition == 'd');
	assert(charPosition == string2 + result);
	
	result = findCharPosition(string1, 'a', &charPosition);
	assert(result == -1);
	assert(!charPosition); 
}
