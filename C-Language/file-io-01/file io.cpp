#include <stdio.h>

int main(void)
{
	FILE* fp;
	char str[] = "Hello KISIA";

	fp = fopen("file/txt", "w");

	if (fp == NULL)
	{
		printf("ERROR: cannot create file/\n");
		return (1);
	}

	fprintf(fp, "%s", str);

	fclose(fp);

	return (0);
}