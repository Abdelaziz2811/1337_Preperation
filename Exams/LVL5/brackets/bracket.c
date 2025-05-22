char o_brackets[] = "([{";
char c_brackets[] = ")]}";

int is_opening_bracket(char c)
{
	int i = 0;
	while (o_brackets[i])
	{
		if (c == o_brackets[i++])
			return 1;
	}
	return 0;
}

int is_closing_bracket(char c)
{
	int i = 0;
	while (c_brackets[i])
	{
		if (c == c_brackets[i++])
			return 1;
	}
	return 0;
}

int bracket_index(char c)
{
	int i = 0;
	while (o_brackets[i])
	{
		if (c == o_brackets[i])
			return i;
		i++;
	}
	return -1;
}

char closing_bracket_of(char c)
{
	int index = bracket_index(c);
	
	return c_brackets[index];
}
