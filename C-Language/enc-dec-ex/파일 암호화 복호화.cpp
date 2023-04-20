#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	FILE* fp;
	int str[10] = {0, };
	int key[4] = {7, 8, 9, 5};

	fp = fopen("example.bin", "rb");

	if (fp == NULL)
	{
		printf("Error: cannot open file.\n");
		return (1);
	}
	for (int i = 0; i < 10; i++)
	{
		str[i] = fgetc(fp);
		printf("%02X", str[i]);
	}
	printf("\n");
	for (int i = 0; i < 10; i++)
	{
		str[i] = str[i] ^ key[i % 4];
		printf("%02X", str[i]);
	}
	printf("\n");
	for (int i = 0; i < 10; i++)
	{
		str[i] = str[i] ^ key[i % 4];
		printf("%02X", str[i]);
	}

	fclose(fp);

	return (0);
}