#include <stdio.h>

int mian(void)
{
	int height = 3;
	int width = 0;

	while (height != 0)
	{
		if (width != height)
		{
			printf("*");
			width++;
		}
		else
		{
			printf("\n");
			height--;
			width = 0;
		}
	}

	return (0);
}