#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <netinet/in.h>

uint32_t read_data(char *filename);
uint32_t add_data(uint32_t data1, uint32_t data2);
void print_result(uint32_t data1, uint32_t data2, uint32_t result);

int main(int argc, char *argv[]) {
    //consider exception
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        exit(1);
    }

    uint32_t data1 = read_data(argv[1]);    //read filename1
    uint32_t data2 = read_data(argv[2]);    //read filename2
    uint32_t result = add_data(data1, data2);	//add data
    print_result(data1, data2, result);

    return 0;
}

//def read file data
uint32_t read_data(char *filename) {
    FILE *fp;
    uint32_t data;
    
    fp = fopen(filename, "rb");     //read byte
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    if (fread(&data, sizeof(uint32_t), 1, fp) != 1) {
        fprintf(stderr, "Error reading file %s\n", filename);
        exit(1);
    }

    fclose(fp);

    return ntohl(data);
}	


uint32_t add_data(uint32_t data1, uint32_t data2) {
    return data1 + data2;
}

void print_result(uint32_t data1, uint32_t data2, uint32_t result) {
    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", data1, data1, data2, data2, result, result);
}

