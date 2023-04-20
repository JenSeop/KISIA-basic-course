#include <stdio.h>

char *my_strcpy(char* dest, char* source)
{
	int length;

	length = -1;
	while (source[++length])
		dest[length] = source[length];
	dest[length] = '\0';

	return (dest);
}

int main(void)
{
	char a[20] = "Hello Wrld";
	char b[20];

	printf("func = %s\n",my_strcpy(b, a));
	printf("a = %s\n", a);
	printf("b = %s\n", b);
}