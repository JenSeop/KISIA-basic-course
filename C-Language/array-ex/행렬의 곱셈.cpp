#include <stdio.h>

int main(void)
{
	int index[2][2] = { {2,2}, {2,2} };
	int sol = 1;

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			sol *= index[i][j];

	printf("SOL : %d\n", sol);

	return (0);
}