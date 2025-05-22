#include <unistd.h>
#include "bracket.h"

int ft_strlen(char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return len;
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		write(1, "\n", 1);
	}
	else
	{
		int i = 1, j = 0;

		while (argv[i])
		{
			int length = ft_strlen(argv[i]);
			char reading_parentheses[length];
			int k = -1;

			while (argv[i][j])
			{
				char c = argv[i][j];
				if (is_opening_bracket(c))
				{
					k++;
					char cb = closing_bracket_of(c);
					reading_parentheses[k] = cb;
				}

				if (is_closing_bracket(c))
				{
					if (reading_parentheses[k] == c)
					{
						reading_parentheses[k] = '\0';
						k--;
					}
				}

				j++;
			}

 			if (k == -1)
				write(1, "OK\n", 3);
			else 
				write(1, "Error\n", 6);
			
			i++;
		}
	}
	return 0;
}

