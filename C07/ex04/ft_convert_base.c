#include <stdlib.h>
#include "ft_convert_base2.h"

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (!(is_valid_base(base_from) && is_valid_base(base_to)))
		return NULL;

	int num = ft_atoi_base(nbr, base_from);
	
	char nbr_base[34];
       	ft_getnbr_base(num, base_to, nbr_base);

	int size = ft_strlen(nbr_base);

	char *alloc_nbr_base = malloc(sizeof(char) * size + 1);

	if (alloc_nbr_base != NULL)
	{
		int i = 0;
		while (i < size)
		{
			alloc_nbr_base[i] = nbr_base[i];
			i++;
		}
		alloc_nbr_base[i] = '\0';

		return alloc_nbr_base;
	}
	
	return NULL;
}
