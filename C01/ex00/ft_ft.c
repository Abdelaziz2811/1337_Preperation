#include<unistd.h>
#include<stdio.h>
void ft_ft(int *nbr)
{
	*nbr = 42;
}

int main()
{
	int num = 67;
	ft_ft(&num);
	printf("%d", num);

	return 0;
}
