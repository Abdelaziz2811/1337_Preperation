#include <unistd.h>

int main()
{
	int i;
	for (i = 1; i <= 100; i++)
	{
		if (i % 3 == 0 && i % 5 == 0) 
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else 
		{
			char c = i;
			write(1, &c, 1);
		}
		write(1, "\n", 1);
	}

	return 0;
}
