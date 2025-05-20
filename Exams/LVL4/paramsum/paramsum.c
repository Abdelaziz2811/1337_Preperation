#include <unistd.h>

void ft_putnbr(int nbr)
{
	if (nbr >= 10)
		ft_putnbr(nbr / 10);

	char c = (nbr % 10) + '0';
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
	if (argc > 1)
		ft_putnbr(argc - 1);
	else
		write(1, "0\n", 2);

	return 0;
}
