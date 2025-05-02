#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 0;
		char c;
		int spaces = 13;
		while (argv[1][i])
		{
			c = argv[1][i];
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			{
				int i;
				for (i = 1; i <= spaces; i++)
				{
					if (c == 'z') c = 'a';
					else if (c == 'Z') c = 'A';
					else c += 1;
				}
			}
			write(1, &c, 1);

			i++;			
		}
	}
	write(1, "\n", 1);

	return 0;
}
