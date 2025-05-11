#include "ft_list.h"

t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int i = 0;
	t_list *current = begin_list;
	while (i < nbr && current)
	{
		current = current->next;
		i++;
	}
	return current;
}
