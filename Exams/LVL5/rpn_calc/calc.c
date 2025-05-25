int ft_add(int a, int b)
{
	return a + b;
}

int ft_sub(int a, int b)
{
	return a - b;
}

int ft_mul(int a, int b)
{
	return a * b;
}

int ft_div(int a, int b)
{
	return a / b;
}

int ft_mod(int a, int b)
{
	return a % b;
}

int operator_index(char op)
{
	char operators[5] = { '+', '-', '*', '/', '%' };
	int i = 0;
	while (operators[i])
	{
		if (operators[i] == op)
			return i;
		i++;
	}
	return -1;
}

int perform_op(int op_index, int num1, int num2)
{
	int (*operations[5])(int, int) = { &ft_add, &ft_sub, &ft_mul, &ft_div, &ft_mod };
	return (operations[op_index](num1, num2));
}
