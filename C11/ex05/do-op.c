#include <unistd.h>

int ft_operator(char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return len;
}

int is_operator_valid(char *ops, char *operator)
{
	if (ft_operator(operator) > 1)		
		return -1;

	int i = 0;
	while (ops[i])
	{
		if (ops[i] == operator[0]) return i;
		i++;
	}
	return -1;
}

int ft_add(int n1, int n2)
{
	return n1 + n2;
}

int ft_sub(int n1, int n2)
{
	return n1 - n2;
}

int ft_mul(int n1, int n2)
{
	return n1 * n2;
}

int ft_div(int n1, int n2)
{
	return n1 / n2;
}

int ft_mod(int n1, int n2)
{
	return n1 % n2;
}

int ft_atoi(char *str)
{
	int i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;

	int sign = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-') sign = -sign;
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

void ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return;	
	}

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}

	if (nb >= 10)
		ft_putnbr(nb / 10);
	
	char c = (nb % 10) + '0';
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		char operators[5] = { '+', '-', '*', '/', '%' };
		int op_index;
		
		if ((op_index = is_operator_valid(operators, argv[2])) == -1)
		{
			write(1, "0", 1);
		}
		else
		{
			int (*operations[5])(int, int) = { &ft_add, &ft_sub, &ft_mul, &ft_div, &ft_mod };
			int n1 = 0, n2 = 0;
			int result = 0;

			n1 = ft_atoi(argv[1]);
			n2 = ft_atoi(argv[3]);
			
			if ((operators[op_index] == '/' || operators[op_index] == '%') && n2 == 0)
			{
				if (operators[op_index] == '/')
					write(1, "Stop : division by zero", 23);
				else
					write(1, "Stop : modulo by zero", 21);
			}
			else
			{	
				result = operations[op_index](n1, n2);	
				ft_putnbr(result);
			}
		}
	}

	return 0;
}
