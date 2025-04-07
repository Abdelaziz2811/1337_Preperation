char *ft_strcapitalize(char *str)
{
	int i = 0;
	int is_first_character = 1;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
		&& is_first_character == 1)
		{
			str[i] -= 32;
		}

		if (!(str[i] >= 'a' && str[i] <= 'z')
		&& !(str[i] >= 'A' && str[i] <= 'Z')
		&& !(str[i] >= '0' && str[i] <= '9'))
		{
			is_first_character = 1;
		}
		else is_first_character = 0; 

		i++;
	}
	return str;
}
