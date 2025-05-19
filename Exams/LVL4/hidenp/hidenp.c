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
	if (argc != 3)
	{
		write(1, "\n", 1);
		return 0;
	}
	else
	{
		int i = 0, j = 0;
		while (argv[1][i] && argv[2][j])
		{
			if (argv[1][i] == argv[2][j])
				i++;
			j++;
		}

		int hidden_str_len = ft_strlen(argv[1]);
		if (i == hidden_str_len)
			write(1, "1\n", 2);
		else 
			write(1, "0\n", 2);
	}

	return 0;
}
