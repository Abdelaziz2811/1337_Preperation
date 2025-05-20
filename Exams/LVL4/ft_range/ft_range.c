#include <stdio.h>
#include <stdlib.h>

int compute_size(int greater, int smaller)
{
	int size = 0;
	while (smaller <= greater)
	{
		smaller++;
		size++;
	}
	return size;
}

int 	*ft_range(int start, int end)
{
	int greater = (start > end) ? start : end;
	int smaller = (start < end) ? start : end;

	int size = compute_size(greater, smaller);

	int *tab = malloc(sizeof(int) * size);

	if (tab != NULL)
	{
		int i = 0;
		while (i < size)
		{
			tab[i] = start;

			if (start < end)
				start++;
			else if (start > end)
				start--;

			i++;
		}
	}
	return tab;
}
