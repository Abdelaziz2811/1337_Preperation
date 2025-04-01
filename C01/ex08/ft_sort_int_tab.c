#include<stdio.h>

void ft_sort_int_tab(int *tab, int size)
{
	int temp;
	int min_index;
	for (int i = 0; i < size; i++)
	{
		min_index = i;
		for (int j = i + 1; j < size; j++)
		{
			if (tab[j] < tab[min_index])
			{
				min_index = j;
			}
		}

		temp = tab[min_index];
		tab[min_index] = tab[i];
		tab[i] = temp;

	}
}
