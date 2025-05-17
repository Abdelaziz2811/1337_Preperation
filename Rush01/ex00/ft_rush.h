#ifndef FT_RUSH_H
#define FT_RUSH_H

typedef struct s_constraints
{
	int col_up[4];
	int col_down[4];
	int row_left[4];
	int row_right[4];
} t_constraints;

char **ft_split(char *str, char *charset);
int ft_atoi(char *str);
t_constraints *get_constraints(char *str, t_constraints *constraints);
int *find_solution(t_constraints *constraints, int *solution, int row, int col);
int validate_full_grid(t_constraints c, int grid[4][4]);
int can_place(int grid[4][4], int row, int col, int value);

#endif
