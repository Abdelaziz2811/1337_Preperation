#include <stdlib.h>

int ft_strlen(char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return len;
}

char    *ft_strdup(char *src)
{
	int len = ft_strlen(src);
	char *new_str = malloc(sizeof(char) * (len + 1));

	if (new_str != NULL)
	{
		int i = 0;
		while (src[i])
		{
			new_str[i] = src[i];
			i++;
		}
		new_str[i] = '\0';
	}
	return new_str;
}
