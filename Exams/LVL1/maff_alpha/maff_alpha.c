#include <unistd.h>

int main()
{
	char c;
	char possition = 1;	
	for (c = 'a'; c <= 'z'; c++, possition++)
	{
		if (possition % 2 == 0)
		{
			c -= 32;
			write(1, &c, 1);
			c += 32;
		}
		else write(1, &c, 1);
	}
	write(1, "\n", 1);

	return 0;
}
