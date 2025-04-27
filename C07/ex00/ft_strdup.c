#include <stdlib.h>

char *ft_strdup(char *src)
{
	int length = 0;
	while (src[length])
		length++;

	char *copy = malloc(sizeof(char) * length + 1);

	if (copy != NULL)
	{
		int i = 0;
		while (i < length)
		{
			copy[i] = src[i];
			i++;
		}
		copy[i] = '\0';
	}
	
	return copy;
}
