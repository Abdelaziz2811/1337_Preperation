#include "ft_list.h"

void ft_list_reverse(t_list **begin_list)
{
	if(*begin_list == NULL)
		return;

	t_list *current = NULL;
	t_list *next_node;

	while (*begin_list)
	{
		next_node = (*begin_list)->next;
		
		(*begin_list)->next = current;
		current = *begin_list;

		*begin_list = next_node;
	}

	*begin_list = current;
}
