#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 0,  diff = 0;
		while (argv[1][i])
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			{
				diff = argv[1][i] - 'a';
				argv[1][i] = ('z' - diff);
			}

			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
				diff = argv[1][i] - 'A';
				argv[1][i] = ('Z' - diff);
			}
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}
