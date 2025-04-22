#include <stdio.h>

int is_char_in_base(char c, char *base)
{
	int i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return 1;
		i++;
	}
	return 0;
}

int get_digit_index(char digit, char *base)
{
	int i = 0;
	while (base[i])
	{
		if (digit == base[i])
			return i;
		i++;
	}
	return -1;
}

int ft_atoi_base(char *str, char *base)
{
	int base_len = 0;
	while (base[base_len] != '\0')
		base_len++;

	if (base_len < 2) return 0;

	int i = 0, j = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+' || base[i] <= 32 || base[i] == 127)
			return 0;

		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return 0;
			j++;
		}		
		i++;
	}

	int sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;

	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	
	int result = 0, index = 0;
	while (is_char_in_base(str[i], base))
	{
		index = get_digit_index(str[i], base);
		if (index == -1) break;
	
		result = result * base_len + index;
		i++;
	}

	return result * sign;
}

int main()
{
	         // → 42
	
	printf("%d\n", ft_atoi_base("101010", "01") );
	
	  // → 42
	
	printf("%d\n", ft_atoi_base("2a", "0123456789abcdef") );
	
	    // → 42

	printf("%d\n", ft_atoi_base("52", "01234567") );

	// -42
	//
	printf("%d\n", ft_atoi_base("-101010", "01") );

	   // → 42
	
	printf("%d\n", ft_atoi_base("   +2A", "0123456789ABCDEF") );

	return 0;
}
