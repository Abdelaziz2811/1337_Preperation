#include <stdio.h>
#include <stdlib.h>
#include "rpn.h"
#include "calc.h"
#include "utils.h"

int main(int argc, char **argv)
{
	if (argc == 2 && valid_rpn(argv[1]))
	{
		int i = 0, buff_i = -1;
		char c;
		int buffer[20];
		int nbr = 0;
		int result = 0;
		int operator_i = 0;

		while (argv[1][i])
		{
			c = argv[1][i];
			if (is_digit(c))
			{
				nbr = 0;
				while (is_digit(argv[1][i]))
				{
					nbr = (nbr * 10) + (argv[1][i] - '0');
					i++;
				}
				buffer[++buff_i] = nbr;
			}
			else
				i++;

			if (is_operator(c))
			{
				operator_i = operator_index(c);
				result = perform_op(operator_i, buffer[buff_i - 1], buffer[buff_i]);
				buffer[buff_i - 1] = result;
				buffer[buff_i] = 0;
				buff_i--;
			}
		}
		printf("%d", result);
	}
	else
		printf("Error\n");

	return 0;
}
