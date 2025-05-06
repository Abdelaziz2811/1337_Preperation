void ft_foreach(int *tab, int length, void(*f)(int))
{
	int i;
	for (i = 0; i < length; i++)
	{
		f(tab[i]);
	}
}
