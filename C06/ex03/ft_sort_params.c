#include <unistd.h>

int str_cmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return s1[i] - s2[i];
		i++;
	}

	if (s1[i] != s2[i])
		return s1[i] - s2[i];

	return 0;
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		// sorting
		int i = 1, j;
		while (i < argc)
		{
			j = i + 1;
			while (j < argc)
			{
				if (str_cmp(argv[i], argv[j]) > 0)
				{
					char *temp = argv[i];
					argv[i] = argv[j];
					argv[j] = temp;
				}
				j++;
			}
			i++;
		}
		
		// printing	
		i = 1;
		while (i < argc)
		{
			j = 0;
			while (argv[i][j])
			{
				write(1, &argv[i][j], 1);
				j++;
			}
			write(1, "\n", 1);
			i++;
		}

	}
		
	return 0;
}
