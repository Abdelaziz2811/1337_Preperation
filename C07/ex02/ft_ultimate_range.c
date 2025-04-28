#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max)
{
	if (max <= min) 
	{
		*range = NULL;
		return 0;
	}

	*range = malloc(sizeof(int) * (max - min));

	if (*range == NULL) return -1;

	int i = 0;

	for (i; min < max; min++, i++)
		(*range)[i] = min;

	return i;
}
