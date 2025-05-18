#include "ft_list.h"

int     ft_list_size(t_list *begin_list)
{
	t_list *current = begin_list;
	int list_size = 0;
	while (current)
	{
		current = current->next;
		list_size++;
	}
	return list_size;
}
