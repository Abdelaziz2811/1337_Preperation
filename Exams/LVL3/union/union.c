#include <unistd.h>

int is_char_exists(char c, char *str)
{
	int i = 0;
	while (str[i])
	{
		if (c == str[i])
			return 1;
		i++;
	}
	return 0;
}

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
		int i = 0, j = 0, k = 0;
		int f_len = ft_strlen(argv[1]);
		int s_len = ft_strlen(argv[2]);
		char buffer[f_len + s_len];

		while (argv[1][i])
		{
			if (!is_char_exists(argv[1][i], buffer))
			{
				write(1, &argv[1][i], 1);
				buffer[k] = argv[1][i];
				k++;
			}
			i++;
		}


		while (argv[2][j])
		{
			if (!is_char_exists(argv[2][j], buffer))
			{
				write(1, &argv[2][j], 1);
				buffer[k] = argv[2][j];
				k++;
			}
			j++;
		}
	}
	write(1, "\n", 1);
	return 0;
}
