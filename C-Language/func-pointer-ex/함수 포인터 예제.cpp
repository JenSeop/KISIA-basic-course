#include <stdio.h>

int isAlpha(char c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (c);
}

int main(void)
{
	int (*func)(char);
	char str[] = "HelloWorld";
	int index = -1;

	func = isAlpha;

	while (str[++index])
		printf("%d ", func(str[index]));

	return (0);
}