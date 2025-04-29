int ft_strlen(char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return len;
}

int is_valid_base(char *base)
{
	if (ft_strlen(base) < 2) return 0;

	int i = 0, j;
	while (base[i])
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

	return 1;
}

int is_in_base(char c, char *base)
{
	int i = 0;
	while (base[i])
	{
		if (base[i] == c) return 1;
		i++;
	}
	return 0;
}

int get_char_index(char c, char *base)
{
	int i = 0;
	while (base[i])
	{
		if (base[i] == c) return i;
		i++;
	}
	return -1;
}

int ft_atoi_base(char *nbr, char *base_from)
{
	int i = 0;
	while (nbr[i] == ' ' || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;

	int sign = 1;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-') sign = -sign;
		i++;
	}

	int result = 0, index;
	int base_len = ft_strlen(base_from);
	while (is_in_base(nbr[i], base_from))
	{
		index = get_char_index(nbr[i], base_from);

		if (index == -1) break;

		result = result * base_len + index;
		i++;
	}

	return result * sign;
}

void set_num_base(unsigned int nbr, char *base, unsigned int base_len, char *num_base, int *index)
{
	if (nbr >= base_len)
		set_num_base(nbr / base_len, base, base_len, num_base, index);

	num_base[(*index)++] = base[nbr % base_len];
	num_base[*index] = '\0';
}

void ft_getnbr_base(int nbr, char *base, char *buffer)
{
	long n = nbr;
	int index = 0;
	
	if (nbr < 0)
	{
		n = -n;
		buffer[0] = '-';
		index = 1;
	}

	unsigned int base_len = ft_strlen(base);
	set_num_base((unsigned int)n, base, base_len, buffer, &index);
}
