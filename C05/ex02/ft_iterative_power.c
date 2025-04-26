int ft_iterative_power(int nb, int power)
{
	int result = 1;
	for (int i = 1; i <= power; i++)
	{
		result *= nb;
	}
	return result;
}
