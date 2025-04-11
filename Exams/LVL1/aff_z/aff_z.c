#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "z\n", 2);
	}
	else
	{
		int i = 0;
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] == 'z')
			{
				write(1, "z\n", 2);
				return 0;
			}
			i++;
		}
		write(1, "z\n", 2);
	}

	return 0;
}
