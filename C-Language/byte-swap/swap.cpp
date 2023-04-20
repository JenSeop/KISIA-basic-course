#include <stdio.h>

void ft_swap(int* num_01, int* num_02)
{
	int temp = 0;

	temp = *num_01;
	*num_01 = *num_02;
	*num_02 = temp;
}

void ft_xor(int* num_01, int* num_02)
{
	*num_01 = *num_01 ^ *num_02;
	*num_02 = *num_01 ^ *num_02;
	*num_01 = *num_01 ^ *num_02;
}

int main(void)
{
	int a = 1;
	int b = 2;

	printf("bef | a = %d | b = %d\n",a,b);
	//ft_swap(&a, &b);
	ft_xor(&a, &b);
	printf("aft | a = %d | b = %d\n",a,b);

	return (0);
}