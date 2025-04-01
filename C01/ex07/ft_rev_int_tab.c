#include<stdio.h>

void ft_rev_int_tab(int *tab, int size)
{
	int temp;

	for (int i = 0; i < size / 2; i++)
	{
		temp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = temp;	
	}
}
