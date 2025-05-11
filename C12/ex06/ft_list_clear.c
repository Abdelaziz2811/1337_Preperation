#include <stdlib.h>
#include "ft_list.h"

void ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list *node_to_delete = NULL;
	while (begin_list)
	{
		node_to_delete = begin_list;
		begin_list = begin_list->next;
		free_fct(node_to_delete->data);
		free(node_to_delete);
	}
}
