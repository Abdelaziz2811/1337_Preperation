#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc != 4)
		write(1, "\n", 1);
	else 
	{
		int rep_from_len = 0;
		while (argv[2][rep_from_len])
			rep_from_len++;

		int rep_to_len = 0;
		while (argv[3][rep_to_len])
			rep_to_len++;

		if (rep_from_len > 1 || rep_to_len > 1) 
		{
			write(1, "\n", 1);
			return 0;
		}

		int i = 0;
		while (argv[1][i])
		{
			if (argv[1][i] == argv[2][0])
				write(1, &argv[3][0], 1);

			else 
				write(1, &argv[1][i], 1);
			i++;
		}
		return write(1, "\n", 1);
	}
	return 0;
}
