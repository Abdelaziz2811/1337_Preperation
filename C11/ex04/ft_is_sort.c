int ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	if (length < 2)
		return 1;

	int i, f_elem_index = 0;
	int is_ascending = tab[0] < tab[1];

	for (i = 1; i < length; i++)
	{
		if (is_ascending)
			if (f(tab[f_elem_index++], tab[i]) > 0) return 0;
		else
			if (f(tab[f_elem_index++], tab[i]) < 0) return 0;
	}
	return 1;
}
