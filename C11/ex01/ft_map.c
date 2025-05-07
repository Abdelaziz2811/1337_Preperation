#include <stdlib.h>

int *ft_map(int *tab, int length, int(*f)(int))
{
	int *new_tab = malloc(sizeof(int) * length);
	if (new_tab != NULL)
	{
		for (int i = 0; i < length; i++)
		{
			new_tab[i] = f(tab[i]);
		}
	}
	return new_tab;
}
