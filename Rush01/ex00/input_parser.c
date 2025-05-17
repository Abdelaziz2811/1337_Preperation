#include "ft_rush.h"
#include <stdlib.h>

int strs_size(char **strs)
{
	int len = 0;
	while (strs[len])
		len++;
	return len;
}

t_constraints *get_constraints(char *str, t_constraints *constraints)
{
	char **constraints_str = ft_split(str, " ");

	int size = strs_size(constraints_str);

	if (size == 16)
	{
		int i, j = 0, num;
		int *targets[4] = {
		constraints->col_up,	
		constraints->col_down,
		constraints->row_left,
		constraints->row_right };

		for (i = 0; i < size; i++)
		{
			num = ft_atoi(constraints_str[i]);
			if (num < 1 || num > 4)
				return NULL;

			targets[i / 4][j] = num;

			j++;

			if ((i + 1) % 4 == 0)
				j = 0;	
		}
		return constraints;
	}
	return NULL;
}
