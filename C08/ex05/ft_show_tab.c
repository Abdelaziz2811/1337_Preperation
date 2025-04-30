#include <unistd.h>
#include "ft_stock_str.h"

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

void ft_putstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void ft_show_tab(struct s_stock_str *par)
{
	int i = 0;
	while (par[i].str != NULL)
	{
		ft_putstr(par[i].str);

		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		
		ft_putstr(par[i].copy);
		i++;
	}
}
