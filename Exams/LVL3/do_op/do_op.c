#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "do_op.h"

int is_op_valid(char *op, char *ops)
{
	int len = 0;
	while (op[len])
		len++;

	if (len != 1) return -1;

	int i = 0;
	while (i < 5)
	{
		if (op[0] == ops[i])
			return i;
		i++;
	}

	return -1;
}

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		char ops[5] = { '+', '-', '*', '/', '%' };
		int op_index;
		
		if ((op_index = is_op_valid(argv[2], ops)) == -1)
			return 0;
		
		int (*operations[5])(int, int) = { ft_sum, ft_sub, ft_mul, ft_div, ft_mod };
		
		int n1 = atoi(argv[1]);
		int n2 = atoi(argv[3]);

		if ((ops[op_index] == '/' || ops[op_index] == '%') && n2 == 0)
		{
			printf("Division by zero is undefined");
		}
		else
		{
			int result = operations[op_index](n1, n2);
			printf("%d", result);
		}
	}

	printf("\n");
	return 0;
}
