int         is_power_of_2(unsigned int n)
{
	if (n == 1)
		return 1;

	int num = 2;
	while(num <= n)
	{
		if (num == n)
			return 1;
		num *= 2;
	}
	return 0;
}
