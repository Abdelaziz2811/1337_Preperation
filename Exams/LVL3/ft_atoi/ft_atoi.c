int     ft_atoi(const char *str)
{
	int i = 0;
	int result = 0, sign = 1;
	while (str[i] == ' ' && str[i] >= 9 && str[i] <= 13)
		i++;

	while (str[i] == '+' && str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}

	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10 + (str[i] - '0');
		i++;
	}

	return result * sign;
}
