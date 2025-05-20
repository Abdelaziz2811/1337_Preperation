#include <unistd.h>

int ft_atoi(char *str)
{
	int i = 0, result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return result;
}

void ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);

	char c = (n % 10) + '0';
	write(1, &c, 1);
}

int ft_mul(int a, int b)
{
	return a * b;
}

void print_mult_table(int n)
{
	int m = 1, result = 0;
	while (m < 10)
	{
		ft_putnbr(m);
		write(1, " x ", 3);
		ft_putnbr(n);
		write(1, " = ", 3);

		result = ft_mul(m, n);

		ft_putnbr(result);
		
		if (m != 9)
			write(1, "\n", 1);

		m++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int number = ft_atoi(argv[1]);
		print_mult_table(number);
	}
	write(1, "\n", 1);
	return 0;
}
