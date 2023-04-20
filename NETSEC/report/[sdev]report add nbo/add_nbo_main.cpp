#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    char *filename1 = argv[1];
    char *filename2 = argv[2];

    FILE *file1 = fopen(filename1, "rb");
    if (file1 == NULL) {
        printf("Cannot open file: %s\n", filename1);
        return 1;
    }

    FILE *file2 = fopen(filename2, "rb");
    if (file2 == NULL) {
        printf("Cannot open file: %s\n", filename2);
        return 1;
    }

    uint32_t num1, num2;
    fread(&num1, sizeof(num1), 1, file1);
    fread(&num2, sizeof(num2), 1, file2);

    num1 = ntohl(num1);
    num2 = ntohl(num2);

    fclose(file1);
    fclose(file2);

    uint32_t sum = num1 + num2;

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", num1, num1, num2, num2, sum, sum);

    return 0;
}
