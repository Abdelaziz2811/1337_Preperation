#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list *temp;

	if (*begin_list && (*cmp)((*begin_list)->data, data_ref) == 0)
	{
		temp = *begin_list;
		*begin_list = (*begin_list)->next;
		(*free_fct)(temp->data);
		free(temp);
	}

	t_list *list_ptr = *begin_list;
	
	while (list_ptr && list_ptr->next)
	{
		if ((*cmp)(list_ptr->next->data, data_ref) == 0)
		{
			temp = list_ptr->next;
			list_ptr->next = list_ptr->next->next;

			(*free_fct)(temp->data);
			free(temp);
		}
		else
			list_ptr = list_ptr->nex;
	}
}
