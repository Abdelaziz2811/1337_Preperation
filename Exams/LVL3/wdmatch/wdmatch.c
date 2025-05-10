#include <unistd.h>

int ft_strlen(char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return len;
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int i = 0, j = 0;
		int len = ft_strlen(argv[1]);
		int is_str_valid = 0;

		while (argv[1][i])
		{
			while (argv[2][j])
			{
				if (argv[1][i] != argv[2][j])
					is_str_valid = 0;
				else 
				{	
					is_str_valid = 1;
					j++;
					break;
				}
				j++;
			}
			i++;
		}
		if (i == len && is_str_valid)
			write(1, argv[1], len);
	}
	write(1, "\n", 1);
	return 0;
}
