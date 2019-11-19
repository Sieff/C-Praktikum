#include <stdio.h>


void textTriangle (char* string) {
	while(*string != 0)
	{
		puts(string);
		string = string+1;
	}
}


int main (int argc, char ** argv) {
	textTriangle("moinservusmoin");
	return 0;
}
