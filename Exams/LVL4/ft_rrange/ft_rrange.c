#include <stdlib.h>

int size_count(int start, int end)
{
	int size = 0;
	int greater, smaller;
	greater = (start > end) ? start : end;
	smaller = (start < end) ? start : end;

	while (smaller <= greater)
	{
		smaller++;
		size++;
	}
	return size;
}

int    *ft_rrange(int start, int end)
{
	int size = size_count(start, end);

	int *tab = malloc(sizeof(int) * size);
	
	if (tab != NULL)
	{
		int i = 0;
		while (end != start || i < size)
		{
			tab[i] = end;

			if (end > start)
				end--;
			else if (end < start)
				end++;

			i++;
		}
	}
	return tab;
}
