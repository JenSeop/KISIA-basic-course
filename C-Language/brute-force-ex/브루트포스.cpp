#include <stdio.h>

char pw[20] = "";

int main(void)
{
	int index = -1;
	int length = 0;
	int key = 96;
	char sol[5] = "";
	int sol_index = -1;

	printf("INPUT PW : ");
	scanf_s("%s", pw, 20);
	printf("OUTPUT PW : %s\n",pw);

	while (pw[++index])
	{
		if (!(pw[index] >= 97 && pw[index] <= 122))
		{
			printf("소문자가 발견되었습니다.\n");
			return (-1);
		}
		if (index > 4)
		{
			printf("PW가 4글자를 초과했습니다.\n");
			return (-1);
		}
		while (1)
			if(pw[index] == ++key)
			{
				sol[++sol_index] = key;
				key = 96;
				break;
			}
	}
	if (index < 4)
	{
		printf("PW가 4글자보다 적습니다.\n");
		return (-1);
	}
	printf("USER PW : %s\nLOGIN SUCCES\n", pw);

	return (0);
}