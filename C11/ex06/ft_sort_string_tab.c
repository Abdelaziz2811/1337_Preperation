int tab_len(char **tab)
{
	int i = 0;
	while (tab[i])
		i++;
	return i;
}

int ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i]) return s1[i] - s2[i];
		i++;
	}
	if (s1[i] != s2[i]) return s1[i] - s2[i];

	return 0;
}

void ft_sort_string_tab(char **tab)
{
	int len = tab_len(tab);

	if (len < 2)
		return;

	int i, j;
	char *temp_tab;
	for (i = 0; i < len; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (ft_strcmp(tab[i], tab[j]) > 0) 
			{
				temp_tab = tab[i];
				tab[i] = tab[j];
				tab[j] = temp_tab;
			}
		}
	}
}
