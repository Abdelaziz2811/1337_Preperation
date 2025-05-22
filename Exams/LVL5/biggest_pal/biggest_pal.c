#include <unistd.h>
#include "pal.h"

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
		int arg_len = ft_strlen(argv[1]);
		
		int j = 0, k = 0;
		int pal_len = 0, biggest_pal_len = 0;
		
		int biggest_pal_starting_i = 0;
		int biggest_pal_ending_i = 0;

		while (argv[1][j])
		{
			char c = argv[1][j];
			k = arg_len;
			while (k > j)
			{
				if (c == argv[1][k])
				{
					if ((pal_len = is_palindrome(j, k, argv[1])) > biggest_pal_len)
					{
						biggest_pal_len = pal_len;
			
						biggest_pal_starting_i = j;
						biggest_pal_ending_i = k;
						break;
					}
				}
				k--;
			}
			if (biggest_pal_len > arg_len)
				break;
			j++;
		}

		if (is_palindrome(biggest_pal_starting_i , biggest_pal_ending_i, argv[1]) > 0)
		{
			j = biggest_pal_starting_i;
			while (j <= biggest_pal_ending_i)
			{
				write(1, &argv[1][j], 1);
				j++;
			}
		}
	}
	write(1, "\n", 1);
	return 0;
}
