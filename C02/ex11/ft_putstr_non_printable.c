void ft_putstr_non_printable(char *str)
{
	int i = 0;
	
	char *hex = "0123456789abcdef";
	char hex_parts[2];

	while (str[i] != '\0')
	{
		if (str[i] >= ' ' && str[i] <= '~')
			write(1, &str[i], 1);
		else 
		{
			write(1, "\\", 1);
			
			hex_parts[0] = hex[(unsigned char)str[i] / 16];
			hex_parts[1] = hex[(unsigned char)str[i] % 16];


			write(1, &hex_parts[0], 1);
			write(1, &hex_parts[1], 1);
		}
		i++;
	}
}
