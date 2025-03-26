#include <unistd.h>

void print_combn(int combn[], int n)
{
	char cm;
	for (int i = 0; i < n; i++)
	{
		cm = combn[i] + '0';
		write(1, &cm, 1);
	}
	if (combn[0] != 10 - n)
	{
		write(1, ", ", 2);
	}
}

void generate_combinations(int combn[], int n, int index, int current)
{
	if (index == n)
	{
		print_combn(combn, n);
		return;
	}

	for (int i = current + 1; i <= 9; i++)
	{
		combn[index] = i;
		generate_combinations(combn, n, index + 1, i);
	}
}

void ft_print_combn(int n)
{
	int combn[9];
	generate_combinations(combn, n, 0, -1);
}

int main()
{
	ft_print_combn(2);
	return 0;
}
