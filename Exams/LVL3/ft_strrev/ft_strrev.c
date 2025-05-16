#include <stdio.h>
int ft_strlen(char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return len;
}

char    *ft_strrev(char *str)
{
	int len = ft_strlen(str);

	int i;
	char temp;
	for (i = 0; i < len / 2; i++)
	{
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}

	return str;
}
