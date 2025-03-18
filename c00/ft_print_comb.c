#include <unistd.h>

void ft_print_comb(void)
{
	char c1, c2, c3;
	for (int i = 48; i <= 55; i++)
	{
		for (int j = i + 1; j <= 56; j++)
        	{
			for (int k = j + 1; k <= 57; k++)
        		{			
				c1 = i;
				c2 = j;
				c3 = k;

				write(1, &c1, 1);
				write(1, &c2, 1);
				write(1, &c3, 1);
					
				if (!(i == 55 && j == 56 && k == 57))
				{
				 	write(1, ", ", 2);
				}
			}
        	}
	}
}
