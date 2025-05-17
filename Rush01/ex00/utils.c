#include <stdlib.h>

// -- string --
int is_separator(char c, char *charset)
{
	int i = 0;
	while (charset[i])
	{
		if (c == charset[i]) return 1;
		i++;
	}
	return 0;
}

int word_count(char *str, char *charset)
{
	int i = 0;
	int count = 0;
	while (str[i])
	{
		if (!is_separator(str[i], charset))
		{
			count++;
			while (str[i] && !is_separator(str[i], charset))
				i++;
		}
		i++;
	}
	return count;
}

int word_len(char *start, char *charset)
{
	int len = 0;
	while (start[len] && !is_separator(start[len], charset))
		len++;
	return len;
}

char *copy_word(char *start, int len)
{
	char *word = malloc(sizeof(char) * (len + 1));
	if (word != NULL)
	{
		int i = 0;
		while (i < len)
		{
			word[i] = start[i];
			i++;
		}
		word[i] = '\0';
	}
	return word;
}

// ==> split :

char **ft_split(char *str, char *charset)
{
	int count = word_count(str, charset);
	char **strs_arr = malloc(sizeof(char *) * (count + 1));

	if (strs_arr != NULL)
	{
		int i = 0,j = 0;
		int len;
		while (str[i])
		{
			if (!is_separator(str[i], charset))
			{
				len = word_len(&str[i], charset);
				strs_arr[j++] =  copy_word(&str[i], len);
				i += len;
			}
			else
				i++;
		}
		strs_arr[j] = 0;
	}

	return strs_arr;
}
// -- string --

// -- ints --

// ==> ft_atoi

int ft_atoi(char *str)
{
	int i = 0, sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
 
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;

		i++;
	}
	
	int result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}

	return result * sign;
}

// -- ints --
