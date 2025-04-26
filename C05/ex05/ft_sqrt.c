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
	return 0;
}
