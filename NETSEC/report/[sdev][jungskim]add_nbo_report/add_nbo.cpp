#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <netinet/in.h>

typedef uint32_t U32;
typedef FILE FE;

U32	rd_data (char *f_name);
U32	ad_data (U32 d1, U32 d2);
void	print_res (U32 d1, U32 d2, U32 res);

int	main (int ac, char *av[])
{
	if (ac != 3)
	{
		fprintf(stderr, "FILE ERROR, PLZ CHECK FILE\n");
		exit(1);
	}

	U32 d1 = rd_data(av[1]);
	U32 d2 = rd_data(av[2]);
	U32 res = ad_data(d1, d2);
	print_res(d1, d2, res);

	return (0);
}

U32 rd_data (char *f_name)
{
	FE *fp;
	U32 d;

	fp = fopen(f_name, "rb");
	if (!fp)
	{
		fprintf(stderr, "OPEN ERROR - %s\n", f_name);
		exit(1);
	}
	if (fread(&d, sizeof(U32), 1, fp) != 1)
	{
		fprintf(stderr, "READ ERROR - %s\n", f_name);
		exit(1);
	}
	fclose(fp);

	return (ntohl(d));
}

U32 ad_data (U32 d1, U32 d2)
{
	return (d1 + d2);
}

void print_res (U32 d1, U32 d2, U32 res)
{
	printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", d1, d1, d2, d2, res, res);
}
