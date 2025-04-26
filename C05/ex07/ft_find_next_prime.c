int ft_sqrt(int nb)
{
	if (nb < 0) return 0;
	if (nb == 0 || nb == 1) return nb;

	int i = 2;
	while (i * i <= nb)
	{
		if (i * i == nb) return i;
		i++;
	}
	return i - 1;
}

int ft_is_prime(int nb)
{
	if (nb <= 1 ) return 0;
	int i, nb_sqrt = ft_sqrt(nb);
	for (i = 2; i <= nb_sqrt; i++)
	{
		if (nb % i == 0) return 0;
	}
	return 1;
}

int ft_find_next_prime(int nb)
{
	while (ft_is_prime(nb) == 0)
		nb++;
	return nb;
}
