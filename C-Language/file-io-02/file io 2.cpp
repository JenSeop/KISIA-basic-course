#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	FILE* fp;
	char c;

	fp = fopen("test.txt", "r");

	if (fp == NULL)
	{
		printf("Error: cannot open file.\n");
		return (1);
	}

	while ((c = fgetc(fp) != EOF))
	{
		if (c >= 65 && c <= 90)
			c -= 32;
		else if (c >= 97 && c <= 122)
			c += 32;
		else
			continue;
		putchar(c);
	}

	fclose(fp);

	return (0);
}