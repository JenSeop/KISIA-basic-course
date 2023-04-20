#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct DB {
	char date[10] = "";
	char time[8] = "";
	char id[5] = "";
	char pw[9] = "";
	char state[7] = "";
};

int ft_strlen(char* str)
{
	int len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

void getDate(char* str, DB* data, int space)
{
	int index = -1;

	if (ft_strlen(str) == 10)
		while (str[++index])
			data[space].date[index] = str[index];
}

void getTime(char* str, DB* data, int space)
{
	int index = -1;

	if (ft_strlen(str) == 8)
		while (str[++index])
			data[space].time[index] = str[index];
}

void getID(char* str, DB* data, int space)
{
	int index = -1;

	if (ft_strlen(str) == 5)
		while (str[++index])
			data[space].id[index] = str[index];
}

void getPW(char* str, DB* data, int space)
{
	int index = -1;

	if (ft_strlen(str) == 9)
		while (str[++index])
			data[space].pw[index] = str[index];
}

void getState(char* str, DB* data, int space)
{
	int index = -1;

	if (ft_strlen(str) == 7)
		while (str[++index])
			data[space].state[index] = str[index];
}

int main(void)
{
	FILE* fp;
	DB filtered_data[78];
	char data[4246] = "";
	char put_str[10] = "";
	int index = 0;
	int space = 0;
	int counter = -1;

	fp = fopen("log.txt", "r");

	if (fp == NULL)
	{
		printf("Error: cannot open file.\n");
		return (1);
	}

	while ((data[index] = fgetc(fp)) != EOF) {
		putchar(data[index]);
		index++;
	}

	index = -1;
	while (++index != 4246)
	{
		put_str[++counter] = data[index];
	}

	fclose(fp);

	return (0);
}