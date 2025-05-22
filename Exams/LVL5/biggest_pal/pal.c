int is_palindrome(int starting_i, int ending_i, char *str)
{
	int pal_len = ending_i - starting_i;
	while (starting_i < ending_i)
	{
		if (str[starting_i] != str[ending_i])
			return 0;

		starting_i++;
		ending_i--;
	}
	return pal_len;
}


