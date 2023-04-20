#include <stdio.h>

int isPrime(int num)
{
	int index = 1;

	while(++index < num / 2)
		if(!(num % index))
			return (0);
	return (1);
}

int main(void)
{
	int num = 0;

	printf("is prime num : ");
	scanf_s("%d", &num);
	
	if (isPrime(num))
		printf("%d - 소수입니다.\n", num);
	else
		printf("%d - 소수가 아닙니다.\n", num);

	return (0);
}