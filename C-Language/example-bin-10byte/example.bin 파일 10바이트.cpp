#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	FILE* fp;
	int c;

	fp = fopen("example.bin", "rb");

	if (fp == NULL)
	{
		printf("Error: cannot open file.\n");
		return (1);
	}

	for (int i = 0; i< 10; i++)
	{
		c = fgetc(fp);
		printf("%02X ", c);
	}

	fclose(fp);

	return (0);
}