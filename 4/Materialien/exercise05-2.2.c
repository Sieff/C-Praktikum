#include <assert.h>

int findCharPosition(char* string, char searchCharacter, /*TODO*/ out_pointer) {
	/*TODO*/
}

int main() {
	char* string1 = "foo";
	char* string2 = "bananas and ananas";

	int result = findCharPosition(string1, 'a', NULL);
	assert(result == -1);

	result = findCharPosition(string2, ' ', NULL);
	assert(result == 7);

	char* charPosition;
	result = findCharPosition(string2, 'd', /*TODO*/);
	assert(result == 10);
	assert(charPosition);
	assert(*charPosition == 'd');
	assert(charPosition == string2 + result);

	result = findCharPosition(string1, 'a', /*TODO*/);
	assert(result == -1);
	assert(!charPosition);
}
