void ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int i = 0, j = 0;
	char *temp_tab;

	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (cmp(tab[i], tab[j]) > 0)
			{
				temp_tab = tab[i];
				tab[i] = tab[j];
				tab[j] = temp_tab;
			}
			j++;
		}
		i++;
	}
}
