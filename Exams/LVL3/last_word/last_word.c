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
	if (argc == 2)
	{
		int len = ft_strlen(argv[1]);

		int i = 0;
		int is_word_begin = 1, last_word = 0;

		while (argv[1][i])
		{
			if (is_word_begin && argv[1][i] != ' ' && argv[1][i] != '\t')
			{
				last_word = i;
			}

			is_word_begin = (argv[1][i] == ' ' || argv[1][i] == '\t') ? 1 : 0;
			i++;
		}

		while (last_word < len && argv[1][last_word] != ' ' && argv[1][last_word] != '\t')
			write(1, &argv[1][last_word++], 1);
	}	

	write(1, "\n", 1);
	return 0;
}
