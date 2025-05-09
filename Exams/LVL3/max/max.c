int max(int* tab, unsigned int len)
{
	if (len != 0)
	{
		int i;
		int max = tab[0];
		for (i = 1; i < len; i++)
		{
			if (max < tab[i])
				max = tab[i];
		}
		return max;
	}
	return 0;
}

