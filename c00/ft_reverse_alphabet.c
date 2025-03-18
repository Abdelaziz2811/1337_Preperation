#include <unistd.h>

void ft_print_alphabet(void)
{	
	char c;
	for(int i = 122; i >= 97; i--)
	{
		c = i;
		write(1, %c, 1);
	}
}
