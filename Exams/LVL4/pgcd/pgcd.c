#include <stdio.h>
#include <stdlib.h>

int find_gcd(int n1, int n2)
{
	while (n2 != 0)
	{
		int temp = n2;
		n2 = n1 % n2;
		n1 = temp;
	}
	return n1;
}

int main(int argc, char **argv)
{
	if (argc != 3)
		printf("\n");
	else
	{
		int n1 = atoi(argv[1]);
		int n2 = atoi(argv[2]);

		int gcd = find_gcd(n1, n2);

		printf("%d", gcd);
	}

	return 0;
}
