#include <unistd.h>

void print_number_in_base(unsigned int nbr, char *base, unsigned int base_len)
{
	if (nbr >= base_len)
		print_number_in_base(nbr / base_len, base, base_len);

	write(1, &base[nbr % base_len], 1);
}

void ft_putnbr_base(int nbr, char *base)
{
	unsigned int base_len = 0;
	while (base[base_len] != '\0')
		base_len++;

	if (base_len < 2) return;

	int i = 0,j = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+' || base[i] <= 32 || base[i] == 127)
			return;

		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return;
			j++;
		}
		i++;
	}

	long n = nbr;
	if (nbr < 0)
	{
		write(1, "-", 1);
		n = -n;
	}

	print_number_in_base((unsigned int)n, base, base_len);	
}
