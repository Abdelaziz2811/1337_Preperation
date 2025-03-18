#include <unistd.h>

void ft_print_comb2()
{
	char c1, c2, c3, c4;
	
	for (int i = 0; i <= 98; i++)
	{
		for (int j = i + 1; j <= 99; j++)
		{
			c1 = (i / 10) + '0';
			c2 = (i % 10) + '0';
			c3 = (j / 10) + '0';
			c4 = (j % 10) + '0';

			write(1, &c1, 1);
			write(1, &c2, 1);
			write(1, " ", 1);
			write(1, &c3, 1);
			write(1, &c4, 1);

			if (!(i == 98 && j == 99))
			{
				write(1, ", ", 2);
			}
		}
	}

}
int main() 
{
	ft_print_comb2();
	return 0;
}
