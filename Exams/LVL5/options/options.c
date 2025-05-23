#include <unistd.h>

unsigned int options_to_int(char **options)
{
	int i = 1, j = 1;
	unsigned int value = 0;
	while (options[i])
	{
		j = 1;
		while (options[i][j])
		{
			value |= (1 << (options[i][j] - 'a'));
			j++;
		}
		i++;
	}
	return value;
}

int valid_options(char **options)
{
	int i = 1, j = 0;
	while (options[i])
	{
		j = 0;
		while (options[i][j])
		{
			if (j == 0 && options[i][j] != '-')
				return 0;
			
			if (j != 0 && (options[i][j] < 'a' || options[i][j] > 'z'))
				return 0;	
			j++;
		}
		i++;
	}
	return 1;
}

int h_flag(char **options)
{
	int i = 1, j = 1;
	char c;
	while (options[i])
	{
		c = options[i][0];
		while (options[i][j])
		{
			if (c == '-' && options[i][j] == 'h')
				return 1;
			else
				break;
						
			j++;
		}
		i++;
	}
	return 0;
}

void presentation_display(unsigned int value)
{
	int i = 31;
	while (i >= 0)
	{
		char bit = (value & (1 << i)) ? '1' : '0';
		write(1, &bit, 1);
		
		if (i % 8 == 0 && i != 0)
			write(1, " ", 1);
		i--;
	}
}
