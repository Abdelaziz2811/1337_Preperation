#include <stdlib.h>

int ft_strlen(char *str)
{
	int len = 0;
	
	while (str[len] != '\0')
		len++;

	return len;
}

char *ft_strcat(char *dest, char *src)
{
	int i = 0;
	while (dest[i] != '\0')
		i++;
	
	int j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';

	return dest;
}

char *ft_strjoin(int size, char **strs, char *sep)
{
	char *str;

	if (size == 0)
	{
		str = malloc(1);
		str[0] = '\0';

		return str;
	}

	int sep_len = ft_strlen(sep);

	int i, j, str_length = 0;
	for (i = 0; i < size; i++)
	{
		j = 0;
		while (strs[i][j])
		{
			str_length++;
			j++;
		}

		if (i < size - 1)
			str_length += sep_len;
	}

	str = malloc(sizeof(char) * (str_length + 1));
	
	if (str == NULL) return NULL;

	str[0] = '\0';
	for (i = 0; i < size; i++)
	{
		ft_strcat(str, strs[i]);		
		if (i < size - 1)
		{
			ft_strcat(str, sep);
		}
	}

	return str;
}
