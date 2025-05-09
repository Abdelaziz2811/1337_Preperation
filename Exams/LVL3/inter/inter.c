#include <unistd.h>

int ft_strlen(char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return len;
}

int is_char_exists(char c, char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return 1;
		i++;
	}
	return 0;
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int i = 0, j = 0, k = 0;
		char c;
		int len = ft_strlen(argv[1]);
		char buffer[len];

		while (argv[1][i])
		{
			c = argv[1][i];
			j = 0;
			while (argv[2][j])
			{
				if (c == argv[2][j] && !is_char_exists(argv[2][j], buffer))
				{
					write(1, &argv[1][i], 1);
					buffer[k] = argv[1][i];
					k++;
					break;
				}
				j++;
			}			
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}
