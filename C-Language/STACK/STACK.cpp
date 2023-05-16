#include <stdio.h>
constexpr auto SIZE = 100;
int stack[SIZE] = { 0, };
int stackTop = -1;

int isFull()
{
	if (stackTop >= SIZE - 1)
		return (true);
	return (false);
}

int isEmpt()
{
	if (stackTop < NULL)
		return (true);
	return (false);
}

int push(int n)
{
	if (!isFull())
	{
		stack[++stackTop] = n;
		return (n);
	}
	return (false);
}

int pop()
{
	if (!isEmpt())
		return (stack[stackTop--]);
	return (false);
}

int main(void)
{
	for (int i = 0; i < SIZE; i++)
		printf("psuh(%d)\n", push(i));
	for (int i = SIZE; i > 0; i--)
		printf("pop(%d)\n", pop());

	return (0);
}