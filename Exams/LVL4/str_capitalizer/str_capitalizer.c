#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		int i = 1, j = 0;
		char c;
		int is_first_letter = 1;

		while (argv[i])
		{
			j = 0;
			while (argv[i][j])
			{
				c = argv[i][j];
				
				if (c >= 'A' && c <= 'Z' && !is_first_letter)
					c += 32;
				
				if (c >= 'a' && c <= 'z' && is_first_letter)		
					c -= 32;

				write(1, &c, 1);

				is_first_letter = (c == ' ' || c == '\t') ? 1 : 0;

				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}
