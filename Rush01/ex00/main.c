#include "ft_rush.h"
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return 1;
	}
	else
	{
		t_constraints *constraints = malloc(sizeof(t_constraints));
		constraints =  get_constraints(argv[1], constraints);

		if (constraints != NULL)
		{	
			int *solution = malloc(sizeof(int) * 16);
			solution = find_solution(constraints, solution, 0, 0);

			if (solution != NULL)
			{
				int i;
				char c;
				for (i = 0; i < 16; i++)
				{
					c = solution[i] + '0';

					write(1, &c, 1);
					
					if ((i + 1) % 4 == 0)
						write(1, "\n", 1);
					else
						write(1, " ", 1);
				}
			}
			free(solution);
		}
		free(constraints);
	}
	return 0;
}
