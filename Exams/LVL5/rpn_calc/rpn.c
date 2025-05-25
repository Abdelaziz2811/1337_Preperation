#include "utils.h"

int valid_rpn(char *rpn)
{
	int i = 0;
	int operand_count = 0, operator_count = 0;
	char c;

	while (rpn[i])
	{
		c = rpn[i];
		if (is_digit(c))
			operand_count++;

		while (is_digit(rpn[i]))
			i++;

		if (is_operator(c))
			operator_count++;
		i++;
	}

	return operator_count == (operand_count - 1);
}
