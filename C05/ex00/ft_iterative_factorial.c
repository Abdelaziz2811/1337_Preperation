int ft_iterative_factorial(int nb)
{
	if (nb < 0) return 0;

	int result = 1;
	for (int i = 2; i <= nb; i++)
	{
		result *= i;
	}
	return result;
}
