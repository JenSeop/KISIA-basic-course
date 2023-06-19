#include <stdio.h> // printf(), scanf_s()
#include <stdlib.h> // rand()

#define BAR_LEN 54
#define INF_LEN 5
#define CAL_LEN 5
#define RAND_S 21
#define RAND_E 55

// data structure
typedef struct Information {
	char name[20] = "";
	int quarter[4] = { 0, };
	int total = 0;
	int rank = 1;
} info;

int q_total_calc(Information* db, int data)
{
	int index = -1;
	int summary = 0;

	while(++index != INF_LEN)
		summary += db[index].quarter[data];

	return (summary);
}

int t_total_calc(Information* db)
{
	int index = -1;
	int summary = 0;

	while (++index != INF_LEN)
		summary += db[index].total;

	return (summary);
}

int input_rank(Information* db)
{
	int src = 0;
	int cmp = 0;

	while (src != INF_LEN)
	{
		cmp = 0;
		while (cmp != INF_LEN)
		{
			if (db[src].total < db[cmp].total)
				db[src].rank += 1;
			cmp++;
		}
		src++;
	}

	return (0);
}

int input_data(Information* db)
{
	int index = -1;

	while(++index != INF_LEN)
	{
		printf("[%d] : ", index + 1);
		scanf_s("%s", db[index].name, 20);
		for (int i = 0; i != 4; i++)
		{
			db[index].quarter[i] = (rand() % (RAND_E - RAND_S)) + RAND_S;
			db[index].total += db[index].quarter[i];
		}
	}

	return (0);
}

int array_data(Information* db)
{
	for (int i = 0; i != BAR_LEN; i++)
		printf("=");
	printf("\n");
	printf("성명\t1분기\t2분기\t3분기\t4분기\t합계\t순위\n");
	for (int i = 0; i != BAR_LEN; i++)
		printf("-");
	printf("\n");
	for(int i = 0; i != INF_LEN; i++)
		printf("%s\t　%d\t　%d\t　%d\t　%d\t　%d\t　%d\n", db[i].name, db[i].quarter[0], db[i].quarter[1], db[i].quarter[2], db[i].quarter[3], db[i].total, db[i].rank);
	for (int i = 0; i != BAR_LEN; i++)
		printf("-");
	printf("\n");
	printf("분기합\t");
	for(int i = 0; i != CAL_LEN - 1; i++)
		printf("　%d\t", q_total_calc(db, i));
	printf("　%d\n", t_total_calc(db));
	for (int i = 0; i != BAR_LEN; i++)
		printf("=");

	return (0);
}

int process()
{
	struct Information db[INF_LEN];

	input_data(db);
	input_rank(db);
	array_data(db);

	return (0);
}

int main(void)
{
	process();

	return(0);
}