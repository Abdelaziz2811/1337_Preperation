#include <unistd.h>
#include <stdio.h>
int ft_atoi(char *str)
{
	int i = 0, result = 0;
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return result;
}

void print_hex(int number)
{
	if (number == 0)
	{
		write(1, "0", 1);
		return;
	}

	char hex_system[16] = "0123456789abcdef";

	int i = 0;
	char hex[8]; // 8-bytes is enough for 32-bit number
	while (number != 0)
	{
		hex[i++] = hex_system[number % 16];
		number /= 16;
	}

	i--;
	while (i >= 0)
		write(1, &hex[i--], 1);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int number = ft_atoi(argv[1]);
		print_hex(number);
	}
	write(1, "\n", 1);
	return 0;
}
