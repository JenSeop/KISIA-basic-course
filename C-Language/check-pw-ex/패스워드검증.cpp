#include <stdio.h>

int main(void)
{
	char pw[100] = "";
	int index = -1;
	int flag_01 = 0; // 대문자 판별
	int flag_02 = 0; // 소문자 판별
	int flag_03 = 0; // 특수문자 판별

	printf("INPUT : ");
	scanf_s("%s", pw, 20);
	printf("OUTPUT : %s\n", pw);

	while (pw[++index])
	{
		if (index > 20)
		{
			printf("ERROR : PW의 길이가 20글자 이상입니다.\n");
			return (-1);
		}
		if (pw[index] >= 65 && pw[index] <= 90) // 대문자 판별
			flag_01 = 1;
		if (pw[index] >= 97 && pw[index] <= 122) // 소문자 판별
			flag_02 = 1;
		if (!(pw[index] >= 65 && pw[index] <= 90) &&
			!(pw[index] >= 97 && pw[index] <= 122)) // 대문자 판별
			flag_03 = 1;
	}
	if (index < 4)
	{
		printf("ERROR : PW의 길이가 4글자 미만입니다.\n");
		return (-1);
	}
	if (!flag_01)
	{
		printf("ERROR : PW에 대문자가 포함되지 않았습니다.\n");
		return (-1);
	}
	if (!flag_02)
	{
		printf("ERROR : PW에 소문자가 포함되지 않았습니다.\n");
		return (-1);
	}
	if (!flag_03)
	{
		printf("ERROR : PW에 특수문자가 포함되지 않았습니다.\n");
		return (-1);
	}

	return (0);
}