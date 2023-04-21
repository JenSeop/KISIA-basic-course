#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

typedef uint32_t U32;
typedef FILE FE;

int	main (int ac, char *av[])
{
	if (ac != 2)
	{
		printf("CHECK FILE\n");
		return (1);
	}

	FE *f1 = foepn(f_name1, "rb");
	FE *f2 = fopen(f_name2, "rb");
	if (!f1 || !f2)
	{
		if (!f1)
			printf("OEPN ERROR - %s\n", f1);
		if (!f2)
			printf("OPEN ERROR - %s\n", f2);
		return (1);
	}

	U32 n1;
	U32 n2;
	fread(&n1, sizeof(n1), 1, f1);
	fread(&n2, sizeof(n2), 1, f2);
	
	n1 = ntohl(n1);
	n2 = ntohl(n2);

	fclose(f1);
	fclose(f2);

	U32 res = n1 + n2;

	printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", n1, n1, n2, n2, res, res);

	return (0);
}
