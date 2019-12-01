#include <assert.h>


/**
* Funktion teilt zwei ganze Zahlen ganzzahlig
* Gibt das Ergebnis zurück, belegt den Pointer mit dem Rest 
*/
int divide(int a, int b, int * rest) {
	*rest = a%b;
	return a/b;
}

int main() {
	int b = 53;
	int a = 7*b + 42;
	int rest = 0;
	int c = divide(a, b, &rest);
	assert(c == 7);
	assert(rest == 42);
}
