#include<stdio.h>

void ft_ultimate_div_mod(int *a, int *b)
{
	if (*b != 0)
	{
		int div, mod;

		div = *a / *b;
		mod = *a % *b;

		*a = div;
		*b = mod;
	}
}
