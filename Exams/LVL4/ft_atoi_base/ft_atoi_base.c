#include <stdio.h>

int is_char_in_base(char c, int base_len)
{
	char base[] = "0123456789abcdef";
	int i = 0;
	while (i < base_len)
	{
		if (c == base[i]) return 1;
		i++;
	}
	return 0;
}

int get_char_index(char c, int base_len)
{
	char base[] = "0123456789abcdef";
	int i = 0;
	while (i < base_len)
	{
		if (c == base[i]) return i;
		i++;
	}
	return -1;
}

int     ft_atoi_base(const char *str, int str_base)
{	
	int i = 0;
	while ( str[i] == ' ' || (str[i] >= 9 && str[i] <= 13) )
		i++;

	int sign = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}

	int result = 0;
	while (is_char_in_base(str[i], str_base))
	{
		int index = get_char_index(str[i], str_base);
		
		if (index == -1) break;

		result = (result * str_base) + index;
		i++;
	}
	return result * sign;
}
