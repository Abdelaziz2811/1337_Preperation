#include <stdlib.h>

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

int word_len(char *start, char *charset)
{
	int len = 0;
	while (start[len] && !is_separator(start[len], charset))
		len++;

	return len;
}

char *copy_word(char *start, int len)
{
	char *word = malloc(sizeof(char) * len + 1);
	
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

char **ft_split(char *str, char *charset)
{
	int count = word_count(str, charset);

	char **chars_arr = malloc(sizeof(char *) * (count + 1));

	int j = 0;
	if (chars_arr != NULL)
	{
		int i = 0;
		int len;
		while (str[i])
		{
			if (!is_separator(str[i], charset))
			{
				len = word_len(&str[i], charset);
				
				chars_arr[j++] = copy_word(&str[i], len);

				i += len;				
			}
			i++;		
		}
	}
	chars_arr[j] = 0;
	
	return chars_arr;
}
