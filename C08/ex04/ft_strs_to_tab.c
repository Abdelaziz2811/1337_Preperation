#include <stdlib.h>
#include "ft_stock_str.h"

int ft_strlen(char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return len;
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	t_stock_str *tab = malloc(sizeof(t_stock_str) * (ac + 1));

	if (tab != NULL)
	{
		int i;
		for (i = 0; i < ac; i++)
		{
			tab[i].size = ft_strlen(av[i]);
			tab[i].str = av[i];
	
			tab[i].copy = malloc(sizeof(char) * (tab[i].size + 1));
	
			if (tab[i].copy != NULL)
			{
				int j = 0;
				while (j < tab[i].size)
				{
					tab[i].copy[j] = av[i][j];
					j++;
				}
				tab[i].copy[j] = '\0';
			}
		}
		tab[i].str = 0;
	}
	
	return tab;
}
