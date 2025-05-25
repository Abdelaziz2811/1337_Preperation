int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int is_operator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}
