#include <stdio.h>

int main(void)
{
	int square[3][3];

	square[0][0] = 1;
	square[0][1] = 2;
	square[0][2] = 3;
	square[1][0] = 4;
	square[1][1] = 5;
	square[1][2] = 6;
	square[2][0] = 7;
	square[2][1] = 8;
	square[2][2] = 9;
	int max = square[0][0];

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (square[i][j] > max)
				max = square[i][j];

	printf("MAX : %d", max);
	return (0);
}