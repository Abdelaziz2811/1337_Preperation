#include <stdlib.h>

int *ft_range(int min, int max)
{
	if (max <= min) return NULL;

	int *arr = malloc(sizeof(int) * (max - min));

	if (arr != NULL)
	{
		int i;
		for (i = 0; min < max; min++, i++)
		{
			arr[i] = min;
		}
	}

	return arr;
}
