#include <stdio.h>
#include<stdlib.h>

struct Student {
	int id;
	char name[20];
	double score;
};

int main(void)
{
	struct Student* student = (Student*)malloc(sizeof(struct Student));

	if (student == NULL)
		printf("error");

	student->id = 10;
	printf("%d \n ", student->id);
	printf("%d - 이름을 입력해주세요 : ", student[0].id);
	scanf_s("%s", &(student->name), 20);

	printf("%d - 성적을 입력해주세요 : ", student[0].id);
	scanf_s("%lf", &(student->score));

	printf("id = %d | name = %s | score = %lf\n", student->id, student->name, student->score);

	free(student);
	student = NULL;

	return (0);
}