#include <unistd.h>

void    print_bits(unsigned char octet)
{
	int i;
	char bit;
	for (i = 7; i >= 0; i--)
	{
		bit = ((octet >> i) & 1) + '0';
		write(1, &bit, 1);
	}
}
