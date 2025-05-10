#include "ft_list.h"

void ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new_node = ft_create_elem(data);

	if (new_node != NULL)
	{
		new_node->next = *begin_list;
		*begin_list = new_node;
	}
}
