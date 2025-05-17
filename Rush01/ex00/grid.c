#include "ft_rush.h"

int is_row_unique(int grid[4])
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		j = i + 1;
		while (j < 4)
		{
			if (grid[i] == grid[j])
				return 0;
			j++;
		}
	}
	return 1;
}

int is_col_unique(int grid[4][4], int col)
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		j = i + 1;
		while (j < 4)
		{
			if (grid[i][col] == grid[j][col])
				return 0;
			j++;
		}
	}
	return 1;
}

int count_visibile_top(int grid[4][4], int col)
{
	int i = 0;
	int max = grid[i][col];
	int visibility = 1;
	while (++i < 4)
	{
		if (max < grid[i][col])
		{
			max = grid[i][col];
			visibility++;
		}
	}
	return visibility;
}

int count_visibile_bottom(int grid[4][4], int col)
{
	int i = 3;
	int max = grid[i][col];
	int visibility = 1;
	while (--i >= 0)
	{
		if (max < grid[i][col])
		{
			max = grid[i][col];
			visibility++;
		}
	}
	return visibility;
}

int count_visibile_left(int grid[4])
{
	int i = 0;
	int max = grid[i];
	int visibility = 1;
	while (++i < 4)
	{
		if (max < grid[i])
		{
			max = grid[i];
			visibility++;
		}
	}
	return visibility;
}

int count_visibile_right(int grid[4])
{
	int i = 3;
	int max = grid[i];
	int visibility = 1;
	while (--i >= 0)
	{
		if (max < grid[i])
		{
			max = grid[i];
			visibility++;
		}
	}
	return visibility;
}

int validate_full_grid(t_constraints c, int grid[4][4])
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (!is_row_unique(grid[i]) || !is_col_unique(grid, i))
			return 0;
	
		if (c.col_up[i] != count_visibile_top(grid, i))
			return 0;

		if (c.col_down[i] != count_visibile_bottom(grid, i))
			return 0;
	
		if (c.row_left[i] != count_visibile_left(grid[i]))
			return 0;

		if (c.row_right[i] != count_visibile_right(grid[i]))
			return 0;
	}
	return 1;
}

int can_place(int grid[4][4], int row, int col, int value)
{
	int i = 0;
	while (i < 4)
	{
		if (value == grid[row][i] || value == grid[i][col])
			return 0;
		i++;
	}
	return 1;
}
