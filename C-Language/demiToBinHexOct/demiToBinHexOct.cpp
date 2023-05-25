#include <stdio.h>

#define GREEN "\033[0;32m" // COLOR : GREEN
#define WHITE "\033[0;37m" // COLOR : WHITE
#define BIT 16

void printB(int num)
{
    int MAX = BIT; // BIT MAX 지정

    while (MAX--)
        printf("%d", (num >> MAX) & 1); // 연산 및 표출
    printf("\n");
}

int main()
{
    int num = 0;

    printf("INPUT => ");
    scanf_s("%d", &num); // 입력 값
    printf("NUM => %d",num);
    printf("\n");
    printf("\n%s* BINARY\n%s=> ", GREEN, WHITE);
    printB(num); // 2진수
    printf("\%s* OCTAL\n%s", GREEN, WHITE);
    printf("=> %o\n",num); // 8진수
    printf("\%s* HEXDECMIAL\n%s", GREEN, WHITE);
    printf("=> %x", num); // 16진수
    return (0);
}