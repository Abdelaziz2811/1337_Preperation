#include "ft_list.h"

void ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *new_node = ft_create_elem(data);

	if (!new_node)
		return;

	if (*begin_list == NULL)
	{
		*begin_list = new_node;
	}
	else
	{
		t_list *current = *begin_list;
		while (current->next)
		{
			current = current->next;
		}
		current->next = new_node;
	}
}
