#define TOP_LEFT_CORNER 'o'
#define TOP_RIGHT_CORNER 'o'

#define BUTTOM_LEFT_CORNER 'o'
#define BUTTOM_RIGHT_CORNER 'o'

#define HORIZONTAL_EDGE '-'
#define VERTICAL_EDGE '|'

#define MIDDLE ' '

int g_col;
int g_row;

void	ft_putchar(char c);

int is_top_left_corner(int current_col, int current_row)
{
	if (current_col == 1 && current_row == 1)
		return 1;
	else 
		return 0;
}

int is_top_right_corner(int current_col, int current_row)
{
	if (current_col == g_col && current_row == 1)
		return 1;
	else 
		return 0;
}

int is_buttom_left_corner(int current_col, int current_row)
{
	if (current_col == 1 && current_row == g_row)
		return 1;
	else 
		return 0;
}

int is_buttom_right_corner(int current_col, int current_row)
{
	if (current_col == g_col && current_row == g_row)
		return 1;
	else 
		return 0;
}
int is_horizontal_edge(int current_col, int current_row)
{
	if ((current_col != 1 && current_col != g_col) && (current_row == 1 || current_row == g_row))
		return 1;
	else
		return 0;
}

int is_vertical_edge(int current_col, int current_row)
{
	if ((current_col == 1 || current_col == g_col) && (current_row != 1 && current_row != g_row))
		return 1;
	else 
		return 0;
}

int is_middle(int current_col, int current_row)
{
	if ((current_col != 1 && current_col != g_col) && (current_row != 1 && current_row != g_row))
		return 1;
	else 
		return 0;
}

void rush(int x, int y)
{
	g_col = x;
	g_row = y;

	int i, j;
	for (i = 1; i <= y; i++)
	{
		for (j = 1; j <= x; j++)
		{
			if (is_top_left_corner(j, i))
			{
				ft_putchar(TOP_LEFT_CORNER);
			}
			else if(is_top_right_corner(j, i))
			{
				ft_putchar(TOP_RIGHT_CORNER);
			}
			else if (is_buttom_left_corner(j, i))
			{
				ft_putchar(BUTTOM_LEFT_CORNER);	
			}
			else if (is_buttom_right_corner(j, i))
			{
				ft_putchar(BUTTOM_RIGHT_CORNER);	
			}
			else if(is_vertical_edge(j, i))
			{
				ft_putchar(VERTICAL_EDGE);
			}
			else if (is_horizontal_edge(j, i))
			{
				ft_putchar(HORIZONTAL_EDGE);
			}
			else if (is_middle(j, i))
			{
				ft_putchar(MIDDLE);	
			}
		}
		ft_putchar('\n');
	}
}
