#include <unistd.h>

void print_queens(int *queens)
{
	int i;
	char c;
	for (i = 0; i < 10; i++)
	{
		c = queens[i] + '0';
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}

int abs(int nb)
{
	if (nb < 0) 
		return -nb;
	else 
		return nb;
}

int is_safe(int *queens, int row, int col)
{
	int i;
	for (i = 0; i < row; i++)
	{
		if (queens[i] == col) return 0;

		if (abs(row - i) == abs(col - queens[i])) return 0;
	}
	return 1;
}

void solve(int *queens, int row, int *solution_count)
{
	if (row == 10)
	{
		print_queens(queens);
		(*solution_count)++;
		return;
	}

	int col;
	for (col = 0; col < 10; col++)
	{
		if (is_safe(queens, row, col))
		{
			queens[row] = col;
			solve(queens, row + 1, solution_count);
		}
	}
}

int ft_ten_queens_puzzle(void)
{
	int queens[10] = { 0 };
	int solution_count = 0;

	solve(queens, 0, &solution_count);

	return solution_count;
}
