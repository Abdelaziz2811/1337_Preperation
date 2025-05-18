#include <unistd.h>
#include <stdlib.h>

int ft_atoi(char *str)
{
	int sign = 1;
	int i = 0;
	while (str[i] == '-' || str[i] == '+' || str[i] == ' ')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}

	int result = 0;

	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}

	return result * sign;
}

int is_prime(int number)
{
	int n = 2;
	while (n < number)
	{
		if (number % n == 0)
			return 0;
			n++;
	}
	return 1;
}

void ft_putnbr(int nbr)
{
	if (nbr >= 10)
		ft_putnbr(nbr / 10);

	char c = (nbr % 10) + '0';
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int number = ft_atoi(argv[1]);
		
		if (number < 0)
		{
			write(1, "0\n", 2);
			exit(1);
		}

		int i = 2;
		int prime_sum = 0;
		while (i <= number)
		{
			if (is_prime(i))
				prime_sum += i;
			i++;
		}

		ft_putnbr(prime_sum);
		write(1, "\n", 1);
		return 0;
	}
	write(1, "0\n", 2);
	exit(1);
}
