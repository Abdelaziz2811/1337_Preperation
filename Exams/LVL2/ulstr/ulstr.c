#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 0;
		char c;
		while (argv[1][i])
		{
			c = argv[1][i];
			
			if (c >= 'a' && c <= 'z')
				c -= 32;
			else if (c >= 'A' && c <= 'Z')
				c += 32;

			write(1, &c, 1);
			i++;
		}
	}

	write(1, "\n", 1);
	return 0;
}
