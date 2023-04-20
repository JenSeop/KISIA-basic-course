#include <stdio.h>

int main(void)
{
	int list[10] = { 7,8,9,5,2,3,10,5,4,2 };
	int max = list[0];
	int index = -1;

	while (index++ != 10)
		if (list[index] > max)
			max = list[index];

	printf("MAX = %d", max);

	return (0);
}