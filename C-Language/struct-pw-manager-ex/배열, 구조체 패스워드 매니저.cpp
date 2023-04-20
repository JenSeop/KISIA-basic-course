#include <stdio.h>

struct user {
	char id[20];
	char pw[20];
};

int	ft_strcmp(char* s1, char* s2)
{
	int	len;

	len = 0;
	while (s1[len] || s2[len])
	{
		if (s1[len] > s2[len])
			return (s1[len] - s2[len]);
		else if (s1[len] < s2[len])
			return (s1[len] - s2[len]);
		len++;
	}
	return (0);
}

int program()
{
	int choice = 0;

	printf("\n| 1 | 유저 열람 | 2 | 유저 생성 | 3 | 로그인 | 4 | 종료\n");
	printf("명령 => ");
	scanf_s("%d", &choice);
	return (choice);
}

int user_view(user* temp, int temp_count)
{
	int index = -1;
	int i = -1;

	printf("\n* USER VIEW *\n");

	while (++index != temp_count)
	{
		printf("\nUSER - %d\n", index + 1);
		printf("ID : %s\n", &temp[index].id[index]);
		printf("PW : %s\n", &temp[index].pw[index]);
		printf("\n");
	}
	return (0);
}

int user_register(user* temp, int temp_count)
{
	char id[20];
	char pw[20];
	int id_index = 0;
	int pw_index = 0;

	if (temp_count >= 20)
	{
		printf("USER의 수가 20명 이상입니다.\n");
		return (-1);
	}
	printf("\n* REGISTER *\n");
	// ID
	while (1)
	{
		printf("ID : ");
		scanf_s("%s", &id, 20);
		while (id[id_index])
			id_index++;
		if (id_index < 5)
			printf("ID의 길이가 5자 이하, 다시 입력해주세요.\n");
		else if (id_index > 20)
			printf("ID의 길이가 20자 이상, 다시 입력해주세요\n");
		else
			break;
	}
	// PW
	while (1)
	{
		printf("PW : ");
		scanf_s("%s", &pw, 20);
		while (id[pw_index])
			pw_index++;
		if (pw_index < 5)
			printf("PW의 길이가 5자 이하, 다시 입력해주세요.\n");
		else if (pw_index > 20)
			printf("PW의 길이가 20자 이상, 다시 입력해주세요\n");
		else
			break;
	}
	// RETURN
	id_index = -1;
	pw_index = -1;
	while (id[++id_index])
		temp[temp_count].id[id_index] = id[id_index];
	temp[temp_count].id[id_index] = '\0';
	while (pw[++pw_index])
		temp[temp_count].pw[pw_index] = pw[pw_index];
	temp[temp_count].pw[pw_index] = '\0';
	printf("REGISTER SUCCES\n");
	// user count return
	return (temp_count + 1);
}

int user_login(user* temp, int temp_count)
{
	char id[20];
	char pw[20];
	int id_index = -1;
	int pw_index = -1;
	int flag = 0;

	printf("\n* LOGIN *\n");

	printf("ID : ");
	scanf_s("%s", &id, 20);
	printf("PW : ");
	scanf_s("%s", &pw, 20);

	while (++id_index != temp_count)
		if (!ft_strcmp(id, temp[id_index].id))
			flag++;
	while (++pw_index != temp_count)
		if (!ft_strcmp(pw, temp[pw_index].pw))
			flag++;
	if (flag == 2)
		printf("LOGIN SUCCES\n");
	else
		return (-1);
	return (0);
}

int main(void)
{
	user temp[20];
	int temp_count = 0;
	int flag = 0;
	int state = 0;

	while (1)
	{
		state = program();
		if (state == 1)
			flag = user_view(temp, temp_count);
		if (state == 2)
			temp_count = user_register(temp, temp_count);
		if (state == 3)
			flag = user_login(temp, temp_count);
		if (state == 4)
		{
			printf("프로그램을 종료합니다.\n");
			return (0);
		}
		if (flag == -1)
			printf("ERROR | 404\n");
		state = 0;
	}
}