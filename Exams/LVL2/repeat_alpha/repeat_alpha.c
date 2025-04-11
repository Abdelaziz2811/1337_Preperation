#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		int i = 0;
		while (argv[1][i] != '\0')
		{
			if ((argv[1][i] >= 'a' && argv[1][i] <= 'z')
			   || (argv[1][i] >= 'A' && argv[1][i] <= 'Z'))
			{
				char current;
				if (argv[1][i] >= 'A' && argv[1][i] <= 'Z') 
					current = argv[1][i] + 32;
				else
					current = argv[1][i];
				
				char c;
				for (c = 'a'; c <= current; c++)
				{
					write(1, &argv[1][i], 1);
				}
			}
			else write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}
