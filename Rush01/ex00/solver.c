#include "ft_rush.h"
#include <stdio.h>

int solve(int grid[4][4], t_constraints *constraints, int row, int col)
{
	if (row == 4)
		return validate_full_grid(*constraints, grid);

	int num;
	for (num = 1; num <= 4; num++)
	{
		if (can_place(grid, row, col, num))
		{
			grid[row][col] = num;

			int next_row = (col == 3) ? row + 1 : row;
			int next_col = (col + 1) % 4;

			if (solve(grid, constraints, next_row, next_col))
				return 1;

			grid[row][col] = 0;
		}
	}
	return 0;
}

int *find_solution(t_constraints *constraints, int *solution, int row, int col)
{
	int grid[4][4] = { 0 };
	if (solve(grid, constraints, row, col))
	{
		int i, j;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				solution[(4 * i) + j] = grid[i][j];
			}
		}
	}
	return solution;
}
