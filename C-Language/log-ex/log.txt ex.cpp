#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	FILE* fp;
	char c;
	int flag = 0;
	int count = 0;

	fp = fopen("log.txt", "r");

	if (fp == NULL)
	{
		printf("Error: cannot open file.\n");
		return (1);
	}

	while ((c = fgetc(fp)) != EOF) {
		if (flag)
		{
			count++;
			flag = 0;
		}
		putchar(c);
		if (c == 'O')
			flag++;
	}
	printf("ERROR COUNT = %d", count);

	fclose(fp);

	return (0);
}