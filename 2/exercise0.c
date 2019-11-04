#include<stdio.h>
void string_concat (char out[], char string1[], char string2[])
{
	int i = 0;
	int j = 0;
	
	while (string1[i] != '\0')
	{
		out[i] = string1[i];
		i++;
	}
	while (string2[j] != '\0')
	{
		out[i] = string2[j];
		j++;
		i++;
	}
	out[i] = '\0';
}

int main (void)
{
	char out[128] = {'\0'};
	string_concat(out, "djvn", "\0");
	printf("%s\n", out);
	return 0;
}
