#include <stdio.h>

#define KEY 5

int EnCaesar(char* str)
{
	int index = -1;

	if (str[0])
	{
		while (str[++index])
			if(str[index] - 32)
				str[index] += KEY;
		str[index] = '\0';
	}
	else
		return (-1);
	return (0);
}

int DeCaesar(char* str)
{
	int index = -1;

	if (str[0])
	{
		while (str[++index])
			if (str[index] - 32)
				str[index] -= KEY;
		str[index] = '\0';
	}
	else
		return (-1);
	return (0);
}

void calc(char* str)
{
	int counter[122] = { 0, };
	int index = -1;

	while (str[++index])
		if (str[index] - 32)
			counter[str[index]]++;

	index = -1;
	while (counter[++index])
		if (counter[index])
			printf("%d - %d\n", index, counter[index]);
}

int main(void)
{
	char str[] = "At vero eos et accusamus et iusto odio dignissimos ducimus qui blanditiis praesentium voluptatum deleniti atque corrupti quos dolores et quas molestias excepturi sint occaecati cupiditate non provident, similique sunt in culpa qui officia deserunt mollitia animi, id est laborum et dolorum fuga. Et harum quidem rerum facilis est et expedita distinctio. Nam libero tempore, cum soluta nobis est eligendi optio cumque nihil impedit quo minus id quod maxime placeat facere possimus, omnis voluptas assumenda est, omnis dolor repellendus. Temporibus autem quibusdam et aut officiis debitis aut rerum necessitatibus saepe eveniet ut et voluptates repudiandae sint et molestiae non recusandae. Itaque earum rerum hic tenetur a sapiente delectus, ut aut reiciendis voluptatibus maiores alias consequatur aut perferendis doloribus asperiores repellat.";

	printf("origin = %s\n\n", str);
	EnCaesar(str); // 암호화
	printf("encoding = %s\n\n", str);
	//calc(str);
	DeCaesar(str); // 복호화
	printf("decoding = %s\n\n", str);

	return (0);
}