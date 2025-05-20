#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	else
	{
		int i = 1, j = 0;
		char c, next_char;
		while (argv[i])
		{
			j = 0;
			while (argv[i][j])
			{
				c = argv[i][j];

				if (argv[i][j + 1])
					next_char = argv[i][j + 1];
				else 
				{
					if (c >= 'a' && c <= 'z')
					{
						c -= 32;
						write(1, &c, 1);
					}
					else 
						write(1, &c, 1);
	
					break;
				}
				
				if (next_char == ' ' || next_char == '\t')
				{
					if (c >= 'a' && c <= 'z')
					{
						c -= 32;
						write(1, &c, 1);
					}
					else write(1, &c, 1);

					write(1, &next_char, 1);
					j++;
				}
				else
				{
					if (c >= 'A' && c <= 'Z')
						c += 32;

					write(1, &c, 1);
				}

				j++;
			}
			write(1, "\n", 1);
			i++;
		}
	}
	return 0;
}
