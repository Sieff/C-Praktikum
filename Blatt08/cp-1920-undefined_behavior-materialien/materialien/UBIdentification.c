#include <stdio.h>
#include <string.h>

double convertTemperature(double* fahrenheit) {
	double celsius = (*fahrenheit - 32)/1.8;
}

char* formatTemperature(double value, const char* unit) {
	char result[10];
	sprintf(result, "%f degree %s", value, unit); // Zweiter Parameter länger als 10 Zeichen abhängig von Eingaben
	return result;
}

int main() {
	void* buffer = (void*)malloc(33);
	strncpy(buffer, "enter a temperature in degree F: ", 33); // Kein Platz in buffer für Nullbyte
	printf("%s", buffer); // Nullbyte fehlt im buffer

	scanf("%f", buffer); // Wenn Eingabe länger als buffer, hervorgerufen durch fixed bufferlength
	double celsius = convertTemperature(buffer); // Es ist nicht definiert, was convertTemperature zurückgeben soll
	printf("the temperatures is %s\n", formatTemperature(celsius, "C")); // Lokale variable in formatTemperature zurückgegeben, ist hier out of scope
}
